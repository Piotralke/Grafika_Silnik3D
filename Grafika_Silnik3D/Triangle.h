#pragma once
#ifndef triangle_h
#define triangle_h
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

/**
 * @brief Klasa odpowiedzialna za tworzenie trójkąta
 * 
 */
class Triangle
{
private:
	float vertices[9];
	unsigned int VBO, VAO;
public:
/**
 * @brief Konstruktor klasy Triangle
 * 
 * @param vertices 
 */
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
	/**
	 * @brief Funckja rysująca trójkąt na ekranie
	 * 
	 */
	void draw();
	/**
	 * @brief Ustawienie wierzchołków trójkąta
	 * 
	 * @param vertices tablica wierzchołków trójkąta
	 */
	void setVertices(float vertices[]);
	/**
	 * @brief Pobranie wierzchołków trójkata
	 * 
	 * @return float* - zwrócenie wierzchołków trójkąta
	 */
	float* getVertices();
};

#endif // !triangle_h
