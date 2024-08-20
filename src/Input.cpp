#include "Input.h"
#include <SDL2/SDL.h>

void Input::handleInput(bool& running, Player& player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }

    // Handle keyboard input for player movement
}
