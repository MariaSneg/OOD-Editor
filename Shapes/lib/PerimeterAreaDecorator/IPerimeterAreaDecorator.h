#ifndef IPERIMETERAREADECORATOR_H
#define IPERIMETERAREADECORATOR_H

#include <SFML/Graphics.hpp>
#include "../Shape/IShape.h"

class IPerimeterAreaDecorator : public IShape
{
public:
	virtual double GetPerimeter() = 0;
	virtual double GetArea() = 0;
};

#endif