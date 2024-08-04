#include <gulpin/PluginManager.h>

#include <iostream>

int main() {
    gulpin::PluginManager pluginManager;

    pluginManager.loadPlugin("plugins/libhelloworldplugin.so");

    std::vector<std::string> pluginNames = pluginManager.getPluginNames();
    
    for (const std::string& name : pluginNames) {
        std::cout << "Plugin name: " << name << std::endl;
        auto pluginOpt = pluginManager.getPlugin(name);

        if(pluginOpt.has_value())
        {
            auto& plugin = pluginOpt.value().get();
            plugin.initialize();
            plugin.execute();
            plugin.shutdown();
        }
        else
        {
            std::cerr<< "Plugin unavailable" << std::endl;
        }
    }

    // Unload all plugins
    pluginManager.unloadPlugins();

    return 0;
}