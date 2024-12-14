#ifndef WITHFRAMEDECORATOR_H
#define WITHFRAMEDECORATOR_H

#include "DrawDecorator.h"

class WithFrameDecorator : public DrawDecorator
{
public:
	WithFrameDecorator(IShape* shape);
	void Draw(sf::RenderWindow* window) override;
	IShape* CopyShape() override;
	void Accept(std::shared_ptr<IVisitor> visitor) override;
private:
	sf::RectangleShape m_frame;
};
#endif
