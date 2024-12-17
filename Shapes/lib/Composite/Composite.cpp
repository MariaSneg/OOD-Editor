#include "Composite.h"
#include "../DrawDecorator/WithFrameDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"
#include "../CommandHandler.h"
#include "../Visitor/IVisitor.h"

void Composite::PrintData(std::ofstream& output)
{
    for (auto child : m_children)
    {
        child->PrintData(output);
    }
}

void Composite::Draw(sf::RenderWindow* window)
{
    for (auto child : m_children)
    {
        child->Draw(window);
    }
}

bool Composite::Select(sf::Vector2f MouseCoords, bool groupSelected)
{
    bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
    if (!shiftPressed)
    {
        m_isSelected = groupSelected;
    }
    for (auto& child : m_children)
    {
        if (child->Select(MouseCoords, m_isSelected))
        {
            m_isSelected = true;
            for (auto& child : m_children)
            {
                child->Select(MouseCoords, m_isSelected);
                if (!child->IsComposite() && dynamic_cast<WithFrameDecorator*>(child) == nullptr) {
                    child = new WithFrameDecorator(child->GetShape());
                }
            }
            break;
        }
        for (auto& child : m_children)
        {
            if (!child->IsComposite() && dynamic_cast<WithoutFrameDecorator*>(child) == nullptr) {
                child = new WithoutFrameDecorator(child->GetShape());
            }
        }
    }
    return m_isSelected;
}

bool Composite::Move(sf::Vector2f MouseCoords, bool groupMoved)
{
    CommandHandler::Save();
    for (auto child : m_children)
    {
        if (child->Move(MouseCoords, groupMoved))
        {
            groupMoved = true;
            for (auto child : m_children)
            {
                child->Move(MouseCoords, groupMoved);
            }
            break;
        }
    }
    return groupMoved;
}

sf::FloatRect Composite::GetBounds()
{
    return sf::FloatRect();
}

IShape* Composite::GetShape()
{
    return this;
}

bool Composite::SetIsMoved(sf::Vector2f MouseCoords, bool groupMoved)
{
    m_isMoved = groupMoved;
    for (auto child : m_children)
    {
        if (child->SetIsMoved(MouseCoords, m_isMoved))
        {
            m_isMoved = true;
            for (auto child : m_children)
            {
                child->SetIsMoved(MouseCoords, m_isMoved);
            }
            break;
        }
    }
    return m_isMoved;
}

void Composite::Add(IDrawDecorator* component) {
    m_children.push_back(component);
}

void Composite::Remove(IDrawDecorator* component) {
    auto index = std::find(m_children.begin(), m_children.end(), component);
    m_children.erase(index);
}

bool Composite::IsComposite() {
    return true;
}

void Composite::Group()
{
    Composite* composite = new Composite();
    for (auto child : m_children)
    {
        if (child->IsSelected())
        {
            
            composite->Add(child);
            Remove(child);
        }
    }
    Add(composite);
}

bool Composite::IsSelected()
{
    for (auto child : m_children)
    {
        if (!child->IsSelected())
        {
            return false;
        }
    }
    return true;
}

std::vector<IDrawDecorator*> Composite::GetChildren()
{
    return m_children;
}

bool Composite::SetFillColor(sf::Vector2f MouseCoords, sf::Color color, bool groupSelected)
{
    CommandHandler::Save();
    for (auto& child : m_children)
    {
        if (child->SetFillColor(MouseCoords, color, false))
        {
            for (auto& child : m_children)
            {
                child->SetFillColor(MouseCoords, color, true);
            }
            return true;
        }
    }
    return false;
}

bool Composite::SetOutline(sf::Vector2f MouseCoords, sf::Color color, int thickness, bool groupSelected)
{
    CommandHandler::Save();
    for (auto& child : m_children)
    {
        if (child->SetOutline(MouseCoords, color, thickness, false))
        {
            for (auto& child : m_children)
            {
                child->SetOutline(MouseCoords, color, thickness, true);
            }
            return true;
        }
    }
    return false;
}

IShape* Composite::CopyShape()
{
    Composite* composite = new Composite();
    for (auto child : m_children)
    {
        composite->Add(new WithoutFrameDecorator(child->CopyShape()));
    }
    return composite;
}

void Composite::Accept(std::shared_ptr<IVisitor> visitor)
{
    visitor->Visit(this);
}

std::string Composite::ToString()
{
    std::string data = "COMPOSITE:\n";
    for (auto child : m_children)
    {
        data += child->ToString();
    }
    data += "END\n";
    return data;
}

sf::Shape* Composite::GetDrawableShape()
{
    return nullptr;
}
