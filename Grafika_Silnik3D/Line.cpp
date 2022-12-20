#include "line.h"
void Line::draw()
{
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_LINES, 0, 2);
}
void Line::setVertices(float vertices[])
{
	for (int i = 0; i < 6; i++)
	{
		this->vertices[i] = vertices[i];
	}
}
float* Line::getVertices()
{
	return this->vertices;
}