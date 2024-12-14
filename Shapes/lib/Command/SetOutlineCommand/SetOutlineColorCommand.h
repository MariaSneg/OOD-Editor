#ifndef SETOUTLINECOLORCOMMAND_H
#define SETOUTLINECOLORCOMMAND_H

#include"../ICommand.h"
#include <SFML/Graphics.hpp>

class SetOutlineColorCommand : public ICommand
{
public:
	SetOutlineColorCommand(sf::Color color);
	void Execute() override;
private:
	sf::Color m_color;
};
#endif