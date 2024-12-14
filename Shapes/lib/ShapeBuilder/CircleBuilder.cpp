#include "CircleBuilder.h"
#include <sstream>
#include "../PerimeterAreaDecorator/CircleDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"

CircleBuilder::CircleBuilder(std::istringstream& data)
	:Builder(data)
{
}

void CircleBuilder::ParseString()
{   
    std::string centerStr, radiusStr;

    std::getline(m_data, centerStr, ';');

    size_t pos = centerStr.find(",");
    Point centerCoordinates{ std::stoi(centerStr.substr(3, pos - 2)), std::stoi(centerStr.substr(pos + 1)) };

    std::getline(m_data, radiusStr);
    int radius = std::stoi(radiusStr.substr(3));

	m_circle = new Circle(radius, centerCoordinates.x + radius, centerCoordinates.y + radius);
}

void CircleBuilder::AddDecorators()
{
    CircleMathDecorator* mathDecorator = new CircleMathDecorator(m_circle);

    m_drawDecorator = new WithoutFrameDecorator(m_circle);
}
