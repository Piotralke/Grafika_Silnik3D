#include "Cube.h"
void Cube::draw()
{
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
void Cube::setVertices(float vertices[])
{
	for (int i = 0; i < 24; i++)
	{
		this->vertices[i] = vertices[i];
	}
}
float* Cube::getVertices()
{
	return this->vertices;
}