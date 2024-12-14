#ifndef SETBLUECOLOROUTLINECOMMAND_H
#define SETBLUECOLOROUTLINECOMMAND_H

#include"../ICommand.h"
#include <SFML/Graphics.hpp>

class SetOutlineThicknessCommand : public ICommand
{
public:
	SetOutlineThicknessCommand(int thickness);
	void Execute() override;
private:
	int m_thickness;
};
#endif