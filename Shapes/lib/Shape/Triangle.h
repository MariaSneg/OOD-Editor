#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IShape.h"

struct TrianglePoints
{
    Point a;
    Point b;
    Point c;
};

const std::string TRIANGLE_NAME = "TRIANGLE:";

class Triangle : public IShape {

public:
    Triangle(std::ifstream& input);
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    TrianglePoints* GetPoints();
    sf::FloatRect GetBounds();
    void PrintData(std::ofstream& output) override;
    sf::Shape* GetDrawableShape() override;
    IShape* CopyShape() override;
    std::string ToString() override;
private:
    void CreateTriangle(std::ifstream& input);

    TrianglePoints m_points;
    sf::ConvexShape m_triangle;
};
#endif