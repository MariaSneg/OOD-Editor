#ifndef CIRCLEDECORATOR_H
#define CIRCLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>
#include "PerimeterAreaDecorator.h"
#include "../Shape/Circle.h"

class CircleMathDecorator : public PerimeterAreaDecorator
{
public:
	CircleMathDecorator(Circle* shape);
	double GetPerimeter() override;
	double GetArea() override;
	IShape* CopyShape() override;
private:
	Circle* m_shape;
};
#endif