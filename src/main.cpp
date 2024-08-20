#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Player.h"
#include "Enemy.h"
#include "Physics.h"
#include "Input.h"
#include "Sound.h"

// Main game loop
int main(int argc, char* argv[]) {
    if (!initSDLAndOpenGL()) {
        return -1;
    }

    Player player;
    Enemy enemy;
    Physics physics;
    Input input;
    Sound sound;

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
