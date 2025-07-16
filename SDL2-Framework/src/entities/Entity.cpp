#include "Entity.h"

Entity::Entity(int entityID, const char* texturePath)
	:m_EntityID(entityID)
{
	m_EntityTexture = AssetLoader::LoadTexture(texturePath);
}

Entity::Entity(const vec2& position, const vec2& dimension, int entityID, const char* texturePath)
	:m_Position(position), m_Dimension(dimension), m_EntityID(entityID)
{
	m_EntityTexture = AssetLoader::LoadTexture(texturePath);
}

Entity::~Entity()
{
	SDL_DestroyTexture(m_EntityTexture);
}

void Entity::Update(const std::vector<Entity*>& entities, const std::vector<GameObject*>& gameObjects)
{
}

void Entity::Render(SDL_Renderer* renderer)
{
	SDL_Rect dest = { m_Position.x, m_Position.y, m_Dimension.width, m_Dimension.height };
	SDL_RenderCopy(renderer, m_EntityTexture, NULL, &dest);
}

void Entity::Render(SDL_Renderer* renderer, float camX, float camY)
{
}

void Entity::SetPosition(const vec2& position)
{
	m_Position = position;
}

void Entity::SetDimension(const vec2& dimension)
{
	m_Dimension = dimension;
}

