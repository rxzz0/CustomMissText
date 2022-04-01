#pragma once
#include "main.hpp"
#include "config-utils/shared/config-utils.hpp"
#include "UnityEngine/Color.hpp"
#include "UnityEngine/Vector3.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(MissText, std::string, "MISS", "MISS");
    CONFIG_VALUE(MissTextColor, UnityEngine::Color, "Miss-Text color", UnityEngine::Color(1.0f, 1.0f, 1.0f, 1.0f), "Color of the MISS text");
    CONFIG_VALUE(FontSize, float, "Font-Size", 5.0f, "Font size for 'MISS' ");
    CONFIG_VALUE(Enabled, bool, "Enabled", true, "Disables the mod");
    CONFIG_VALUE(Shake, bool, "Text shake", false, "Makes the text shake (funny)");

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(MissText);
        CONFIG_INIT_VALUE(MissTextColor);
        CONFIG_INIT_VALUE(FontSize);
        CONFIG_INIT_VALUE(Enabled);
        CONFIG_INIT_VALUE(Shake);
    )
)