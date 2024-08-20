#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class GameObject {
public:
    glm::vec3 position;
    glm::vec3 size;

    virtual GLuint getVAO() = 0;
    virtual int getVertexCount() = 0;
};

#endif
