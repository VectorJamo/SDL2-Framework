#include <iostream>
#include <unordered_map>
#include <cassert>

#include "DefaultComponents.h"

struct Entity
{
private:
	std::unordered_map<size_t, void*> m_Components;

public:
	Entity();
	virtual ~Entity();

	template<typename T>
	void AddComponent(T component);

	template<typename T>
	T* GetComponent();

};

template<typename T>
void Entity::AddComponent(T component)
{
	const std::type_info& info = typeid(T);
	int key = info.hash_code();

	// Check if the component already exists
	if (m_Components.count(key) > 0)
	{
		// The component already exists
		std::cout << "The component already exists!" << std::endl;
	}
	else {
		// Attach the component if it does not already exist
		m_Components[key] = new T(component);
	}
}

template<typename T>
T* Entity::GetComponent()
{
	const std::type_info& info = typeid(T);
	int key = info.hash_code();

	// Check if the component exists
	if (m_Components.count(key) > 0)
	{
		// The component exists, so return it.
		return ((T*)(m_Components[key]));
	}
	else {
		// The component does not exist.
		std::cout << "The component does not exist!" << std::endl;
		assert(false); // Bomb the program
	}
}

#if 0
void test()
{
	Entity e;
	e.AddComponent<Position>({ 1.0f, 2.0f });

	Position* p = e.GetComponent<Position>();
	p->y++;

	std::cout << e.GetComponent<Position>()->y;
}
#endif