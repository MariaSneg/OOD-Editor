#include "Rectangle.h"
#include <format>

Rectangle::Rectangle(std::ifstream& input)
{
    CreateRectangle(input);
}

Rectangle::Rectangle(int width, int height, double x, double y)
{
    m_size = Point{ (float)width, (float)height };
    m_position = Point{ (float)x, (float)y };

    m_rectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
    m_rectangle.setPosition(sf::Vector2f(m_position.x, m_position.y));

    m_rectangle.setFillColor(sf::Color::Cyan);
}

void Rectangle::CreateRectangle(std::ifstream& input)
{
    std::string point1Str, point2Str;
    std::getline(input, point1Str, ';');

    size_t pos = point1Str.find(",");
    Point point1{ std::stoi(point1Str.substr(4, pos - 3)), std::stoi(point1Str.substr(pos + 1)) };

    std::getline(input, point2Str);

    pos = point2Str.find(",");
    Point point2{ std::stoi(point2Str.substr(4, pos - 3)), std::stoi(point2Str.substr(pos + 1)) };

    m_size =  Point{ point2.x - point1.x, point2.y - point1.y };
    m_position = Point{ point1.x, point1.y };

    m_rectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
    m_rectangle.setPosition(sf::Vector2f(m_position.x, m_position.y));

    m_rectangle.setFillColor(sf::Color::Cyan);
}

sf::FloatRect Rectangle::GetBounds()
{
    return m_rectangle.getGlobalBounds();
}

sf::Shape* Rectangle::GetDrawableShape()
{
    return &m_rectangle;
}

IShape* Rectangle::CopyShape()
{
    return new Rectangle(*this);
}

std::string Rectangle::ToString()
{
    return std::format("RECTANGLE: P1={},{}; P2={},{}\n", m_rectangle.getPosition().x, m_rectangle.getPosition().y, m_rectangle.getPosition().x + m_size.x, m_rectangle.getPosition().y + m_size.y);
}

Point* Rectangle::GetSize()
{
    return &m_size;
}

void Rectangle::PrintData(std::ofstream& output)
{
    output << RECTANGLE_NAME;
}

