#include "Sound.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>

bool Sound::init() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to initialize SDL_Mixer: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

void Sound::playSound(const char* filePath) {
    Mix_Chunk* sound = Mix_LoadWAV(filePath);
    if (sound == nullptr) {
        std::cerr << "Failed to load sound effect: " << Mix_GetError() << std::endl;
        return;
    }
    Mix_PlayChannel(-1, sound, 0);
}

void Sound::cleanup() {
    Mix_CloseAudio();
}
