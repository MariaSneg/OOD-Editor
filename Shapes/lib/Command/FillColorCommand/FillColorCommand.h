#ifndef FILLCOLORCOMMAND_H
#define FILLCOLORCOMMAND_H

#include "../ICommand.h"
#include <SFML/Graphics.hpp>

class FillColorCommand : public ICommand
{
public:
	FillColorCommand(sf::Color color);
	void Execute() override;
private:
	sf::Color m_color;
};
#endif