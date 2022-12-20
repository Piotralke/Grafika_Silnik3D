#include "Rectangle.h"
void Rectangle::draw()
{
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void Rectangle::setVertices(float vertices[])
{
	for (int i = 0; i < 12; i++)
	{
		this->vertices[i] = vertices[i];
	}
}
float* Rectangle::getVertices()
{
	return this->vertices;
}