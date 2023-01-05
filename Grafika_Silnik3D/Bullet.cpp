#pragma once
#include "Bullet.h"

void Bullet::move()
{
	position += translation;
}