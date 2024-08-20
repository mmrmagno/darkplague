#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Player.h"
#include "Enemy.h"
#include "Physics.h"
#include "Input.h"
#include "Sound.h"

int main(int argc, char* argv[]) {
    if (!Renderer::initSDLAndOpenGL()) {
        return -1;
    }

    Player player;
    Enemy enemy(Vector3(2.0f, 0.0f, -5.0f));
    Physics physics;
    Input input;
    Sound sound;

    if (!sound.init()) {
        return -1;
    }

    sound.playSound("assets/sounds/ambient.wav");

    bool running = true;
    while (running) {
        input.handleInput(running, player);

        // Update game logic
        physics.update(player, enemy);
        enemy.update(player);

        // Render the scene
        Renderer::clear();
        Renderer::render(player);
        Renderer::render(enemy);
        Renderer::swapBuffers();

        SDL_Delay(16);  // Cap to ~60 FPS
    }

    sound.cleanup();
    SDL_Quit();
    return 0;
}
