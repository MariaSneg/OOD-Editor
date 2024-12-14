#include "Circle.h"
#include <format>

Circle::Circle(std::ifstream& input)
{
    CreateCircle(input);
}

Circle::Circle(int radius, double x, double y)
    : m_radius(radius)
{
    m_center = Point{ (float)x - m_radius, (float)y - m_radius };
    m_circle = sf::CircleShape(m_radius);
    m_circle.setPosition(sf::Vector2f(m_center.x, m_center.y));

    m_circle.setFillColor(sf::Color::Magenta);
}

void Circle::CreateCircle(std::ifstream& input)
{
    std::string centerStr, radiusStr;
    std::getline(input, centerStr, ';');

    size_t pos = centerStr.find(",");
    Point centerCoordinats{ std::stoi(centerStr.substr(3, pos - 2)), std::stoi(centerStr.substr(pos + 1)) };

    std::getline(input, radiusStr);
    m_radius = std::stoi(radiusStr.substr(3));

    m_center = Point{ centerCoordinats.x - m_radius, centerCoordinats.y - m_radius };

    m_circle = sf::CircleShape(m_radius);
    m_circle.setPosition(sf::Vector2f(centerCoordinats.x - m_radius, centerCoordinats.y - m_radius));

    m_circle.setFillColor(sf::Color::Magenta);
}

sf::FloatRect Circle::GetBounds()
{
    return m_circle.getGlobalBounds();
}

sf::Shape* Circle::GetDrawableShape()
{
    return &m_circle;
}

IShape* Circle::CopyShape()
{
    return new Circle(*this);
}

std::string Circle::ToString()
{
    return std::format("CIRCLE: C={},{}; P={}\n", m_circle.getPosition().x, m_circle.getPosition().y, m_radius);
}

int Circle::GetRadius()
{
    return m_radius;
}

void Circle::PrintData(std::ofstream& output)
{
    output << CIRCLE_NAME;
}