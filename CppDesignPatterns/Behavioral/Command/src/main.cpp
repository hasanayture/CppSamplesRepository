#include "CommandDesignPattern.h"
#include <iostream>

using std::cout;
using std::make_shared;

using namespace CommandDesignPattern;

int main(int argc, char **argv) {

	float currentValue { 0.0 };
	Calculator calculator(currentValue); //(currentValue);
	auto add5Command = make_shared<AddCommand>(currentValue, 5);
	auto subtract7Command = make_shared<SubtractCommand>(currentValue, 7);

	cout << "Initial value: " << currentValue << std::endl;
	for (int i = 0; i < 5; i++) {
		calculator.execute(add5Command);
		cout << "After add5Command, the value: " << currentValue << std::endl;
	}
	for (int i = 0; i < 5; i++) {
		calculator.undo();
		cout << "After undo, the value: " << currentValue << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		calculator.execute(subtract7Command);
		cout << "After subtract7Command, the value: " << currentValue << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		calculator.undo();
		cout << "After undo, the value: " << currentValue << std::endl;
	}

	std::cout << "\nMAIN END" << std::endl;
	return 0;
}

