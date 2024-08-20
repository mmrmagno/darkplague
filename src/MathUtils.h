#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <glm/glm.hpp>  // For vector and matrix operations

// Utility functions for common math operations
glm::mat4 createTransformationMatrix(const glm::vec3& position, const glm::vec3& rotation, float scale);

#endif
