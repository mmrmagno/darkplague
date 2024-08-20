#include "Renderer.h"
#include "Shader.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>

SDL_Window* window;
SDL_GLContext glContext;
Shader shaderProgram;

bool Renderer::initSDLAndOpenGL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Dark Plague", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        return false;
    }

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    shaderProgram = Shader::loadShader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    return true;
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::swapBuffers() {
    SDL_GL_SwapWindow(window);
}

void Renderer::render(GameObject& obj) {
    shaderProgram.use();
    glBindVertexArray(obj.getVAO());
    glDrawArrays(GL_TRIANGLES, 0, obj.getVertexCount());
}
