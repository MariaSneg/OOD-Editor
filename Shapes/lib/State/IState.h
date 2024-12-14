#ifndef ISTATE_H
#define ISTATE_H

class IState
{
public:
	virtual void Select(sf::RenderWindow* window) = 0;
	virtual void SetFillColor(sf::RenderWindow* window) = 0;
	virtual void SetOutline(sf::RenderWindow* window) = 0;
};
#endif