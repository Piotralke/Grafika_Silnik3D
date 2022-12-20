#pragma once
#ifndef rectangle_h
#define rectangle_h
#include "glad/glad.h"
//#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

class Rectangle
{
private:
	float vertices[12];
	unsigned int VBO, VAO, EBO;
public:
	Rectangle(float vertices[])
	{
		for (int i = 0; i < 12; i++)
		{
			this->vertices[i] = vertices[i];
		}
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
		unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
		};
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	void draw();
	void setVertices(float vertices[]);
	float* getVertices();
};

#endif // !rectangle_h