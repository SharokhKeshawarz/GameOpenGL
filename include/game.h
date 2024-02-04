#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <sys/stat.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "cglm/cglm.h"

// #include <SFML/System.h>
// #include <SFML/Window.h>
// #include <SFML/OpenGL.h>
// #include <SFML/Graphics.h>
// #include <SFML/Audio.h>
// #include <SFML/Network.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
char *open_glsl(char const *path);
void check_vertex_shader_error(GLFWwindow *window, unsigned int vertexShader);
void check_fragment_shader_error(GLFWwindow *window, unsigned int vertexShader, unsigned int fragmentShader);
void check_program_error(GLFWwindow *window, unsigned int shaderProgram, unsigned int vertexShader, unsigned int fragmentShader);

#endif /* GAME_H */
