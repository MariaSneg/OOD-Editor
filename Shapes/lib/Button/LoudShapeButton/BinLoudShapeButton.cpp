#include "BinLoudShapeButton.h"

BinLoadShapeButton::BinLoadShapeButton(sf::Vector2f position)
	:Button(position)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("C:/Programming/ood/Shapes4/Shapes/binFileImport.png");
	m_texture = texture;

	sf::RectangleShape* button = new sf::RectangleShape(sf::Vector2f(20, 20));
	button->setPosition(position);
	button->setTexture(m_texture);
	m_button = button;
}
