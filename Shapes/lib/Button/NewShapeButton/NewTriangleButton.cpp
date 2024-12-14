#include "NewTriangleButton.h"

NewTriangleButton::NewTriangleButton(sf::Vector2f position)
	:Button(position)
{
    sf::ConvexShape* button = new sf::ConvexShape();

    button->setPointCount(3);
    button->setPoint(0, sf::Vector2f(0, 20));   
    button->setPoint(1, sf::Vector2f(10, 0));   
    button->setPoint(2, sf::Vector2f(20, 20)); 

    button->setPosition(m_position);
    button->setFillColor(sf::Color::White);

    m_button = button;
}