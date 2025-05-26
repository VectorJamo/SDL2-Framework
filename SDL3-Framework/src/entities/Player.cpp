#include "Player.h"

void Player::Move()
{
	if (HasComponent<Transform>() && HasComponent<Velocity>())
	{
		GetComponent<Transform>()->x += GetComponent<Velocity>()->dx;
		GetComponent<Transform>()->y += GetComponent<Velocity>()->dy;
	}
}