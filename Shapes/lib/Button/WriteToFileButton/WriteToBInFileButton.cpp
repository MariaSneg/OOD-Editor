#include "WriteToBInFileButton.h"

WriteToBinFileButton::WriteToBinFileButton(sf::Vector2f position)
	:Button(position)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("C:/Programming/ood/Shapes4/Shapes/binFile.png");
	m_texture = texture;

	sf::RectangleShape* button = new sf::RectangleShape(sf::Vector2f(20, 20));
	button->setPosition(position);
	button->setTexture(m_texture);
	m_button = button;
}
