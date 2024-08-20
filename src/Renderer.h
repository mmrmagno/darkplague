#ifndef RENDERER_H
#define RENDERER_H

#include "GameObject.h"

class Renderer {
public:
    static bool initSDLAndOpenGL();
    static void clear();
    static void swapBuffers();
    static void render(GameObject& obj);
};

#endif
