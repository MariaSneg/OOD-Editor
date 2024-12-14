#ifndef FILLCOLORVISITOR_H
#define FILLCOLORVISITOR_H

#include "IVisitor.h"
#include "../DrawDecorator/WithFrameDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"

class FillColorVisitor : public IVisitor
{
public:
	FillColorVisitor(sf::Color color, sf::Vector2f mouseCoords, bool groupSelected);
	void Visit(WithFrameDecorator* shape) override;
	void Visit(WithoutFrameDecorator* shape) override;
	void Visit(Composite* shape) override;
private:
	sf::Color m_color;
	sf::Vector2f m_mouseCoords;
	bool m_groupSelected;
};
#endif