#ifndef BUTTON_H
#define BUTTON_H
#include "IButton.h"

class Button : public IButton
{
public:
	Button(sf::Vector2f position);
	void SetCommand(ICommand* command) override;
	void Execute() override;
	void Push(sf::Vector2f MouseCoords) override;
	void Draw(sf::RenderWindow* window) override;
protected:
	ICommand* m_command = nullptr;
	sf::Vector2f m_position;
	sf::Shape* m_button = nullptr;
};
#endif