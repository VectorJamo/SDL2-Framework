#pragma once
class Entity;
class GameObject;
struct vec2;

// Simple AABB collision
class CollisionHandler
{
public:
	static bool CheckCollision(Entity* e1, Entity* e2, const vec2& e1Vel, const vec2& e2Vel);
	static bool CheckCollision(Entity* entity, GameObject* object, const vec2& entityVel, const vec2& objectVel);
	static bool CheckCollision(GameObject* o1, GameObject* o2, const vec2& o1Vel, const vec2& o2Vel);
};

