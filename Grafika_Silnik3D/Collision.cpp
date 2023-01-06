#include "Collision.h"

bool Collision :: checkCollision(Cube ob1, Cube ob2)
{
	// collision x-axis
	bool collisionX = ob1.getPosition().x + 1.0 * ob1.getScalingFactor().x >= ob2.getPosition().x &&
		ob2.getPosition().x + 1.0 * ob2.getScalingFactor().x >= ob1.getPosition().x;
	// collision y-axis
	bool collisionY = ob1.getPosition().y + 1.0 * ob1.getScalingFactor().y >= ob2.getPosition().y &&
		ob2.getPosition().y + 1.0 * ob2.getScalingFactor().y >= ob1.getPosition().y;
	// collision z-axis
	bool collisionZ = ob1.getPosition().z + 1.0 * ob1.getScalingFactor().z >= ob2.getPosition().z &&
		ob2.getPosition().z + 1.0 * ob2.getScalingFactor().z >= ob1.getPosition().z;
	return collisionX && collisionY && collisionZ;
}
//bool Collision::checkCollision(Cube ob1, Bullet ob2)
//{
//	// collision x-axis
//	bool collisionX = ob1.getPosition().x + 1.0 * ob1.getScalingFactor().x>=ob2.getPosition().x &&
//		ob2.getPosition().x + 1.0*ob2.getScalingFactor().x>=ob1.getPosition().x;
//	// collision y-axis
//	bool collisionY = ob1.getPosition().y + 1.0 * ob1.getScalingFactor().y>=ob2.getPosition().y &&
//	ob2.getPosition().y + 1.0 * ob2.getScalingFactor().y >= ob1.getPosition().y;
//	// collision z-axis
//	bool collisionZ = ob1.getPosition().z + 1.0 * ob1.getScalingFactor().z >= ob2.getPosition().z &&
//		ob2.getPosition().z + 1.0 * ob2.getScalingFactor().z >= ob1.getPosition().z;
//	return collisionX && collisionY && collisionZ;
//}