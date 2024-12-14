#include "CommandHandler.h"
#include "PerimeterAreaDecorator/RectangleDecorator.h"
#include "PerimeterAreaDecorator/CircleDecorator.h"
#include "PerimeterAreaDecorator/TriangleDecorator.h"
#include "DrawDecorator/WithFrameDecorator.h"
#include "DrawDecorator/WithoutFrameDecorator.h"
#include "Shape/Circle.h"
#include "Shape/Rectangle.h"
#include "Shape/Triangle.h"
#include "State/DragAndDropState.h"
#include <map>

std::map<std::string, int> shapeMap
{
    {"CIRCLE", 1},
    {"TRIANGLE", 2},
    {"RECTANGLE", 3}
};

CommandHandler* CommandHandler::m_commandHandler = nullptr;
IState* CommandHandler::m_state = new DragAndDropState();
History CommandHandler::m_history = History();
std::vector<IDrawDecorator*> CommandHandler::m_drawDecorators;
std::vector<IPerimeterAreaDecorator*> CommandHandler::m_mathDecorators;

CommandHandler::CommandHandler(sf::RenderWindow* window, std::ifstream& input, std::ofstream& output)
    : m_window(window), m_input(input), m_output(output)
{
}

CommandHandler* CommandHandler::GetInstance(sf::RenderWindow* window, std::ifstream& input, std::ofstream& output)
{
    if (m_commandHandler == nullptr)
    {
        m_commandHandler = new CommandHandler(window, input, output);
    }
    return m_commandHandler;
}

void CommandHandler::AddShape(IDrawDecorator* shape)
{
    Save();
    m_drawDecorators.push_back(shape);
}

void CommandHandler::SetShapes(std::vector<IDrawDecorator*> shapes)
{
    m_drawDecorators = shapes;
}

std::vector<IDrawDecorator*>& CommandHandler::GetShapes()
{
    return m_drawDecorators;
}

void CommandHandler::ChangeState(IState* state)
{
    m_state = state;
}

std::string CommandHandler::GetStateName()
{
    return typeid(*m_state).name();
}

IState* CommandHandler::GetState()
{
    return m_state;
}

void CommandHandler::ReadShapes() {
    std::string line;
    while (std::getline(m_input, line, ':')) {
        switch (shapeMap.at(line)) {
        case 1: AddCircle(); break;
        case 2: AddTriangle(); break;
        case 3: AddRectangle(); break;
        }
    }
}

void CommandHandler::AddCircle()
{
    Circle* circle = new Circle(m_input);

    CircleMathDecorator* mathDecorator = new CircleMathDecorator(circle);

    m_mathDecorators.push_back(mathDecorator);

    WithoutFrameDecorator* drawDecorator = new WithoutFrameDecorator(circle);
    m_drawDecorators.push_back(drawDecorator);
}

void CommandHandler::AddTriangle()
{
    Triangle* triangle = new Triangle(m_input);

    TriangleMathDecorator* mathDecorator = new TriangleMathDecorator(triangle);

    m_mathDecorators.push_back(mathDecorator);

    WithoutFrameDecorator* drawDecorator = new WithoutFrameDecorator(triangle);
    m_drawDecorators.push_back(drawDecorator);
}

void CommandHandler::AddRectangle()
{
    Rectangle* rectangle = new Rectangle(m_input);

    RectangleMathDecorator* mathDecorator = new RectangleMathDecorator(rectangle);

    m_mathDecorators.push_back(mathDecorator);

    WithoutFrameDecorator* drawDecorator = new WithoutFrameDecorator(rectangle);
    m_drawDecorators.push_back(drawDecorator);
}

void CommandHandler::PrintShapes()
{
    for (auto shape : m_mathDecorators)
    {
        shape->PrintData(m_output);
    }
}

void CommandHandler::DrawShapes()
{
    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            EventHandle(event);
        }

        m_window->clear(sf::Color::White);
        for (auto shape : m_drawDecorators)
        {
            shape->Draw(m_window);
        }
        m_toolbar.DrawToolbar(m_window, GetStateName());
        m_window->display();
    }
}

void CommandHandler::MoveShapes()
{
    for (auto& shape : m_drawDecorators)
    {
        shape->Move(sf::Vector2f(sf::Mouse::getPosition(*m_window)), false);
    }
}

void CommandHandler::UngroupShapes() {
    auto composite = FindSelectedComposite();
    if (composite) {
        UngroupComposite(composite);
    }
}

void CommandHandler::Save()
{
    m_history.AddMemento(Memento(m_drawDecorators));
}

void CommandHandler::Undo()
{
    if (!m_history.IsEmpty())
    {
        Memento memento = m_history.Undo();
        m_drawDecorators = memento.GetState();
    }
}

Composite* CommandHandler::FindSelectedComposite() {
    for (auto it = m_drawDecorators.begin(); it != m_drawDecorators.end(); ++it) {
        if ((*it)->IsSelected() && (*it)->IsComposite()) {
            auto composite = dynamic_cast<Composite*>(*it);
            if (composite) {
                m_drawDecorators.erase(it);
                return composite;
            }
        }
    }
    return nullptr;
}

void CommandHandler::UngroupComposite(Composite* composite) {
    auto children = composite->GetChildren();
    for (auto& child : children) {
        m_drawDecorators.push_back(child);
    }
}

void CommandHandler::GroupShapes() {
    auto composite = CreateCompositeFromSelectedShapes();
    if (composite) {
        m_drawDecorators.push_back(composite);
    }
}

Composite* CommandHandler::CreateCompositeFromSelectedShapes() {
    auto composite = new Composite();
    for (auto it = m_drawDecorators.begin(); it != m_drawDecorators.end();) {
        if ((*it)->IsSelected()) {
            composite->Add(*it);
            it = m_drawDecorators.erase(it);
        }
        else {
            ++it;
        }
    }
    return !composite->GetChildren().empty() ? composite : nullptr;
}


void CommandHandler::EventHandle(sf::Event event)
{
    bool mouseLeftButtonPressed = event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
    bool mouseLeftButtonReleased = event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left;
    bool mouseMoved = event.type == sf::Event::MouseMoved;
    bool ctrlPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
    bool gPressed = event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G;
    bool uPressed = event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U;
    bool zPressed = event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z;

    if (event.type == sf::Event::Closed) {
        m_window->close();
    }
    if (mouseLeftButtonPressed)
    {
        m_state->Select(m_window);
        m_state->SetFillColor(m_window);
        m_state->SetOutline(m_window);
        m_toolbar.Select(sf::Vector2f(sf::Mouse::getPosition(*m_window)), GetStateName());
        isDragging = true;
    }
    if (mouseLeftButtonReleased)
    {
        isDragging = false;
    }
    if (mouseMoved)
    {
        if (isDragging) 
        {
            MoveShapes();
        }
    }
    if (ctrlPressed && gPressed)
    {
        GroupShapes();
    }
    if (ctrlPressed && zPressed)
    {
        Undo();
    }
    if (ctrlPressed && uPressed)
    {
        UngroupShapes();
    }
}
