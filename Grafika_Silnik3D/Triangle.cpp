#include"Triangle.h"
void Triangle::draw()
{
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Triangle::setVertices(float vertices[])
{
	for (int i = 0; i < 9; i++)
	{
		this->vertices[i] = vertices[i];
	}
}
float* Triangle::getVertices()
{
	return this->vertices;
}