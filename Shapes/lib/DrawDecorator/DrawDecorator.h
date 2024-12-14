#ifndef DRAWDECORATOR_H
#define DRAWDECORATOR_H

#include "IDrawDecorator.h"
class DrawDecorator : public IDrawDecorator
{
public:
	DrawDecorator(IShape* shape);
	void PrintData(std::ofstream& output) override;
	bool Select(sf::Vector2f MouseCoords, bool groupSelected) override;
	bool Move(sf::Vector2f MouseCoords, bool groupMoved) override;
	sf::FloatRect GetBounds() override;
	bool IsComposite() override;
	IShape* GetShape() override;
	sf::Shape* GetDrawableShape() override;
	bool SetIsMoved(sf::Vector2f MouseCoords, bool groupMoved) override;
	bool IsSelected() override;
	void Draw(sf::RenderWindow* window) override;
	bool SetFillColor(sf::Vector2f MouseCoords, sf::Color color, bool groupSelected) override;
	bool SetOutline(sf::Vector2f MouseCoords, sf::Color color, int thickness, bool groupSelected) override;
	std::string ToString() override;
protected:
	sf::Shape* m_drawableShape;
	IShape* m_shape;
	bool m_isSelected = false;
	bool m_isMoved = false;
	sf::Vector2f m_lastMousePosition;
};
#endif
