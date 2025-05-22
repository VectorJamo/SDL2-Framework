#pragma once

#include "ECS.h"

struct Player : public Entity
{
	void Move()
	{
		GetComponent<Transform>()->x += GetComponent<Velocity>()->dx;
		GetComponent<Transform>()->y += GetComponent<Velocity>()->dy;
	}
};
