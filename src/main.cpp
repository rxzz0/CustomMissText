#include "main.hpp"
#include "Hooks.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "UnityEngine/Color.hpp"
#include "config/config.hpp"
#include "UI/ViewControllers/TextViewController.hpp"
#include "UI/ViewControllers/ExtrasViewController.hpp"
#include "UI/CustomMissTextFlowCoordinator.hpp"
#include "questui/shared/QuestUI.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}



// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load(); // Load the config file
    getModConfig().Init(modInfo);
    getConfig().Reload();
    getConfig().Write();
    getLogger().info("Completed setup!");
}

// hello game
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing hooks...");
    InstallHooks();
    QuestUI::Init();
    custom_types::Register::AutoRegister();
    QuestUI::Register::RegisterMainMenuModSettingsFlowCoordinator<CustomMissText::UI::FlowCoordinators::CustomMissTextFlowCoordinator*>(modInfo);
    getLogger().info("Installed all hooks!");
    }
    