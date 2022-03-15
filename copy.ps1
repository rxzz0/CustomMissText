& $PSScriptRoot/build.ps1
if ($?) {
    adb push build/libCustomMissText.so /sdcard/Android/data/com.beatgames.beatsaber/files/mods/libCustomMissText.so
    if ($?) {
        & $PSScriptRoot/restart-game.ps1
        if ($args[0] -eq "--log") {
            & $PSScriptRoot/start-logging.ps1
        }
    }
}
