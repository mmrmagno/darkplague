#include "Input.h"
#include <SDL2/SDL.h>

void Input::handleInput(bool& running, Player& player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W]) player.position.z -= 0.1f;
    if (state[SDL_SCANCODE_S]) player.position.z += 0.1f;
    if (state[SDL_SCANCODE_A]) player.position.x -= 0.1f;
    if (state[SDL_SCANCODE_D]) player.position.x += 0.1f;
}
