#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

const std::string RECTANGLE_NAME = "RECTANGLE:";

class Rectangle : public IShape {

public:
    Rectangle(std::ifstream& input);
    Rectangle(int width, int height, double x, double y);
    Point* GetSize();
    sf::FloatRect GetBounds();
    void PrintData(std::ofstream& output) override;
    sf::Shape* GetDrawableShape() override;
    IShape* CopyShape() override;
    std::string ToString() override;
private:
    void CreateRectangle(std::ifstream& input);

    Point m_size;
    Point m_position;
    sf::RectangleShape m_rectangle;
};
#endif
