#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "UI/ViewControllers/ExtrasViewController.hpp" 

#include "config/config.hpp"

#include "UI/Custom/ConfigValueColorPickerModal.hpp"
#include "UI/Custom/ConfigValueModifiersButton.hpp"

#include "UnityEngine/TextAnchor.hpp"

using namespace CustomMissText::UI;

DEFINE_TYPE(CustomMissText::UI::ViewControllers, ExtraSettingsViewController);

void CustomMissText::UI::ViewControllers::ExtraSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   if (firstActivation) 
    {
        UnityEngine::UI::VerticalLayoutGroup* VerticalLayout = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        UnityEngine::UI::HorizontalLayoutGroup* HorizontalLayout = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(VerticalLayout->get_transform());

        AddConfigValueIncrementFloat(VerticalLayout->get_transform(), getModConfig().FontSize, 1, 0.1, 0.1, 10);
        auto Shake = AddConfigValueModifierButton(HorizontalLayout->get_transform(), getModConfig().Shake);
        Shake->get_gameObject()->GetComponentInChildren<TMPro::TextMeshProUGUI*>()->set_alignment(TMPro::TextAlignmentOptions::MidlineLeft);
        Shake->get_gameObject()->GetComponentInChildren<TMPro::TextMeshProUGUI*>()->set_fontSize(5.0);
        

        AddConfigValueColorPickerModal(VerticalLayout->get_transform(), getModConfig().MissTextColor)->Show();
    }      
}
