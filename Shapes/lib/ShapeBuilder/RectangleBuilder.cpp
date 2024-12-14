#include "RectangleBuilder.h"
#include <sstream>
#include "../PerimeterAreaDecorator/RectangleDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"

RectangleBuilder::RectangleBuilder(std::istringstream& data)
	:Builder(data)
{
}

void RectangleBuilder::ParseString()
{
    std::string point1Str, point2Str;
    std::getline(m_data, point1Str, ';');

    size_t pos = point1Str.find(",");
    Point point1{ std::stoi(point1Str.substr(4, pos - 3)), std::stoi(point1Str.substr(pos + 1)) };

    std::getline(m_data, point2Str);

    pos = point2Str.find(",");
    Point point2{ std::stoi(point2Str.substr(4, pos - 3)), std::stoi(point2Str.substr(pos + 1)) };

    Point size = Point{ point2.x - point1.x, point2.y - point1.y };

    m_rectangle = new Rectangle(size.x, size.y, point1.x, point1.y);
}

void RectangleBuilder::AddDecorators()
{
    RectangleMathDecorator* mathDecorator = new RectangleMathDecorator(m_rectangle);

    m_drawDecorator = new WithoutFrameDecorator(m_rectangle);
}
