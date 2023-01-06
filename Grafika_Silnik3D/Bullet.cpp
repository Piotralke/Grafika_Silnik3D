#pragma once
#include "Bullet.h"

void Bullet::move(float deltaTime)
{
	position += translation * deltaTime * 10.0f;
}