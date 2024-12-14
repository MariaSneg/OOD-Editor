#include "TriangleBuilder.h"
#include <sstream>
#include "../PerimeterAreaDecorator/TriangleDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"

TriangleBuilder::TriangleBuilder(std::istringstream& data)
	:Builder(data)
{
}

void TriangleBuilder::ParseString()
{
    std::string point1Str, point2Str, point3Str;
    std::getline(m_data, point1Str, ';');

    size_t pos = point1Str.find(",");
    Point point1{ std::stoi(point1Str.substr(4, pos - 3)), std::stoi(point1Str.substr(pos + 1)) };

    std::getline(m_data, point2Str, ';');

    pos = point2Str.find(",");
    Point point2{ std::stoi(point2Str.substr(4, pos - 3)), std::stoi(point2Str.substr(pos + 1)) };

    std::getline(m_data, point3Str);

    pos = point3Str.find(",");
    Point point3{ std::stoi(point3Str.substr(4, pos - 3)), std::stoi(point3Str.substr(pos + 1)) };

    m_triangle = new Triangle(point1.x, point1.y, point2.x, point2.y, point3.x, point3.y);
}

void TriangleBuilder::AddDecorators()
{
    TriangleMathDecorator* mathDecorator = new TriangleMathDecorator(m_triangle);

    m_drawDecorator = new WithoutFrameDecorator(m_triangle);
}
