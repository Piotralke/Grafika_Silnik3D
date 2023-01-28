#pragma once
#ifndef camera_h
#define camera_h
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glm/gtc/matrix_transform.hpp"
class Camera {
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::mat4 model; 
	glm::mat4 view; 
	glm::mat4 projection;
	bool firstMouse;
	float lastX;
	float lastY;
	float pitch;
	float yaw;
public:
	Camera();
	Camera(float screenWidth, float screenHeight, unsigned int programShader, unsigned int programShader2, GLFWwindow* window)
	{
		cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		glUseProgram(programShader);
		glUniformMatrix4fv(glGetUniformLocation(programShader, "projection"), 1, GL_FALSE, &projection[0][0]);
		glUseProgram(programShader2);
		glUniformMatrix4fv(glGetUniformLocation(programShader2, "projection"), 1, GL_FALSE, &projection[0][0]);
		//glfwMakeContextCurrent(window);
		firstMouse = true;
		lastX = screenWidth / 2;
		lastY = screenHeight / 2;
		pitch = 0.0f;
		yaw = -90.0f;
	}
	void UpdateCamera(unsigned int programShader, unsigned int programShader2);
	void VerticalMove(bool isUp, float cameraSpeed);
	void HorizontalMove(bool isRight, float cameraSpeed);
	void UpdateMouse(double xpos, double ypos);
	glm::mat4 getView();
	glm::vec3 getCameraFront();
	glm::vec3 getCameraPos();
	void setCameraPos(glm::vec3 pos);
};

#endif // !camera_h
