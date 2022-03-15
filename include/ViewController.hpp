#pragma once
#include "HMUI/ViewController.hpp"
#include "custom-types/shared/macros.hpp"
#include "UnityEngine/GameObject.hpp"

using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace QuestUI;
using namespace GlobalNamespace;



DECLARE_CLASS_CODEGEN(CustomMissText, ViewController, HMUI::ViewController,
DECLARE_INSTANCE_FIELD(VerticalLayoutGroup*, layout);
DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup*, horizontal);
DECLARE_INSTANCE_FIELD(Button*, button);
DECLARE_OVERRIDE_METHOD(void, DidActivate, 
il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::ViewController::DidActivate>::get(), 
bool firstActivation, 
bool addedToHierarchy, 
bool screenSystemEnabling);
)