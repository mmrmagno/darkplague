#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input {
public:
    void update();
    bool isKeyDown(SDL_Scancode key);
    bool isMouseButtonDown(Uint8 button);
    bool isMouseMoving();
    void resetMouseMovement();

private:
    const Uint8* state;
    Uint32 mouseState;
    int mouseX, mouseY;
    int lastMouseX, lastMouseY;
};

#endif
