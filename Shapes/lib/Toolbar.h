#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Button/IButton.h"

class Toolbar
{
public:
	Toolbar();
	void DrawToolbar(sf::RenderWindow* window, std::string state);
	void Select(sf::Vector2f MouseCoords, std::string state);
private:
	void InitButtons();

	void InitSetThricknessButtons();

	void InitSetOutlineColorButtons();

	void InitFillColorButtons();

	void InitChangeStateButtons();

	void InitNewShapeButtons();

	void InitWriteToFileButtons();

	void InitLoadShapeButtons();

	std::vector<IButton*> m_buttons;
	std::vector<IButton*> m_fillColorButtons;
	std::vector<IButton*> m_setOutlineButtons;
};
#endif
