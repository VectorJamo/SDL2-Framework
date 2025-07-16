#include "CollisionHandler.h"

#include "entities/Entity.h"
#include "objects/GameObject.h"

bool CollisionHandler::CheckCollision(Entity* e1, Entity* e2, const vec2& e1Vel, const vec2& e2Vel)
{
    float e1XNew = e1->GetPosition().x + e1Vel.x;
	float e1YNew = e1->GetPosition().y + e1Vel.y;
	float e2XNew = e2->GetPosition().x + e2Vel.x;
	float e2YNew = e2->GetPosition().y + e2Vel.y;

	if (e1XNew > e2XNew + e2->GetDimension().x || e1YNew > e2YNew + e2->GetDimension().y
		|| e2XNew > e1XNew + e1->GetDimension().x || e2YNew > e1YNew + e1->GetDimension().y)
	{
		return false;
	}
    return true;
}

bool CollisionHandler::CheckCollision(Entity* entity, GameObject* object, const vec2& entityVel, const vec2& objectVel)
{
	float entityXNew = entity->GetPosition().x + entityVel.x;
	float entityYNew = entity->GetPosition().y + entityVel.y;
	float objectXNew = object->GetPosition().x + objectVel.x;
	float objectYNew = object->GetPosition().y + objectVel.y;

	if (entityXNew > objectXNew + object->GetDimension().x || entityYNew > objectYNew + object->GetDimension().y
		|| objectXNew > entityXNew + entity->GetDimension().x || objectYNew > entityYNew + entity->GetDimension().y)
	{
		return false;
	}
	return true;
}

bool CollisionHandler::CheckCollision(GameObject* o1, GameObject* o2, const vec2& o1Vel, const vec2& o2Vel)
{
	float o1XNew = o1->GetPosition().x + o1Vel.x;
	float o1YNew = o1->GetPosition().y + o1Vel.y;
	float o2XNew = o2->GetPosition().x + o2Vel.x;
	float o2YNew = o2->GetPosition().y + o2Vel.y;

	if (o1XNew > o2XNew + o2->GetDimension().x || o1YNew > o2YNew + o2->GetDimension().y
		|| o2XNew > o1XNew + o1->GetDimension().x || o2YNew > o1YNew + o1->GetDimension().y)
	{
		return false;
	}
	return true;
}