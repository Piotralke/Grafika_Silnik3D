#pragma once
#ifndef brokenline_h
#define brokenlineh_
#include "glad/glad.h"
#include "GLFW/glfw3.h"

/**
 * @brief Klasa reprezentująca łamaną linię
 * 
 */
class BrokenLine
{
private:
/**
 * @brief Tablica przechowująca dane o liniach
 * 
 */
	float vertices[6];
	unsigned int VBO, VAO;
public:
/**
 * @brief Konstruktor obiektu BrokenLine
 * 
 * @param vertices Tablica przechowująca dane o liniach
 */
	BrokenLine(float vertices[])
	{
		for (int i = 0; i < 6; i++)
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
	 * @brief Funkcja rysująca linię
	 * 
	 */
	void draw();
	/**
	 * @brief Ustawia nową tablicę vertices
	 * 
	 * @param vertices Tablica przechowująca dane o liniach
	 */
	void setVertices(float vertices[]);
	/**
	 * @brief Zwraca tabelę vertices
	 * 
	 * @return float* 
	 */
	float* getVertices();
};

#endif // !brokenline_h