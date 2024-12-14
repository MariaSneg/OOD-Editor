#include "NewRectangleCommand.h"
#include "../../Shape/Rectangle.h"
#include "../../PerimeterAreaDecorator/RectangleDecorator.h"
#include "../../DrawDecorator/WithoutFrameDecorator.h"
#include "../../CommandHandler.h"

void NewRectangleCommand::Execute()
{
	Rectangle* rectangle = new Rectangle(100, 80, 250, 250);
	RectangleMathDecorator* mathDecorator = new RectangleMathDecorator(rectangle);
	WithoutFrameDecorator* drawDecorator = new WithoutFrameDecorator(rectangle);
	CommandHandler::AddShape(drawDecorator);
}
