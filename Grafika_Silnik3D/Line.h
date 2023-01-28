#pragma once
#ifndef line_h
#define lineh_
#include "glad/glad.h"
//#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
/**
 * @brief Klasa reprezentująca linie
 * 
 */
class Line
{
private:
	/**
	 * @brief matryca przechowujaca dwa punkty
	 * 
	 */
	float vertices[6];
	unsigned int VBO, VAO;
public:
	/**
	 * @brief Konstruktor klasy Linia
 	 * 
 	 * @param vertices Tablica zawierająaca informacje o współrzędnych
  	 */
	Line(float vertices[])
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
	 * @brief Funkcja rysująca linie
	 * 
	 */
	void draw();
	/**
	 * @brief Ustawnienie współrzędnych dla linii
	 * 
	 * @param vertices 
	 */
	void setVertices(float vertices[]);
	/**
	 * @brief Pobranie współrzędnych linii
	 * 
	 * @return float* 
	 */
	float* getVertices();
};

#endif // !line_h