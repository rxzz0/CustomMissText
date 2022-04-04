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

#define config getModConfig()
#define Enabled config.Enabled.GetValue()

static float Sign(float f)
{
  return (f >= 0.0f) ? 1.0f : -1.0f;
}

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

    if (Enabled && _spawner != nullptr) 
    {
          _spawner->dyn__targetZPos() = 12.0f;
          _spawner->dyn__xSpread() = 1.8;

          _spawner->dyn__fontSize() = config.FontSize.GetValue();
          _spawner->dyn__color() = config.MissTextColor.GetValue();
          _spawner->dyn__shake() = config.Shake.GetValue();   

          GlobalNamespace::NoteData* noteData = noteController->get_noteData();
          if (noteData->get_colorType() == GlobalNamespace::ColorType::ColorA || noteData->get_colorType() == GlobalNamespace::ColorType::ColorB)
          {
              UnityEngine::Vector3 pos = noteController->get_noteTransform()->get_position();
              UnityEngine::Quaternion worldRotation = noteController->get_worldRotation();
              pos = noteController->get_inverseWorldRotation() * pos;
              pos = worldRotation * pos;
              pos.y = noteController->get_transform()->get_position().y;
              float xPos = noteController->get_transform()->get_position().x;
              pos = Sign(xPos * _spawner->dyn__xSpread());
              _spawner->SpawnText(pos, noteController->get_worldRotation(), noteController->get_inverseWorldRotation(), config.MissText.GetValue());
          }
    }
};  
void InstallHooks() { 
  INSTALL_HOOK(getLogger(), MissedNoteEffectSpawner_HandleNoteWasMissed); 
  };