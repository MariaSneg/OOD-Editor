#ifndef IDRAWDECORATOR_H
#define IDRAWDECORATOR_H

#include <SFML/Graphics.hpp>
#include "../Shape/IShape.h"
class IVisitor;

class IDrawDecorator : public IShape
{
public:
	virtual bool Select(sf::Vector2f MouseCoords, bool groupSelected) = 0;
	virtual bool Move(sf::Vector2f MouseCoords, bool groupMoved) = 0;
	virtual bool SetIsMoved(sf::Vector2f MouseCoords, bool groupMoved) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual bool SetFillColor(sf::Vector2f MouseCoords, sf::Color color, bool groupSelected) = 0;
	virtual bool SetOutline(sf::Vector2f MouseCoords, sf::Color color, int thickness, bool groupSelected) = 0;
	virtual sf::FloatRect GetBounds() = 0;
	virtual bool IsComposite() = 0;
	virtual bool IsSelected() = 0;
	virtual IShape* GetShape() = 0;
	virtual void Accept(std::shared_ptr<IVisitor> visitor) = 0;
};

#endif