#ifndef SETOUTLINERVISITOR_H
#define SETOUTLINEVISITOR_H

#include "IVisitor.h"
#include "../DrawDecorator/WithFrameDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"

class SetOutlineVisitor : public IVisitor
{
public:
	SetOutlineVisitor(sf::Color color, int thickness, sf::Vector2f mouseCoords, bool groupSelected);
	void Visit(WithFrameDecorator* shape) override;
	void Visit(WithoutFrameDecorator* shape) override;
	void Visit(Composite* shape) override;
private:
	sf::Color m_color;
	int m_thickness;
	sf::Vector2f m_mouseCoords;
	bool m_groupSelected;
};
#endif