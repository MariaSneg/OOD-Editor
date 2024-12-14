#include "WithoutFrameDecorator.h"
#include "../Visitor/IVisitor.h"

WithoutFrameDecorator::WithoutFrameDecorator(IShape* shape)
	: DrawDecorator(shape)
{
	m_isSelected = false;
}

IShape* WithoutFrameDecorator::CopyShape()
{
	return new WithoutFrameDecorator(m_shape->CopyShape());
}

void WithoutFrameDecorator::Accept(std::shared_ptr<IVisitor> visitor)
{
	visitor->Visit(this);
}
