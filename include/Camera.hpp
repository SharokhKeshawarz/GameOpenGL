#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glad.h"
#include "GLFW/glfw3.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "Shader.hpp"

class Camera
{
    public:
        glm::vec3 Position;
        glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 cameraMatrix = glm::mat4(1.0f);

        int width, height;
        float speed = 0.1f;
        float sensitivity = 100.0f;
        bool firstClick = true;

        Camera(int width, int height, glm::vec3 Position);

        void Matrix(Shader& shader, const char *uniform);
        void Inputs(GLFWwindow *window);

        void UpdateMatrix(float fovDeg, float nearPlane, float farPlane);

};

#endif /* CAMERA_HPP */
