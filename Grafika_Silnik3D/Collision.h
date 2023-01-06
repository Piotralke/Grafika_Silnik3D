#pragma once
#ifndef collision_h
#define collision_h
#include "Bullet.h"
class Collision
{
private:

public:
	Collision();
	bool checkCollision(Cube ob1,Cube ob2);
	//bool checkCollision(Cube ob1,Bullet ob2);
};

#endif // !collision_h
