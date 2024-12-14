#include "Toolbar.h"
#include "ToolbarIncludes.h"

Toolbar::Toolbar()
{
	InitButtons();
}

void Toolbar::InitButtons()
{
	InitNewShapeButtons();

	InitChangeStateButtons();

	InitFillColorButtons();

	InitSetOutlineColorButtons();

	InitSetThricknessButtons();

	InitWriteToFileButtons();

	InitLoadShapeButtons();
}

void Toolbar::InitSetThricknessButtons()
{
	SetOutlineThicknessButton* setThickness1Button = new SetOutlineThicknessButton(sf::Vector2f(540, 60), 1);
	setThickness1Button->SetCommand(new SetOutlineThicknessCommand(1));
	m_setOutlineButtons.push_back(setThickness1Button);

	SetOutlineThicknessButton* setThickness3Button = new SetOutlineThicknessButton(sf::Vector2f(540, 100), 3);
	setThickness3Button->SetCommand(new SetOutlineThicknessCommand(3));
	m_setOutlineButtons.push_back(setThickness3Button);

	SetOutlineThicknessButton* setThickness5Button = new SetOutlineThicknessButton(sf::Vector2f(541, 140), 5);
	setThickness5Button->SetCommand(new SetOutlineThicknessCommand(5));
	m_setOutlineButtons.push_back(setThickness5Button);

	SetOutlineThicknessButton* setThickness7Button = new SetOutlineThicknessButton(sf::Vector2f(542, 180), 7);
	setThickness7Button->SetCommand(new SetOutlineThicknessCommand(7));
	m_setOutlineButtons.push_back(setThickness7Button);
}

void Toolbar::InitSetOutlineColorButtons()
{
	SetOutlineColorButton* setRedColorOutlineButton = new SetOutlineColorButton(sf::Vector2f(570, 60), sf::Color(255, 59, 59));
	setRedColorOutlineButton->SetCommand(new SetOutlineColorCommand(sf::Color(255, 59, 59)));
	m_setOutlineButtons.push_back(setRedColorOutlineButton);

	SetOutlineColorButton* setOrangeColorOutlineButton = new SetOutlineColorButton(sf::Vector2f(570, 100), sf::Color(255, 144, 59));
	setOrangeColorOutlineButton->SetCommand(new SetOutlineColorCommand(sf::Color(255, 144, 59)));
	m_setOutlineButtons.push_back(setOrangeColorOutlineButton);

	SetOutlineColorButton* setYellowColorOutlineButton = new SetOutlineColorButton(sf::Vector2f(570, 140), sf::Color(255, 249, 58));
	setYellowColorOutlineButton->SetCommand(new SetOutlineColorCommand(sf::Color(255, 249, 58)));
	m_setOutlineButtons.push_back(setYellowColorOutlineButton);

	SetOutlineColorButton* setGreenColorOutlineButton = new SetOutlineColorButton(sf::Vector2f(570, 180), sf::Color(111, 255, 58));
	setGreenColorOutlineButton->SetCommand(new SetOutlineColorCommand(sf::Color(111, 255, 58)));
	m_setOutlineButtons.push_back(setGreenColorOutlineButton);

	SetOutlineColorButton* setBlueColorOutlineButton = new SetOutlineColorButton(sf::Vector2f(570, 220), sf::Color(58, 71, 255));
	setBlueColorOutlineButton->SetCommand(new SetOutlineColorCommand(sf::Color(58, 71, 255)));
	m_setOutlineButtons.push_back(setBlueColorOutlineButton);
}

void Toolbar::InitFillColorButtons()
{
	FillColorButton* fillRedColorButton = new FillColorButton(sf::Vector2f(570, 60), sf::Color(255, 78, 78));
	fillRedColorButton->SetCommand(new FillColorCommand(sf::Color(255, 78, 78)));
	m_fillColorButtons.push_back(fillRedColorButton);

	FillColorButton* fillOrangeColorButton = new FillColorButton(sf::Vector2f(570, 100), sf::Color(255, 209, 80));
	fillOrangeColorButton->SetCommand(new FillColorCommand(sf::Color(255, 209, 80)));
	m_fillColorButtons.push_back(fillOrangeColorButton);

	FillColorButton* fillYellowColorButton = new FillColorButton(sf::Vector2f(570, 140), sf::Color(250, 255, 80));
	fillYellowColorButton->SetCommand(new FillColorCommand(sf::Color(250, 255, 80)));
	m_fillColorButtons.push_back(fillYellowColorButton);

	FillColorButton* fillGreenColorButton = new FillColorButton(sf::Vector2f(570, 180), sf::Color(156, 255, 80));
	fillGreenColorButton->SetCommand(new FillColorCommand(sf::Color(156, 255, 80)));
	m_fillColorButtons.push_back(fillGreenColorButton);

	FillColorButton* fillBlueColorButton = new FillColorButton(sf::Vector2f(570, 220), sf::Color(80, 168, 255));
	fillBlueColorButton->SetCommand(new FillColorCommand(sf::Color(80, 168, 255)));
	m_fillColorButtons.push_back(fillBlueColorButton);

	FillColorButton* fillPurpleColorButton = new FillColorButton(sf::Vector2f(570, 260), sf::Color(197, 80, 255));
	fillPurpleColorButton->SetCommand(new FillColorCommand(sf::Color(197, 80, 255)));
	m_fillColorButtons.push_back(fillPurpleColorButton);

	FillColorButton* fillBlackColorButton = new FillColorButton(sf::Vector2f(570, 300), sf::Color::Black);
	fillBlackColorButton->SetCommand(new FillColorCommand(sf::Color::Black));
	m_fillColorButtons.push_back(fillBlackColorButton);
}

void Toolbar::InitChangeStateButtons()
{
	SetOutlineStateButton* setOutlineStateButton = new SetOutlineStateButton(sf::Vector2f(470, 10));
	setOutlineStateButton->SetCommand(new SetOutlineStateCommand);
	m_buttons.push_back(setOutlineStateButton);

	FillColorStateButton* fillColorStateButton = new FillColorStateButton(sf::Vector2f(500, 10));
	fillColorStateButton->SetCommand(new FillColorStateCommand);
	m_buttons.push_back(fillColorStateButton);

	DragAndDropButton* dragAndDropButton = new DragAndDropButton(sf::Vector2f(530, 10));
	dragAndDropButton->SetCommand(new DragAndDropCommand);
	m_buttons.push_back(dragAndDropButton);
}

void Toolbar::InitNewShapeButtons()
{
	NewCircleButton* newCircleButton = new NewCircleButton(sf::Vector2f(10, 10));
	newCircleButton->SetCommand(new NewCircleCommand);
	m_buttons.push_back(newCircleButton);

	NewRectangleButton* newRectangleButton = new NewRectangleButton(sf::Vector2f(40, 10));
	newRectangleButton->SetCommand(new NewRectangleCommand);
	m_buttons.push_back(newRectangleButton);

	NewTriangleButton* newTriangleButton = new NewTriangleButton(sf::Vector2f(70, 10));
	newTriangleButton->SetCommand(new NewTriangleCommand);
	m_buttons.push_back(newTriangleButton);
}

void Toolbar::InitWriteToFileButtons()
{
	WriteToBinFileButton* writeToBinFileButton = new WriteToBinFileButton(sf::Vector2f(410, 10));
	writeToBinFileButton->SetCommand(new WriteToFileCommand(new WriteToBinFileStrategy("out.bin")));
	m_buttons.push_back(writeToBinFileButton);

	WriteToTextFileButton* writeToTextFileButton = new WriteToTextFileButton(sf::Vector2f(440, 10));
	writeToTextFileButton->SetCommand(new WriteToFileCommand(new WriteToTextFileStrategy("out.txt")));
	m_buttons.push_back(writeToTextFileButton);
}

void Toolbar::InitLoadShapeButtons()
{
	TextLoadShapeButton* textLoadShapeButton = new TextLoadShapeButton(sf::Vector2f(350, 10));
	textLoadShapeButton->SetCommand(new LoadShapeCommand(new TextShapeLoader("out.txt")));
	m_buttons.push_back(textLoadShapeButton);

	BinLoadShapeButton* binLoadShapeButton = new BinLoadShapeButton(sf::Vector2f(380, 10));
	binLoadShapeButton->SetCommand(new LoadShapeCommand(new BinShapeLoader("out.bin")));
	m_buttons.push_back(binLoadShapeButton);
}

void Toolbar::DrawToolbar(sf::RenderWindow* window, std::string state)
{
	sf::RectangleShape panel = sf::RectangleShape(sf::Vector2f(window->getSize().x, 40));
	panel.setFillColor(sf::Color(205, 198, 249));
	window->draw(panel);
	for (auto button : m_buttons)
	{
		button->Draw(window);
	}
	if (state == "class FillColorState")
	{
		sf::RectangleShape fillColorPanel = sf::RectangleShape(sf::Vector2f(40, window->getSize().x));
		fillColorPanel.setPosition(560, 40);
		fillColorPanel.setFillColor(sf::Color(229, 225, 255));
		window->draw(fillColorPanel);
		for (auto button : m_fillColorButtons)
		{
			button->Draw(window);
		}
	}
	else if (state == "class SetOutlineState")
	{
		sf::RectangleShape fillColorPanel = sf::RectangleShape(sf::Vector2f(70, window->getSize().x));
		fillColorPanel.setPosition(530, 40);
		fillColorPanel.setFillColor(sf::Color(229, 225, 255));
		window->draw(fillColorPanel);
		for (auto button : m_setOutlineButtons)
		{
			button->Draw(window);
		}
	}
}

void Toolbar::Select(sf::Vector2f MouseCoords, std::string state)
{
	for (auto button : m_buttons)
	{
		button->Push(MouseCoords);
	}
	if (state == "class FillColorState")
	{
		for (auto button : m_fillColorButtons)
		{
			button->Push(MouseCoords);
		}
	}
	else if (state == "class SetOutlineState")
	{
		for (auto button : m_setOutlineButtons)
		{
			button->Push(MouseCoords);
		}
	}
}
