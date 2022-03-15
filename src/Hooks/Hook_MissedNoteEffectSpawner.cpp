#include "main.hpp"
#include "Hooks.hpp"
#include "config/config.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/typedefs-string.hpp"

#include "GlobalNamespace/FlyingTextSpawner.hpp"
#include "GlobalNamespace/FlyingTextEffect.hpp"
#include "GlobalNamespace/FlyingTextEffect_Pool.hpp"
#include "GlobalNamespace/MissedNoteEffectSpawner.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/ColorType.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"

#include "UnityEngine/Transform.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Quaternion.hpp"
#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Component.hpp"

#include "Zenject/MonoInstallerBase.hpp"
#include "Zenject/DiContainer.hpp"

GlobalNamespace::FlyingTextSpawner* _spawner;

MAKE_HOOK_MATCH(MissedNoteEffectSpawner_HandleNoteWasMissed, 
                &GlobalNamespace::MissedNoteEffectSpawner::HandleNoteWasMissed, 
                void, GlobalNamespace::MissedNoteEffectSpawner* self, 
                GlobalNamespace::NoteController* noteController)
{
     _spawner = UnityEngine::GameObject::New_ctor("CustomMissTextSpawner")->AddComponent<GlobalNamespace::FlyingTextSpawner*>();

        auto installers = UnityEngine::Object::FindObjectsOfType<Zenject::MonoInstallerBase*>();
          for (auto& installer : installers) 
          {
            auto container = installer->get_Container();
              if (container != nullptr && _spawner != nullptr && container->HasBinding<GlobalNamespace::FlyingTextEffect::Pool*>()) 
              {
                container->Inject(_spawner);
                break;
              }
          }
      bool Enabled = getModConfig().Enabled.GetValue();
      UnityEngine::Color TextColor = getModConfig().MissTextColor.GetValue();
      float TextFontSize = getModConfig().FontSize.GetValue();
      std::string Text = getModConfig().MissText.GetValue();
      GlobalNamespace::NoteData* noteData = noteController->get_noteData();
      if (noteData->get_colorType()._get_ColorA() != GlobalNamespace::ColorType::None && noteData->get_colorType()._get_ColorB() != GlobalNamespace::ColorType::None) 
      {
      
        if (noteController->get_hidden()) return;
        if (noteData->get_time() + 0.5f < GlobalNamespace::AudioTimeSyncController().get_songTime()) return;
        if (noteData->get_colorType() == GlobalNamespace::ColorType::None) return;

        UnityEngine::Vector3 vector = noteController->get_noteTransform()->get_position();
        UnityEngine::Quaternion worldRotation = noteController->get_worldRotation();
        UnityEngine::Quaternion inverseWorldRotation = noteController->get_inverseWorldRotation();
        vector = worldRotation * vector;
        vector = inverseWorldRotation * vector;
        vector.z = self->dyn__spawnPosZ();

_spawner->dyn__fontSize() = TextFontSize;
_spawner->dyn__color() = TextColor;

        if (Enabled == true) {
	  	  _spawner->SpawnText(vector, worldRotation, inverseWorldRotation, Text);
        }
    }
};  


void InstallHooks() { 
  INSTALL_HOOK(getLogger(), MissedNoteEffectSpawner_HandleNoteWasMissed); 
  };
  
