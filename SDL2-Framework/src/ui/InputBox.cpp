#include "InputBox.h"
#include <iostream>

InputBox::InputBox(const vec2& position, const vec2& dimension, SDL_Renderer* renderer)
	:m_Position(position), m_Dimension(dimension)
{
	m_Text = new Text(std::string(""), m_Position.x + m_TextOffset, m_Position.y + m_TextOffset, m_Dimension.height/3, renderer);
}

InputBox::~InputBox()
{
	delete m_Text;
}

void InputBox::Update(SDL_Event* ev)
{
	// Check if it is active or not
	int mx, my;
	SDL_GetMouseState(&mx, &my);
		
	if (MouseManager::IsMouseButtonPressed(SDL_BUTTON_LEFT))
	{
		std::cout << 3;
		if (mx > m_Position.x && mx < m_Position.x + m_Dimension.width && my > m_Position.y && my < m_Position.y + m_Dimension.height)
		{
			isActive = true;
		}
		else {
			isActive = false;
		}
	}

	if (isActive)
	{
		// Do stuff when the input box is active
		// Get what the user has typed.
		if (ev->type == SDL_KEYDOWN)
		{
			unsigned char keyCode = ev->key.keysym.sym;
			std::cout << keyCode << std::endl;
			if (keyCode > 97 && keyCode < 123) // a -> z
			{
				std::string str = m_Text->GetString();
				str.push_back(keyCode);

				std::cout << "New String: " << str << std::endl;

				m_Text->SetText(str); // TODO: Check for bounds.
			}
		}
	}
}

void InputBox::Render(SDL_Renderer* renderer)
{
	// Outline
	SDL_Rect rect = { m_Position.x, m_Position.y, m_Dimension.width, m_Dimension.height };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White by default.
	SDL_RenderDrawRect(renderer, &rect);

	// Text
	m_Text->Render();
}