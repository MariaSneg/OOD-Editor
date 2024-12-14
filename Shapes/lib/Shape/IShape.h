#ifndef ISHAPE_H
#define ISHAPE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>

struct Point {
    float x;
    float y;
};

class IShape {
public:
    virtual ~IShape() = default;
    virtual void PrintData(std::ofstream& output) = 0;
    virtual sf::Shape* GetDrawableShape() = 0;
    virtual sf::FloatRect GetBounds() = 0;
    virtual IShape* CopyShape() = 0;
    virtual std::string ToString() = 0;
};

#endif