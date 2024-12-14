#ifndef IBUTTON_H
#define IBUTTON_H

#include "../Command/ICommand.h"
#include <SFML/Graphics.hpp>

class IButton
{
public:
	virtual void SetCommand(ICommand* command) = 0;
	virtual void Execute() = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual void Push(sf::Vector2f MouseCoords) = 0;
};
#endif