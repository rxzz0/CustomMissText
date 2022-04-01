#pragma once

#include "questui/shared/BeatSaberUI.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "config/config.hpp"

namespace CustomMissText::UI {

    //I had to, sorry to whoever has to look at this
    
        inline ::UnityEngine::UI::Toggle* AddConfigValueModifierButton(::UnityEngine::Transform* parent, ConfigUtils::ConfigValue<bool>& configValue)
        {
            auto object = ::QuestUI::BeatSaberUI::CreateModifierButton(parent, configValue.GetName(), configValue.GetValue(), 
        [&configValue](bool value) 
        { 
            configValue.SetValue(value); 
        });

    if(!configValue.GetHoverHint().empty())
        ::QuestUI::BeatSaberUI::AddHoverHint(object->get_gameObject(), configValue.GetHoverHint());
    return object;
        }
}