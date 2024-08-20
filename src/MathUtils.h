#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <glm/glm.hpp>

glm::mat4 createTransformationMatrix(const glm::vec3& position, const glm::vec3& rotation, float scale);

#endif
