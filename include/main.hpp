#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "glad.h"

#include "GLFW/glfw3.h"

#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/scalar_constants.hpp"

#include "stb_image.h"

#include "shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

#define WIDTH 800
#define HEIGHT 600

typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;

#endif // MAIN_HPP
