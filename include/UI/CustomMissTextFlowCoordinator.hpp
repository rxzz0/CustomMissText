#pragma once

#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"

#include "UI/ViewControllers/TextViewController.hpp"
#include "UI/ViewControllers/ExtrasViewController.hpp"
#include "UI/ViewControllers/ColorSettingsViewController.hpp"

#include "custom-types/shared/macros.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

DECLARE_CLASS_CODEGEN(CustomMissText::UI::FlowCoordinators, CustomMissTextFlowCoordinator, HMUI::FlowCoordinator,
                      DECLARE_INSTANCE_FIELD(CustomMissText::UI::ViewControllers::TextSettingsViewController*, TextSettingsViewController);
                      DECLARE_INSTANCE_FIELD(CustomMissText::UI::ViewControllers::ExtraSettingsViewController*, ExtraSettingsViewController);
                      DECLARE_INSTANCE_FIELD(CustomMissText::UI::ViewControllers::ColorSettingsViewController*, ColorSettingsViewController);

                      DECLARE_INSTANCE_METHOD(void, Awake);

                      DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::FlowCoordinator::DidActivate>::get(), bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling);
                      DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::FlowCoordinator::BackButtonWasPressed>::get(), HMUI::ViewController* topViewController);
                      )