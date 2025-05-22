#include "ECS.h"

Entity::Entity()
{
}

Entity::~Entity()
{
	for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		delete it->second;
	}
}
