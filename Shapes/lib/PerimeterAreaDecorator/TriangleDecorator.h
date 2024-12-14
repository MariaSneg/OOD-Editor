#ifndef TRIANGLEDECORATOR_H
#define TRIANGLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>
#include "PerimeterAreaDecorator.h"
#include "../Shape/Triangle.h"

class TriangleMathDecorator : public PerimeterAreaDecorator
{
public:
	TriangleMathDecorator(Triangle* shape);
	double GetPerimeter() override;
	double GetArea() override;
	IShape* CopyShape() override;
private:
	void CountSize();

	double m_a, m_b, m_c;
	Triangle* m_shape;
};
#endif