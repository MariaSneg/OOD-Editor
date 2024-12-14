#ifndef WITHOUTFRAMEDECORATOR_H
#define WITHOUTFRAMEDECORATOR_H

#include "DrawDecorator.h"

class WithoutFrameDecorator : public DrawDecorator
{
public:
	WithoutFrameDecorator(IShape* shape);
	IShape* CopyShape() override;
	void Accept(std::shared_ptr<IVisitor> visitor) override;
private:
};

#endif