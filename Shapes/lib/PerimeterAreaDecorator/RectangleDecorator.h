#ifndef RECTANGLEDECORATOR_H
#define RECTANGLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>
#include "PerimeterAreaDecorator.h"
#include "../Shape/Rectangle.h"

class RectangleMathDecorator : public PerimeterAreaDecorator
{
public:
	RectangleMathDecorator(Rectangle* shape);
	double GetPerimeter() override;
	double GetArea() override;
	IShape* CopyShape() override;
private:
	Rectangle* m_shape;
};
#endif