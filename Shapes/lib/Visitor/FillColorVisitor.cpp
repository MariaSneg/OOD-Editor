#include "FillColorVisitor.h"
#include "../DrawDecorator/WithFrameDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"
#include "../Composite/Composite.h"

FillColorVisitor::FillColorVisitor(sf::Color color, sf::Vector2f mouseCoords, bool groupSelected)
	:m_color(color), 
	m_mouseCoords(mouseCoords), 
	m_groupSelected(groupSelected)
{
}

void FillColorVisitor::Visit(WithFrameDecorator* shape)
{
	shape->SetFillColor(m_mouseCoords, m_color, m_groupSelected);
}

void FillColorVisitor::Visit(WithoutFrameDecorator* shape)
{
	shape->SetFillColor(m_mouseCoords, m_color, m_groupSelected);
}

void FillColorVisitor::Visit(Composite* shape)
{
	shape->SetFillColor(m_mouseCoords, m_color, m_groupSelected);
}
