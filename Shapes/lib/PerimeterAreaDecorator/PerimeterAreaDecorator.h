#ifndef PERIMETERAREADECORATOR_H
#define PERIMETERAREADECORATOR_H

#include "IPerimeterAreaDecorator.h"

class PerimeterAreaDecorator : public IPerimeterAreaDecorator
{
public:
	PerimeterAreaDecorator(IShape* shape);
	void PrintData(std::ofstream& output) override;
	sf::Shape* GetDrawableShape() override;
	sf::FloatRect GetBounds() override;
	double GetPerimeter() override;
	double GetArea() override;
	std::string ToString() override;
protected:
	IShape* m_shape;
};
#endif
