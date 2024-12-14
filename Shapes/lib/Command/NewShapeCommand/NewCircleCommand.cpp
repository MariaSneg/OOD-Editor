#include "NewCircleCommand.h"
#include "../../CommandHandler.h"
#include "../../Shape/Circle.h"
#include "../../PerimeterAreaDecorator/CircleDecorator.h"
#include "../../DrawDecorator/WithoutFrameDecorator.h"

void NewCircleCommand::Execute()
{
	Circle* circle = new Circle(50, 250, 250);
	CircleMathDecorator* mathDecorator = new CircleMathDecorator(circle);
	WithoutFrameDecorator* drawDecorator = new WithoutFrameDecorator(circle);
	CommandHandler::AddShape(drawDecorator);
}
