#include "TriangleDecorator.h"

TriangleMathDecorator::TriangleMathDecorator(Triangle* shape)
	: PerimeterAreaDecorator(shape), 
	m_shape(shape)
{
	CountSize();
}

double TriangleMathDecorator::GetPerimeter()
{
	return m_a + m_b + m_c;
}

double TriangleMathDecorator::GetArea()
{
	double semiperimeter = GetPerimeter() / 2;
	return std::sqrt(semiperimeter * (semiperimeter - m_a) * (semiperimeter - m_b) * (semiperimeter - m_c));
}

IShape* TriangleMathDecorator::CopyShape()
{
	return new TriangleMathDecorator(dynamic_cast<Triangle*>(m_shape->CopyShape()));
}

void TriangleMathDecorator::CountSize()
{
	Point point1 = m_shape->GetPoints()->a;
	Point point2 = m_shape->GetPoints()->b;
	Point point3 = m_shape->GetPoints()->c;
	m_a = std::sqrt(std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2));
	m_b = std::sqrt(std::pow(point2.x - point3.x, 2) + std::pow(point2.y - point3.y, 2));
	m_c = std::sqrt(std::pow(point1.x - point3.x, 2) + std::pow(point1.y - point3.y, 2));
}