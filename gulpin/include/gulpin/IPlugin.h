#pragma once

#include <string>

class IPlugin {
public:
    struct Descriptor
    {
        std::string name;
        std::string version;
    };

    virtual ~IPlugin() = default;

    virtual void initialize() = 0;
    
    virtual void execute() = 0;
    
    virtual void shutdown() = 0;
    
    virtual Descriptor getDescriptor() const = 0;
};

extern "C" IPlugin* createPlugin();

extern "C" void destroyPlugin(IPlugin* plugin);
