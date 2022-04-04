#include "main.hpp"

#include "UI/CustomMissTextFlowCoordinator.hpp"
#include "config/config.hpp"

#include "System/Action.hpp"
#include "System/Action_1.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

DEFINE_TYPE(CustomMissText::UI::FlowCoordinators, CustomMissTextFlowCoordinator);

void CustomMissText::UI::FlowCoordinators::CustomMissTextFlowCoordinator::Awake() {
    if (!TextSettingsViewController) {
        TextSettingsViewController = QuestUI::BeatSaberUI::CreateViewController<CustomMissText::UI::ViewControllers::TextSettingsViewController*>();
    }
    if (!ExtraSettingsViewController) {
        ExtraSettingsViewController = QuestUI::BeatSaberUI::CreateViewController<CustomMissText::UI::ViewControllers::ExtraSettingsViewController*>();
    }
}

void CustomMissText::UI::FlowCoordinators::CustomMissTextFlowCoordinator::DidActivate(bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling) {
    if (!firstActivation) return;

    SetTitle("Custom Miss-Text Settings", HMUI::ViewController::AnimationType::In);
    showBackButton = true;
    ProvideInitialViewControllers(TextSettingsViewController, ExtraSettingsViewController, nullptr, nullptr, nullptr);
}

void CustomMissText::UI::FlowCoordinators::CustomMissTextFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    getModConfig().config->Write();
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}