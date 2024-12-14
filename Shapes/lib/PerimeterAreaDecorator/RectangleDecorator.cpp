#include "RectangleDecorator.h"

RectangleMathDecorator::RectangleMathDecorator(Rectangle* shape)
	: PerimeterAreaDecorator(shape), 
	m_shape(shape)
{
}

double RectangleMathDecorator::GetPerimeter()
{
	return 2 * m_shape->GetSize()->x + 2 * m_shape->GetSize()->y;
}

double RectangleMathDecorator::GetArea()
{
	return m_shape->GetSize()->x * m_shape->GetSize()->y;
}

IShape* RectangleMathDecorator::CopyShape()
{
	return new RectangleMathDecorator(dynamic_cast<Rectangle*>(m_shape->CopyShape()));
}
