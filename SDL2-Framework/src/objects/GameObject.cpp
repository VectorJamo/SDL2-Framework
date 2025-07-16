#include "GameObject.h"

GameObject::GameObject(int objectID, const char* texturePath)
	:m_ObjectID(objectID)
{
	m_ObjectTexture = AssetLoader::LoadTexture(texturePath);

}

GameObject::GameObject(const vec2& position, const vec2& dimension, int objectID, const char* texturePath)
	:m_Position(position), m_Dimension(dimension), m_ObjectID(objectID)
{
	m_ObjectTexture = AssetLoader::LoadTexture(texturePath);

}

GameObject::~GameObject()
{
	SDL_DestroyTexture(m_ObjectTexture);
}

void GameObject::Update(const std::vector<Entity*>& entities, const std::vector<GameObject*>& gameObjects)
{
}

void GameObject::Render(SDL_Renderer* renderer)
{
	SDL_Rect dest = { m_Position.x, m_Position.y, m_Dimension.width, m_Dimension.height };
	SDL_RenderCopy(renderer, m_ObjectTexture, NULL, &dest);
}

void GameObject::SetPosition(const vec2& position)
{
	m_Position = position;
}

void GameObject::SetDimension(const vec2& dimension)
{
	m_Dimension = dimension;
}
