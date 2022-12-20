#pragma once
#ifndef triangle_h
#define triangle_h
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

class Triangle
{
private:
	float vertices[9];
	unsigned int VBO, VAO;
public:
	Triangle(float vertices[])
	{
		for(int i = 0; i < 9; i++)
		{
			this->vertices[i] = vertices[i];
		}
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}
	void draw();
	void setVertices(float vertices[]);
	float* getVertices();
};

#endif // !triangle_h
