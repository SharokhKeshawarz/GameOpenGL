#include "../include/game.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
}

char *open_glsl(char const *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    stat(path, &st);
    char *buffer = malloc(st.st_size + 1);
    ssize_t bytes_read = read(fd, buffer, st.st_size);
    buffer[bytes_read] = '\0';
    return buffer;
}

void check_vertex_shader_error(GLFWwindow *window, unsigned int vertexShader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("Can't Compile Vertex Shader\n%s\n", infoLog);
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

void check_fragment_shader_error(GLFWwindow *window, unsigned int vertexShader, unsigned int fragmentShader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("Can't Compile Fragment Shader\n%s\n", infoLog);
        glDeleteShader(vertexShader);
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

void check_program_error(GLFWwindow *window, unsigned int shaderProgram, unsigned int vertexShader, unsigned int fragmentShader)
{
    int success;
    char infoLog[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("Can't Link Program\n%s\n", infoLog);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}
