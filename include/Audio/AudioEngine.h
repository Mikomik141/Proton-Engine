#ifndef AUDIO_ENGINE_HPP
#define AUDIO_ENGINE_HPP

#include <fmod.hpp>
#include <fmod_studio.hpp>
#include <fmod_errors.h>
#include <string>
#include <unordered_map>

class AudioEngine {
public:
    static void Init();
    static void Update();
    static void Shutdown();

    static void LoadBank(const std::string& bankName);
    static void LoadEvent(const std::string& eventName);
    static void PlayEvent(const std::string& eventName);
    static void StopEvent(const std::string& eventName);

    static void Set3DListenerAttributes(const FMOD_VECTOR& position, const FMOD_VECTOR& velocity, const FMOD_VECTOR& forward, const FMOD_VECTOR& up);

private:
    static FMOD::Studio::System* studioSystem;
    static FMOD::System* coreSystem;

    static std::unordered_map<std::string, FMOD::Studio::Bank*> banks;
    static std::unordered_map<std::string, FMOD::Studio::EventInstance*> events;
};

#endif // AUDIO_ENGINE_HPP
