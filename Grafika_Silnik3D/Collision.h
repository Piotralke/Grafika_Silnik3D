#pragma once
#ifndef collision_h
#define collision_h
#include "Bullet.h"

/**
 * @brief Klasa odpowiedzialna za kolizję
 * 
 */
class Collision
{
private:

public:
/**
 * @brief Konstruktor klasy Collision
 * 
 */
	Collision();
	/**
	 * @brief Funkcja sprawdzająca czy występuje kolizja między dwoma obiektami
	 * 
	 * @param ob1 1 obiekt
	 * @param ob2 2 obiekt
	 * @return true Gdy jest kolizja między obiektami
	 * @return false Gdy nie ma kolizji między obiektami
	 */
	bool checkCollision(Cube ob1,Cube ob2);
};

#endif // !collision_h
