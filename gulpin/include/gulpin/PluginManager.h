#pragma once

#include <gulpin/IPlugin.h>

#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace gulpin {
class PluginManager {
public:
    using Handle = void*;

    ~PluginManager();

    bool loadPlugin(const std::string& path);
    
    void unloadPlugins();
    
    std::optional<std::reference_wrapper<IPlugin>> getPlugin(const std::string& name) const;
    
    std::vector<std::string> getPluginNames() const;

private:
    std::map<std::string, IPlugin*> m_plugins;
    std::map<std::string, Handle> m_handles;
};
}