#include "Sound.h"
#include <SDL2/SDL_mixer.h>

bool Sound::init() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) return false;
    return true;
}

void Sound::playSound(const char* filePath) {
    Mix_Chunk* sound = Mix_LoadWAV(filePath);
    Mix_PlayChannel(-1, sound, 0);
}

void Sound::cleanup() {
    Mix_CloseAudio();
}
