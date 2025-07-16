#pragma once
#include "maths/vec2.h"
#include "utils/AssetLoader.h"
#include <vector>
#include <SDL_image.h>

class Entity;

class GameObject
{
protected:
	int m_ObjectID;
	vec2 m_Position, m_Dimension;
	SDL_Texture* m_ObjectTexture;

public:
	GameObject(int objectID, const char* texturePath);
	GameObject(const vec2& position, const vec2& dimension, int objectID, const char* texturePath);
	virtual ~GameObject();

	virtual void Update(const std::vector<Entity*>& entities, const std::vector<GameObject*>& gameObjects);
	virtual void Update(const std::vector<Entity*>& entities, const std::vector<GameObject*>& gameObjects, float camX, float camY) = 0;
	virtual void Render(SDL_Renderer* renderer);
	virtual void Render(SDL_Renderer* renderer, float camX, float camY) = 0;

	void SetPosition(const vec2& position);
	void SetDimension(const vec2& dimension);

	inline vec2& GetPosition() { return m_Position; }
	inline vec2& GetDimension() { return m_Dimension; }
	inline int GetObjectID() { return m_ObjectID; }
};

