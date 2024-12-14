#include "DragAndDropButton.h"
#include "../../CommandHandler.h"

DragAndDropButton::DragAndDropButton(sf::Vector2f position)
	:Button(position)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("C:/Programming/ood/Shapes4/Shapes/select.png");
	m_texture = texture;

	sf::RectangleShape* button = new sf::RectangleShape(sf::Vector2f(20, 20));
	button->setPosition(position);
	button->setTexture(m_texture);
	m_button = button;
}

void DragAndDropButton::Draw(sf::RenderWindow* window)
{
	if (CommandHandler::GetStateName() == "class DragAndDropState")
	{
		m_button->setOutlineThickness(4);
		m_button->setOutlineColor(sf::Color(177, 168, 232));
	}
	else
	{
		m_button->setOutlineThickness(0);
	}
	window->draw(*m_button);
}