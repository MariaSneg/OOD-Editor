#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"
#include <string>

const std::string CIRCLE_NAME = "CIRCLE:";

class Circle : public IShape {

public:
    Circle(std::ifstream& input);
    Circle(int radius, double x, double y);
    int GetRadius();
    sf::FloatRect GetBounds();
    void PrintData(std::ofstream& output) override;
    sf::Shape* GetDrawableShape() override;
    IShape* CopyShape() override;
    std::string ToString() override;
private:
    void CreateCircle(std::ifstream& input);

    sf::CircleShape m_circle;
    Point m_center;
    int m_radius;
};
#endif 

