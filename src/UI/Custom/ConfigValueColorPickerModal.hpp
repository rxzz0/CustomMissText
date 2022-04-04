#pragma once

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
#include "config/config.hpp"
#include "UnityEngine/Color.hpp"
#include "questui/shared/CustomTypes/Components/ModalColorPicker.hpp"
#include "GlobalNamespace/ColorChangeUIEventType.hpp"

namespace CustomMissText::UI {
    
        //I had to, sorry to whoever has to look at this
    inline ::QuestUI::ModalColorPicker* AddConfigValueColorPickerModal(UnityEngine::Transform* parent, ConfigUtils::ConfigValue<::UnityEngine::Color>& configValue) {
    auto object = ::QuestUI::BeatSaberUI::CreateColorPickerModal(parent, configValue.GetName(), configValue.GetValue(), nullptr, nullptr, 
    [&configValue](::UnityEngine::Color value) {
            configValue.SetValue(value);
        }
    );
    if(!configValue.GetHoverHint().empty())
        ::QuestUI::BeatSaberUI::AddHoverHint(object, configValue.GetHoverHint());
    return object;
}
}