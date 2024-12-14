#include "WithFrameDecorator.h"
#include "../Visitor/IVisitor.h"

WithFrameDecorator::WithFrameDecorator(IShape* shape)
    : DrawDecorator(shape)
{
    m_isSelected = true;
}

void WithFrameDecorator::Draw(sf::RenderWindow* window)
{
    sf::FloatRect bounds = GetBounds();

    m_frame.setSize(sf::Vector2f(bounds.width, bounds.height));
    m_frame.setPosition(bounds.left, bounds.top);
    m_frame.setOutlineThickness(5);
    m_frame.setOutlineColor(sf::Color::Red);
    m_frame.setFillColor(sf::Color::Transparent);

    window->draw(m_frame);
    window->draw(*m_drawableShape);
}

IShape* WithFrameDecorator::CopyShape()
{
    return new WithFrameDecorator(m_shape->CopyShape());
}

void WithFrameDecorator::Accept(std::shared_ptr<IVisitor> visitor)
{
    visitor->Visit(this);
}
 