#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
#include "questui_components/shared/components/ModifierButton.hpp"

#include "UI/ViewControllers/TextViewController.hpp" 

#include "config/config.hpp"

#include "UI/Custom/ConfigValueModifiersButton.hpp"

#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TextMeshPro.hpp"
#include "TMPro/TextAlignmentOptions.hpp"

#include "UnityEngine/UI/LayoutGroup.hpp"

using namespace CustomMissText::UI;

DEFINE_TYPE(CustomMissText::UI::ViewControllers, TextSettingsViewController);

void CustomMissText::UI::ViewControllers::TextSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   if (firstActivation) 
    {
            UnityEngine::UI::VerticalLayoutGroup* Vertical = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
            UnityEngine::UI::HorizontalLayoutGroup* Horizontal = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(Vertical->get_transform());
            UnityEngine::GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

            auto EnabledButton = AddConfigValueModifierButton(container->get_transform(), getModConfig().Enabled);
            EnabledButton->get_gameObject()->GetComponentInChildren<TMPro::TextMeshProUGUI*>()->set_alignment(TMPro::TextAlignmentOptions::Center);
            EnabledButton->get_gameObject()->GetComponentInChildren<TMPro::TextMeshProUGUI*>()->set_fontSize(5.0);


            AddConfigValueStringSetting(container->get_transform(), getModConfig().MissText);
            QuestUI::BeatSaberUI::CreateUIButton(Horizontal->get_transform(), "made by rxzz0#6982");
    }
}
