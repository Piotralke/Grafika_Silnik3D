#pragma once
#ifndef cube_h
#define cube_h
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include <glm/ext/matrix_transform.hpp>
class Cube
{
protected:
	float vertices[48] = {
		0.5f, 0.5f, 0.5f,       0.0f,0.0f,0.0f,//1 
		-0.5f, 0.5f, 0.5f,	    0.0f,0.0f,0.0f,//2
		-0.5f, 0.5f, -0.5f,	    0.0f,0.0f,0.0f,//3
		0.5f,0.5f,-0.5f,	    0.0f,0.0f,0.0f,//4
		0.5f, -0.5f, 0.5f,	    0.0f,0.0f,0.0f,//5
		-0.5f, -0.5f, 0.5f,	    0.0f,0.0f,0.0f,//6
		-0.5f, -0.5f, -0.5f,	0.0f,0.0f,0.0f,//7
		0.5f,-0.5f,-0.5f,	    0.0f,0.0f,0.0f//8
	};
	unsigned int VBO, VAO, EBO;
	glm::vec3 position;
	glm::vec3 scalingFactor;
	float rotationAngleX=0;
	float rotationAngleY=0;
	float rotationAngleZ=0;
public:
	Cube(glm::vec3 point, glm::vec3 color)
	{
		scalingFactor = glm::vec3(1.0, 1.0, 1.0);
		position = point;
		for (int i = 3; i < 49; i=i+6)
		{
			for (int j = 0; j < 3; j++)
			{
				vertices[i + j] = color[j];
			}
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
	void draw(unsigned int programShader);
	void setVertices(float vertices[]);
	float* getVertices();
	void translate(glm::vec3 translation);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	void scale(float k);
	glm::vec3 getPosition();
	glm::vec3 getScalingFactor();
	void setPosition(glm::vec3 position);
	float getRotX();
	float getRotY();
	float getRotZ();
	
};

#endif // !cube_h