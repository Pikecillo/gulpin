#include <gulpin/PluginManager.h>

#include <functional>
#include <iostream>
#include <optional>

#include <dlfcn.h>

namespace gulpin {

PluginManager::~PluginManager()
{
    unloadPlugins();
}

bool PluginManager::loadPlugin(const std::string& objectPath)
{
    void* handle = dlopen(objectPath.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load plugin: " << objectPath << std::endl;

        return false;
    }

    using CreatePluginFunc = IPlugin* (*)();

    CreatePluginFunc createPlugin = reinterpret_cast<CreatePluginFunc>(dlsym(handle, "createPlugin"));
    if (!createPlugin) {
        std::cerr << "Failed to load CreatePlugin function" << std::endl;
        dlclose(handle);

        return false;
    }

    auto* const plugin = createPlugin();

    if (!plugin) {
        std::cerr << "Failed to create plugin" << std::endl;
        dlclose(handle);

        return false;
    }

    std::string name = plugin->getDescriptor().name;
    m_plugins[name] = plugin;
    m_handles[name] = handle;

    return true;
}

void PluginManager::unloadPlugins()
{
    for (auto& entry : m_plugins) {
        const std::string& name = entry.first;
        IPlugin* plugin = entry.second;
        void* handle = m_handles[name];

        using DestroyPluginFunc = void (*)(IPlugin*);

        DestroyPluginFunc destroyPlugin = reinterpret_cast<DestroyPluginFunc>(dlsym(handle, "destroyPlugin"));
        if (destroyPlugin) {
            destroyPlugin(plugin);
        }
        else {
            std::cerr << "Failed to destroy plugin" << std::endl;
        }

        dlclose(handle);
    }

    m_plugins.clear();
    m_handles.clear();
}

std::optional<std::reference_wrapper<IPlugin>> PluginManager::getPlugin(const std::string& name) const
{
    auto it = m_plugins.find(name);
    if (it != m_plugins.end()) {
        return std::make_optional<std::reference_wrapper<IPlugin>>(*it->second);
    }
    return {};
}

std::vector<std::string> PluginManager::getPluginNames() const
{
    std::vector<std::string> names;
    for (const auto& entry : m_plugins) {
        names.push_back(entry.first);
    }
    return names;
}
}