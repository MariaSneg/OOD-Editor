#include "NewRectangleButton.h"

NewRectangleButton::NewRectangleButton(sf::Vector2f position)
	: Button(position)
{
	sf::RectangleShape* button = new sf::RectangleShape();
	button->setSize(sf::Vector2f(20, 20));
	button->setPosition(m_position);
	button->setFillColor(sf::Color::White);
	m_button = button;
}
