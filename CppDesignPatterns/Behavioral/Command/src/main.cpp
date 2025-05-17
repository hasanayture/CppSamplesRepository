#include <iostream>
#include <vector>
#include <memory>
#include <stack>

class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~ICommand() = default;
};

class Vehicle {
    int x = 0;
    int y = 0;
public:
    void moveRight() { x++; }
    void moveLeft() { x--; }
    void moveUp() { y++; }
    void moveDown() { y--; }
    void printPosition() { std::cout << "(" << x << ", " << y << ")\n"; }
};

class MoveRightCommand : public ICommand {
    Vehicle& vehicle;
public:
    MoveRightCommand(Vehicle& v) : vehicle(v) {}
    void execute() override { vehicle.moveRight(); }
    void undo() override { vehicle.moveLeft(); }
};

class MoveLeftCommand : public ICommand {
    Vehicle& vehicle;
public:
    MoveLeftCommand(Vehicle& v) : vehicle(v) {}
    void execute() override { vehicle.moveLeft(); }
    void undo() override { vehicle.moveRight(); }
};

class MoveUpCommand : public ICommand {
    Vehicle& vehicle;
public:
    MoveUpCommand(Vehicle& v) : vehicle(v) {}
    void execute() override { vehicle.moveUp(); }
    void undo() override { vehicle.moveDown(); }
};

class MoveDownCommand : public ICommand {
    Vehicle& vehicle;
public:
    MoveDownCommand(Vehicle& v) : vehicle(v) {}
    void execute() override { vehicle.moveDown(); }
    void undo() override { vehicle.moveUp(); }
};

class CommandManager {
    std::vector<std::unique_ptr<ICommand>> commands;
    std::stack<ICommand*> history;
public:
    void addCommand(std::unique_ptr<ICommand> cmd) {
        cmd->execute();
        history.push(cmd.get());
        commands.push_back(std::move(cmd));
    }
    void undoLast() {
        if (!history.empty()) {
            history.top()->undo();
            history.pop();
        }
    }
};

int main() {
    Vehicle v;
    CommandManager manager;

    manager.addCommand(std::make_unique<MoveRightCommand>(v));
    manager.addCommand(std::make_unique<MoveUpCommand>(v));
    manager.addCommand(std::make_unique<MoveUpCommand>(v));
    manager.addCommand(std::make_unique<MoveRightCommand>(v));

    v.printPosition();

    manager.undoLast();
    manager.undoLast();

    v.printPosition();

    return 0;
}
