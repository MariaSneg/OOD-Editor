#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "../DrawDecorator/IDrawDecorator.h"

class Composite : public IDrawDecorator
{
public:
    void Add(IDrawDecorator* component);
    void Remove(IDrawDecorator* component);
    bool IsComposite() override;
    void PrintData(std::ofstream& output) override;
    void Draw(sf::RenderWindow* window) override;
    bool Select(sf::Vector2f MouseCoords, bool groupSelected) override;
    bool Move(sf::Vector2f MouseCoords, bool groupMoved) override;
    sf::FloatRect GetBounds() override;
    IShape* GetShape() override;
    sf::Shape* GetDrawableShape() override;
    bool SetIsMoved(sf::Vector2f MouseCoords, bool groupMoved) override;
    void Group();
    bool IsSelected() override;
    std::vector<IDrawDecorator*> GetChildren();
    bool SetFillColor(sf::Vector2f MouseCoords, sf::Color color, bool groupSelected) override;
    bool SetOutline(sf::Vector2f MouseCoords, sf::Color color, int thickness, bool groupSelected) override;
    IShape* CopyShape() override;
    void Accept(std::shared_ptr<IVisitor> visitor) override;
    std::string ToString() override;
private:
    std::vector<IDrawDecorator*> m_children;
    bool m_isMoved = false;
    bool m_isSelected = false;
};
#endif