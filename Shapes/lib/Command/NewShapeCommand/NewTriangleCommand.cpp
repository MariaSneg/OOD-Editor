#include "NewTriangleCommand.h"
#include "../../Shape/Triangle.h"
#include "../../PerimeterAreaDecorator/TriangleDecorator.h"
#include "../../DrawDecorator/WithoutFrameDecorator.h"
#include "../../CommandHandler.h"

void NewTriangleCommand::Execute()
{
	Triangle* rectangle = new Triangle(200, 200, 250, 100, 300, 200);
	TriangleMathDecorator* mathDecorator = new TriangleMathDecorator(rectangle);
	WithoutFrameDecorator* drawDecorator = new WithoutFrameDecorator(rectangle);
	CommandHandler::AddShape(drawDecorator);
}
