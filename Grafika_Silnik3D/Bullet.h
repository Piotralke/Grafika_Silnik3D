#pragma once
#ifndef bullet_h
#define bullet_h
#include "Cube.h"

/**
 * @brief Klasa przedstawiająca pocisk
 * 
 */
class Bullet: public Cube
{
private: 
	
public:
/**
 * @brief Konstruktor obiektu Bullet
 * 
 * @param point Współrzędne punktu
 * @param color Kolor obiektu pocisku
 * @param translation Kierunek w którym porusza się pocisk
 */
	Bullet(glm::vec3 point, glm::vec3 color,glm::vec3 translation):Cube(point,color)
	{
		this->scale(0.1);
		this->translation = translation;
	}
	/**
	 * @brief Metoda odpowiadająca za ruch
	 * 
	 * @param deltaTime 
	 */
	void move(float deltaTime);
	/**
	 * @brief wektor (odpowiadający za przemieszczenie)
	 * 
	 */
	glm::vec3 translation;
};



#endif // !bullet_h
