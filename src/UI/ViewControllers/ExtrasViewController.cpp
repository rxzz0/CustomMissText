#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "UI/ViewControllers/ExtrasViewController.hpp" 

#include "config/config.hpp"

#include "UI/Custom/ConfigValueModifiersButton.hpp"
#include "UI/Custom/ConfigValueColorPickerModal.hpp"

#include "UnityEngine/TextAnchor.hpp"

using namespace CustomMissText::UI;

DEFINE_TYPE(CustomMissText::UI::ViewControllers, ExtraSettingsViewController);

void CustomMissText::UI::ViewControllers::ExtraSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   if (!firstActivation) return;
        QuestUI::BeatSaberUI::CreateText(get_transform(), "Extra settings", true, UnityEngine::Vector2(7, 47.5))->GetComponentInChildren<TMPro::TextMeshProUGUI*>()->set_fontSize(9.0);

        UnityEngine::UI::HorizontalLayoutGroup* layout = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(get_transform());

        auto ColorPickerModal = AddConfigValueColorPickerModal(layout->get_transform(), getModConfig().MissTextColor);
        auto ColorButton = QuestUI::BeatSaberUI::CreateUIButton(get_transform(), "Change Miss-Color", UnityEngine::Vector2(0, 10), UnityEngine::Vector2(30, 10), [=] {
        ColorPickerModal->Show();
        });
        

        AddConfigValueModifierButton(get_transform(), getModConfig().Shake, UnityEngine::Vector2(60, -15));
        AddConfigValueIncrementFloat(layout->get_transform(), getModConfig().FontSize, 1, 0.1, 0.1, 10.0);
}
