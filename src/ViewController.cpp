#include "questui/shared/QuestUI.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "ViewController.hpp"
#include "HMUI/Touchable.hpp"
#include "HMUI/InputFieldView.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "UnityEngine/UI/Button.hpp"
#include "config/config.hpp"

using namespace HMUI;
using namespace QuestUI::BeatSaberUI;
using namespace UnityEngine;

DEFINE_TYPE(CustomMissText, ViewController);

void CustomMissText::ViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   
    if (firstActivation) {
            layout = CreateVerticalLayoutGroup(get_transform());
            horizontal = CreateHorizontalLayoutGroup(layout->get_transform());
            get_gameObject()->AddComponent<Touchable*>();
            GameObject* container = CreateScrollableSettingsContainer(get_transform());
            button = CreateUIButton(horizontal->get_transform(), "made by rxzz0#6982");  


            AddConfigValueToggle(container->get_transform(), getModConfig().Enabled);
            AddConfigValueIncrementFloat(container->get_transform(), getModConfig().FontSize, 1, 0.1f, 0.1f, 10.0f);
            AddConfigValueStringSetting(container->get_transform(), getModConfig().MissText);
            AddConfigValueColorPicker(container->get_transform(), getModConfig().MissTextColor);   
    } 
}
            