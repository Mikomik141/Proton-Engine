//
// Created by amale on 21/08/24.
//
#include <AudioEngine.h>
#include <iostream>

// Initialisation des variables statiques
FMOD::Studio::System* AudioEngine::studioSystem = nullptr;
FMOD::System* AudioEngine::coreSystem = nullptr;

std::unordered_map<std::string, FMOD::Studio::Bank*> AudioEngine::banks;
std::unordered_map<std::string, FMOD::Studio::EventInstance*> AudioEngine::events;

void AudioEngine::Init() {
    FMOD::Studio::System::create(&studioSystem);  // Créer le système FMOD Studio
    studioSystem->getCoreSystem(&coreSystem);     // Obtenir le système FMOD de base

    // Initialiser le système FMOD avec 512 canaux, mode normal
    studioSystem->initialize(512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);
}

void AudioEngine::Update() {
    studioSystem->update();  // Mettre à jour le système FMOD chaque frame
}

void AudioEngine::Shutdown() {
    // Libérer toutes les banques et les instances d'événements
    for (auto& event : events) {
        event.second->stop(FMOD_STUDIO_STOP_IMMEDIATE);
        event.second->release();
    }
    for (auto& bank : banks) {
        bank.second->unload();
    }

    studioSystem->release();  // Fermer et libérer FMOD
}

void AudioEngine::LoadBank(const std::string& bankName) {
    FMOD::Studio::Bank* bank;
    std::string path = bankName + ".bank";  // Exemple de chemin, à adapter selon l'organisation des fichiers
    studioSystem->loadBankFile(path.c_str(), FMOD_STUDIO_LOAD_BANK_NORMAL, &bank);
    banks[bankName] = bank;
}

void AudioEngine::LoadEvent(const std::string& eventName) {
    FMOD::Studio::EventDescription* eventDescription = nullptr;
    studioSystem->getEvent(eventName.c_str(), &eventDescription);

    FMOD::Studio::EventInstance* eventInstance = nullptr;
    eventDescription->createInstance(&eventInstance);
    events[eventName] = eventInstance;
}

void AudioEngine::PlayEvent(const std::string& eventName) {
    auto it = events.find(eventName);
    if (it != events.end()) {
        it->second->start();
    }
}

void AudioEngine::StopEvent(const std::string& eventName) {
    auto it = events.find(eventName);
    if (it != events.end()) {
        it->second->stop(FMOD_STUDIO_STOP_IMMEDIATE);
    }
}

void AudioEngine::Set3DListenerAttributes(const FMOD_VECTOR& position, const FMOD_VECTOR& velocity, const FMOD_VECTOR& forward, const FMOD_VECTOR& up) {
    FMOD_3D_ATTRIBUTES attributes = {};
    attributes.position = position;
    attributes.velocity = velocity;
    attributes.forward = forward;
    attributes.up = up;

    studioSystem->setListenerAttributes(0, &attributes);  // Appliquer les attributs au premier auditeur (index 0)
}

