#include "DrawDecorator.h"
#include "../PerimeterAreaDecorator/CircleDecorator.h"
#include "../PerimeterAreaDecorator/RectangleDecorator.h"
#include "../PerimeterAreaDecorator/TriangleDecorator.h"
#include "../CommandHandler.h"

DrawDecorator::DrawDecorator(IShape* shape)
    :m_shape(shape)
{
    m_drawableShape = shape->GetDrawableShape();
}

void DrawDecorator::PrintData(std::ofstream& output)
{
    m_shape->PrintData(output);
}

bool DrawDecorator::IsComposite()
{
    return false;
}

sf::FloatRect DrawDecorator::GetBounds()
{
    return m_shape->GetBounds();
}

IShape* DrawDecorator::GetShape()
{
    return m_shape;
}

sf::Shape* DrawDecorator::GetDrawableShape()
{
    return m_drawableShape;
}

bool DrawDecorator::SetIsMoved(sf::Vector2f MouseCoords, bool groupMoved)
{
    m_isMoved = false;
    if (groupMoved || this->GetBounds().contains(MouseCoords))
    {
        m_isMoved = true;
        m_lastMousePosition = MouseCoords;
    }
    return m_isMoved;
}

bool DrawDecorator::IsSelected()
{
    return m_isSelected;
}

void DrawDecorator::Draw(sf::RenderWindow* window)
{
    if (m_shape != nullptr)
    {
        window->draw(*m_shape->GetDrawableShape());
    }
}

bool DrawDecorator::SetFillColor(sf::Vector2f MouseCoords, sf::Color color, bool groupSelected)
{
    if (groupSelected || m_drawableShape->getGlobalBounds().contains(MouseCoords))
    {
        if (!groupSelected)
        {
            CommandHandler::Save();
        }
        m_drawableShape->setFillColor(color);
        return true;
    }
    return false;
}

bool DrawDecorator::SetOutline(sf::Vector2f MouseCoords, sf::Color color, int thickness, bool groupSelected)
{
    if (groupSelected || m_drawableShape->getGlobalBounds().contains(MouseCoords))
    {
        if (!groupSelected)
        {
            CommandHandler::Save();
        }
        m_drawableShape->setOutlineColor(color);
        m_drawableShape->setOutlineThickness(thickness);
        return true;
    }
    return false;
}

std::string DrawDecorator::ToString()
{
    return m_shape->ToString();
}

bool DrawDecorator::Select(sf::Vector2f MouseCoords, bool groupSelected)
{
    bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
    if (!shiftPressed)
    {
        m_isSelected = false;
    }
    if (groupSelected || this->GetBounds().contains(MouseCoords))
    {
        m_isSelected = true;
    }
    return m_isSelected;
}

bool DrawDecorator::Move(sf::Vector2f MouseCoords, bool groupMoved)
{
    if (groupMoved || (m_isSelected && m_isMoved && GetBounds().contains(MouseCoords)))
    {
        if (!groupMoved)
        {
            CommandHandler::Save();
        }
        auto position = sf::Vector2f(MouseCoords - m_lastMousePosition);
        m_drawableShape->move(position);
        m_lastMousePosition = MouseCoords;
        return true;
    }
    return false;
         
}
