#pragma once
#ifndef bullet_h
#define bullet_h
#include "Cube.h"
class Bullet: public Cube
{
private: 
	glm::vec3 translation;
public:
	Bullet(glm::vec3 point, glm::vec3 color,glm::vec3 translation):Cube(point,color)
	{
		this->scale(0.1);
		translation = translation;
	}
	void move();
};



#endif // !bullet_h
