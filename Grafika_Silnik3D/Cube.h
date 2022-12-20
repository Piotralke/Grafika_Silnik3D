#pragma once
#ifndef cube_h
#define cube_h
#include "glad/glad.h"
//#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

class Cube
{
private:
	float vertices[48];
	unsigned int VBO, VAO, EBO;
public:
	Cube(float vertices[])
	{
		for (int i = 0; i < 48; i++)
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
		0, 1, 2,  //gorna sciana
		0, 3, 2,
		4, 5, 6,  //dolna sciana
		4, 7, 6,
		6, 2, 3, //przednia sciana
		6, 7, 3,
		5, 1, 0, //tylnia sciana
		5, 4, 0,
		6, 5, 1, //lewa sciana
		6, 2, 1,
		0, 3, 7, //prawa sciana
		0, 4, 7
		};
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	void draw();
	void setVertices(float vertices[]);
	float* getVertices();
};

#endif // !rectangle_h