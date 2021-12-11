/*
 * CommandDesignPattern.cpp
 *
 *  Created on: Dec 11, 2021
 *      Author: development
 */

#include "CommandDesignPattern.h"

using namespace CommandDesignPattern;

ICommand::~ICommand() {
}

//AddCommand
AddCommand::AddCommand(float &currentValue, const float valueToAdd) : //
		_currentValue(currentValue), //
		_valueToAdd(valueToAdd) //
{

}

void AddCommand::execute() {
	_currentValue += _valueToAdd;

}

void AddCommand::undo() {
	_currentValue -= _valueToAdd;
}

//SubtractCommand
SubtractCommand::SubtractCommand(float &currentValue, const float valueToAdd) : //
		_currentValue(currentValue), //
		_valueToAdd(valueToAdd) //
{
}

void SubtractCommand::execute() {
	_currentValue -= _valueToAdd;
}

void SubtractCommand::undo() {
	_currentValue += _valueToAdd;
}

//Calculator
Calculator::Calculator(float &currentValue) : //
		_currentValue(currentValue) //

{
}

void Calculator::execute(cType command) {
	command->execute();
	history.push(command);

}

void Calculator::undo() {
	if (history.size() < 1)
		return;
	auto command = history.top();
	command->undo();
	history.pop();
}

