#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
#include "UI/ViewControllers/ColorSettingsViewController.hpp" 
#include "config/config.hpp"
#include "UI/Custom/ConfigValueColorPickerModal.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TextMeshPro.hpp"
#include "TMPro/TextAlignmentOptions.hpp"

using namespace CustomMissText::UI;

DEFINE_TYPE(CustomMissText::UI::ViewControllers, ColorSettingsViewController);

void CustomMissText::UI::ViewControllers::ColorSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   if (firstActivation) 
    {
            UnityEngine::UI::VerticalLayoutGroup* Vertical = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
            UnityEngine::UI::HorizontalLayoutGroup* Horizontal = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(Vertical->get_transform());

            auto ColorPicker = AddConfigValueColorPickerModal(Vertical->get_transform(), getModConfig().MissTextColor);

            QuestUI::BeatSaberUI::CreateUIButton(get_transform(), "miss-color", [=] {
                ColorPicker->Show();
            });

    }
}
