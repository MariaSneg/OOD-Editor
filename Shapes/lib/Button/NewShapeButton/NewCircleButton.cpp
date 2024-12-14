#include "NewCircleButton.h"

NewCircleButton::NewCircleButton(sf::Vector2f position)
	: Button(position)
{
	sf::CircleShape* button = new sf::CircleShape(10);
	button->setPosition(m_position);
	button->setFillColor(sf::Color::White);
	m_button = button;
}
