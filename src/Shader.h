#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

class Shader {
public:
    GLuint ID;

    Shader() : ID(0) {}  // Default constructor
    Shader(GLuint programID) : ID(programID) {}  // Constructor with program ID

    static Shader loadShader(const char* vertexPath, const char* fragmentPath);
    void use() const;

    ~Shader() {
        if (ID != 0) {
            glDeleteProgram(ID);
        }
    }
};

#endif
