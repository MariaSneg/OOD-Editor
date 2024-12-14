#include "Triangle.h"
#include <format>

Triangle::Triangle(std::ifstream& input)
{
    CreateTriangle(input);
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    Point point1{ (float)x1, (float)y1 };
    Point point2{ (float)x2, (float)y2 };
    Point point3{ (float)x3, (float)y3 };

    m_points = TrianglePoints{ point1, point2, point3 };

    m_triangle = sf::ConvexShape();
    m_triangle.setPointCount(3);
    m_triangle.setPoint(0, sf::Vector2f(point1.x, point1.y));
    m_triangle.setPoint(1, sf::Vector2f(point2.x, point2.y));
    m_triangle.setPoint(2, sf::Vector2f(point3.x, point3.y));

    m_triangle.setFillColor(sf::Color::Yellow);
}

void Triangle::CreateTriangle(std::ifstream& input)
{
    std::string point1Str, point2Str, point3Str;
    std::getline(input, point1Str, ';');

    size_t pos = point1Str.find(",");
    Point point1{ std::stoi(point1Str.substr(4, pos - 3)), std::stoi(point1Str.substr(pos + 1)) };

    std::getline(input, point2Str, ';');

    pos = point2Str.find(",");
    Point point2{ std::stoi(point2Str.substr(4, pos - 3)), std::stoi(point2Str.substr(pos + 1)) };

    std::getline(input, point3Str);

    pos = point3Str.find(",");
    Point point3{ std::stoi(point3Str.substr(4, pos - 3)), std::stoi(point3Str.substr(pos + 1)) };

    m_points = TrianglePoints{ point1, point2, point3 };

    m_triangle = sf::ConvexShape();
    m_triangle.setPointCount(3);
    m_triangle.setPoint(0, sf::Vector2f(point1.x, point1.y));
    m_triangle.setPoint(1, sf::Vector2f(point2.x, point2.y));
    m_triangle.setPoint(2, sf::Vector2f(point3.x, point3.y));

    m_triangle.setFillColor(sf::Color::Yellow);
}

sf::FloatRect Triangle::GetBounds()
{
    return m_triangle.getGlobalBounds();
}

sf::Shape* Triangle::GetDrawableShape()
{
    return &m_triangle;
}

IShape* Triangle::CopyShape()
{
    return new Triangle(*this);
}

std::string Triangle::ToString()
{
    sf::Vector2f point1 = m_triangle.getPoint(0) + m_triangle.getPosition();
    sf::Vector2f point2 = m_triangle.getPoint(1) + m_triangle.getPosition();
    sf::Vector2f point3 = m_triangle.getPoint(2) + m_triangle.getPosition();
    return std::format("TRIANGLE: P1={},{}; P2={},{}; P3={},{}\n", point1.x, point1.y, point2.x, point2.y, point3.x, point3.y);
}

TrianglePoints* Triangle::GetPoints()
{
    return &m_points;
}

void Triangle::PrintData(std::ofstream& output)
{
    output << TRIANGLE_NAME;
}

