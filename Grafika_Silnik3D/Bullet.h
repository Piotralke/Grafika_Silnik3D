#pragma once
#ifndef bullet_h
#define bullet_h
#include "Cube.h"
class Bullet: public Cube
{
private: 
	
public:
	Bullet(glm::vec3 point, glm::vec3 color,glm::vec3 translation):Cube(point,color)
	{
		this->scale(0.1);
		this->translation = translation;
	}
	void move(float deltaTime);
	glm::vec3 translation;
};



#endif // !bullet_h
