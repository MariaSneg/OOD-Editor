#include "FillColorButton.h"

FillColorButton::FillColorButton(sf::Vector2f position, sf::Color color)
	:m_color(color),
	Button(position)
{
	sf::RectangleShape* button = new sf::RectangleShape();
	button->setSize(sf::Vector2f(20, 20));
	button->setPosition(m_position);
	button->setFillColor(m_color);
	m_button = button;
}