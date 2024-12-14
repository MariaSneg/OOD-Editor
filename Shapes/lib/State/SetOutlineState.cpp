#include "SetOutlineState.h"
#include "../Visitor/SetOutlineVisitor.h"

void SetOutlineState::SetOutline(sf::RenderWindow* window)
{
    std::shared_ptr<SetOutlineVisitor> visitor = std::make_shared<SetOutlineVisitor>(m_color, m_thickness, sf::Vector2f(sf::Mouse::getPosition(*window)), false);
    for (auto& shape : m_shapes)
    {
        shape->Accept(visitor);
    }
}

void SetOutlineState::SetColor(sf::Color color)
{
    m_color = color;
}

void SetOutlineState::SetThicness(int thickness)
{
    m_thickness = thickness;
}
