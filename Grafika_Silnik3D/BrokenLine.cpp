#include "BrokenLine.h"
void BrokenLine::draw()
{
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_LINES, 0, 3);
}
void BrokenLine::setVertices(float vertices[])
{
	for (int i = 0; i < 6; i++)
	{
		this->vertices[i] = vertices[i];
	}
}
float* BrokenLine::getVertices()
{
	return this->vertices;
}