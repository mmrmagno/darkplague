#include "Renderer.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>

SDL_Window* window;
SDL_GLContext glContext;

bool Renderer::initSDLAndOpenGL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    window = SDL_CreateWindow("Dark Plague", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) return false;

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) return false;

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) return false;

    glEnable(GL_DEPTH_TEST);
    return true;
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::swapBuffers() {
    SDL_GL_SwapWindow(window);
}

void Renderer::render(GameObject& obj) {
    // Bind VAO, shaders, set uniforms, etc.
    glBindVertexArray(obj.getVAO());
    glDrawArrays(GL_TRIANGLES, 0, obj.getVertexCount());
}
