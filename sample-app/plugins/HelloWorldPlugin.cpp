#include <gulpin/IPlugin.h>

#include <iostream>
#include <memory>

class HelloWorldPlugin : public IPlugin {
public:
    void initialize() override {
        std::cout << "HelloWorldPlugin Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "Hello World!" << std::endl;
    }

    void shutdown() override {
        std::cout << "HelloWorldPlugin Shutting Down" << std::endl;
    }

    Descriptor getDescriptor() const override {
        return Descriptor{"HelloWorldPlugin", "1.0"};
    }
};

IPlugin* createPlugin() {
    return new HelloWorldPlugin();
}

void destroyPlugin(IPlugin* plugin)
{
    delete plugin;
}