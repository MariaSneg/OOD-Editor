#include "FillColorState.h"
#include "../Visitor/FillColorVisitor.h"

void FillColorState::SetFillColor(sf::RenderWindow* window)
{
    std::shared_ptr<FillColorVisitor> visitor = std::make_shared<FillColorVisitor>(m_color, sf::Vector2f(sf::Mouse::getPosition(*window)), false);
    for (auto& shape : m_shapes)
    {
        shape->Accept(visitor);
    }
}

void FillColorState::SetColor(sf::Color color)
{
    m_color = color;
}
