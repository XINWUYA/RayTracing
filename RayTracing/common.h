#pragma once
#include <GLM/glm.hpp>

#define SINGLE_PRECISION

#ifdef SINGLE_PRECISION
typedef float Float;
typedef glm::vec3 Vec3;
#else
typedef double Float;
typedef glm::dvec3 Vec3;
#endif // SINGLE_PRECISION
