#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec3 color;
out vec2 texCoord;

out vec3 Normal;
out vec3 currentPos;


uniform mat4 cameraMatrix;
uniform mat4 model;

void main()
{
   currentPos = vec3(model * vec4(aPos, 1.0f));
   gl_Position = cameraMatrix * vec4(currentPos, 1.0);
   color = aColor;
   texCoord = aTex;
   Normal = aNormal;
}
