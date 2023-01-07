#pragma once
#include "Bullet.h"

void Bullet::move(float deltaTime)
{
	position += translation * deltaTime * 33.0f;
}