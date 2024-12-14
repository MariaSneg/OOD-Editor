#include "Button.h"

Button::Button(sf::Vector2f position)
	: m_position(position)
{
}

void Button::SetCommand(ICommand* command)
{
	m_command = command;
}

void Button::Execute()
{
	m_command->Execute();
}

void Button::Push(sf::Vector2f MouseCoords)
{
	if (m_button->getGlobalBounds().contains(MouseCoords))
	{
		Execute();
	}
}

void Button::Draw(sf::RenderWindow* window)
{
	window->draw(*m_button);
}
