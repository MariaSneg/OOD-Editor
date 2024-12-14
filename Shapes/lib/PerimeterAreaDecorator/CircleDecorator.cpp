#include "CircleDecorator.h"

CircleMathDecorator::CircleMathDecorator(Circle* shape)
	: PerimeterAreaDecorator(shape),
	m_shape(shape)
{
}

double CircleMathDecorator::GetPerimeter()
{
	return 2 * M_PI * m_shape->GetRadius();
}

double CircleMathDecorator::GetArea()
{
	return M_PI * std::pow(m_shape->GetRadius(), 2);
}

IShape* CircleMathDecorator::CopyShape()
{
	return new CircleMathDecorator(dynamic_cast<Circle*>(m_shape->CopyShape()));
}
