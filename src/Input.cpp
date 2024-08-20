#include "Input.h"
#include <SDL2/SDL.h>

void Input::update() {
    SDL_PumpEvents();
    state = SDL_GetKeyboardState(NULL);
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

bool Input::isKeyDown(SDL_Scancode key) {
    return state[key];
}

bool Input::isMouseButtonDown(Uint8 button) {
    return (mouseState & SDL_BUTTON(button)) != 0;
}

bool Input::isMouseMoving() {
    return (mouseX != lastMouseX || mouseY != lastMouseY);
}

void Input::resetMouseMovement() {
    lastMouseX = mouseX;
    lastMouseY = mouseY;
}
