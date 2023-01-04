#pragma once
#include "glm/gtc/matrix_transform.hpp"
#include <glad/glad.h>
#ifndef camera_h
#define camera_h

class Camera {
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::mat4 model; 
	glm::mat4 view; 
	glm::mat4 projection;
public:
	Camera();
	Camera(float screenWidth, float screenHeight, unsigned int programShader)
	{
		cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		glUseProgram(programShader);
		glUniformMatrix4fv(glGetUniformLocation(programShader, "projection"), 1, GL_FALSE, &projection[0][0]);
	}
	void UpdateCamera(unsigned int programShader);
	void VerticalMove(bool isUp, float cameraSpeed);
	void HorizontalMove(bool isRight, float cameraSpeed);
};

#endif // !camera_h
