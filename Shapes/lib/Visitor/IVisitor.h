#ifndef IVISITOR_H
#define IVISITOR_H

#include <memory>

class WithFrameDecorator;
class WithoutFrameDecorator;
class Composite;

class IVisitor
{
public:
	virtual void Visit(WithFrameDecorator* shape) = 0;
	virtual void Visit(WithoutFrameDecorator* shape) = 0;
	virtual void Visit(Composite* shape) = 0;
};
#endif