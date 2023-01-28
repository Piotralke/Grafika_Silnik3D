#pragma once
#ifndef trianglestrip_h
#define trianglestrip_h
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>
#include <iterator>
#include <iostream>

/**
 * @brief Klasa reprezentująca TriangleStrip
 * 
 */
class TriangleStrip
{
private:
	/**
	 * @brief wektor verticies
	 * 
	 */
	std::vector<float> vertices;
	/**
	 * @brief VBO,VAO,EBO
	 * 
	 */
	unsigned int VBO, VAO, EBO;
	/**
	 * @brief ilość danych
	 * 
	 */
	int n;
public:
/**
 * @brief Konstruktor klasy trangle strip
 * 
 * @param vertices tablica vertices
 * @param size rozmiar
 */
	TriangleStrip(float vertices[],int size)
	{
		n = size;
		std::cout << n << std::endl;
		for (int i = 0; i < n; i++)
		{
			this->vertices.push_back(vertices[i]);
		}
		
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		float* fVertices = this->vertices.data();
		for (int i = 0; i < n; i++)
		{
			std::cout << fVertices[i] << std::endl;
		}
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 4*n, fVertices, GL_STATIC_DRAW);
		//unsigned int indices[] = {
		//0, 1, 3,
		//1, 2, 3
		//};
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	/**
	 * @brief Funkcja rysująca trójkąt
	 * 
	 */
	void draw();
	/**
	 * @brief Ustawia tablicę wspolrzednych
	 * 
	 * @param vertices tablica vertices
	 */
	void setVertices(float vertices[]);
	/**
	 * @brief Pobiera tablicę wspolrzednych
	 * 
	 * @return tablica vertices
	 */
	float* getVertices();
};
#endif // !trianglefan_h
