#include "TriangleStrip.h"
void TriangleStrip::draw()
{
	glBindVertexArray(this->VAO);
	//glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, (this->n/3));
}
void TriangleStrip::setVertices(float vertices[])
{
	for (int i = 0; i < this->n; i++)
	{
		this->vertices[i] = vertices[i];
	}
}
float* TriangleStrip::getVertices()
{
	return this->vertices.data();
}