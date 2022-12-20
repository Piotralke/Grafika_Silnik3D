#pragma once
#ifndef point3d_h
#define point3d_h
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <GLFW/glfw3.h>

class Point3D
{
private:
	float vertices[3];
	unsigned int VAO, VBO;
public:
	Point3D(float vertices[])
	{
		for (int i = 0; i < 3; i++)
		{
			this->vertices[i] = vertices[i];
		}
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}
	float getX();
	float getY();
	float getZ();
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	glm::vec3 getVec();
	void setVec(glm::vec3 vec);
	void draw();
};
#endif // !point3d_h
