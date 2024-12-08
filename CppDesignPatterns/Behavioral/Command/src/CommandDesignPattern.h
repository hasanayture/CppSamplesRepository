#ifndef COMMANDDESIGNPATTERN_H_
#define COMMANDDESIGNPATTERN_H_

#include <stack>
#include <memory>

using std::stack;

namespace CommandDesignPattern {

	class ICommand {
		public:
			virtual void execute() = 0;
			virtual void undo() = 0;
			virtual ~ICommand();
	};

	class AddCommand: public ICommand {
			float &_currentValue;
			float _valueToAdd;
		public:
			AddCommand(float &currentValue, const float valueToAdd);
			void execute() override;
			void undo() override;
	};

	class SubtractCommand: public ICommand {
			float &_currentValue;
			float _valueToAdd;
		public:SubtractCommand(float &currentValue, const float valueToAdd);
			void execute() override;
			void undo() override;
	};

	using CommandType = std::shared_ptr<ICommand>;
	class Calculator {
			float &_currentValue;
			stack<CommandType> history;
		public:
			Calculator(float &currentValue);
			void execute(CommandType command);
			void undo();
	};
}

#endif /* COMMANDDESIGNPATTERN_H_ */
