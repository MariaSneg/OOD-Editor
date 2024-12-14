#include "SetOutlineThicknessButton.h"

SetOutlineThicknessButton::SetOutlineThicknessButton(sf::Vector2f position, int thickness)
	:m_thickness(thickness),
	Button(position)
{
	sf::RectangleShape* button = new sf::RectangleShape();
	button->setSize(sf::Vector2f(20 - m_thickness, 20 - m_thickness));
	button->setPosition(m_position);
	button->setFillColor(sf::Color::White);
	button->setOutlineThickness(m_thickness);
	button->setOutlineColor(sf::Color(177, 168, 232));
	m_button = button;
}
