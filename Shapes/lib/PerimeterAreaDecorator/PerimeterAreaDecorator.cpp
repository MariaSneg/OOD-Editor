#include "PerimeterAreaDecorator.h"

PerimeterAreaDecorator::PerimeterAreaDecorator(IShape* shape)
	:m_shape(shape)
{
}

void PerimeterAreaDecorator::PrintData(std::ofstream& output)
{
	m_shape->PrintData(output);
	output << "P=" << GetPerimeter() << "; S=" << GetArea() << std::endl;
}

sf::Shape* PerimeterAreaDecorator::GetDrawableShape()
{
	return m_shape->GetDrawableShape();
}

sf::FloatRect PerimeterAreaDecorator::GetBounds()
{
	return m_shape->GetBounds();
}

double PerimeterAreaDecorator::GetPerimeter()
{
	return 0.0;
}

double PerimeterAreaDecorator::GetArea()
{
	return 0.0;
}

std::string PerimeterAreaDecorator::ToString()
{
	return m_shape->ToString();
}
