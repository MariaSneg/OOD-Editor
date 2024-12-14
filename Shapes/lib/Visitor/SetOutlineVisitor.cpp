#include "SetOutlineVisitor.h"
#include "../DrawDecorator/WithFrameDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"
#include "../Composite/Composite.h"

SetOutlineVisitor::SetOutlineVisitor(sf::Color color, int thickness, sf::Vector2f mouseCoords, bool groupSelected)
	:m_color(color),
	m_mouseCoords(mouseCoords),
	m_groupSelected(groupSelected),
	m_thickness(thickness)
{
}

void SetOutlineVisitor::Visit(WithFrameDecorator* shape)
{
	shape->SetOutline(m_mouseCoords, m_color, m_thickness, m_groupSelected);
}

void SetOutlineVisitor::Visit(WithoutFrameDecorator* shape)
{
	shape->SetOutline(m_mouseCoords, m_color, m_thickness, m_groupSelected);
}

void SetOutlineVisitor::Visit(Composite* shape)
{
	shape->SetOutline(m_mouseCoords, m_color, m_thickness, m_groupSelected);
}
