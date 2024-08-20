#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

class Shader {
public:
    GLuint ID;
    static GLuint loadShader(const char* vertexPath, const char* fragmentPath);
    void use();
};

#endif
