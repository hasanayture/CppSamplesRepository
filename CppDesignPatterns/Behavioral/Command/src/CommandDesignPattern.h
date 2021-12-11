/*
 * CommandDesignPattern.h
 *
 *  Created on: Dec 11, 2021
 *      Author: development
 */

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

	using cType = std::shared_ptr<ICommand>;
	class Calculator {
			float &_currentValue;
			stack<cType> history;
		public:
			Calculator(float &currentValue);
			void execute(cType command);
			void undo();

	};

//	//Command Interface
//	template<typename T>
//	class ICommand {
//		public:
//			virtual void execute() =0;
//			virtual void undo() = 0;
//			virtual ~ICommand();
//
//	};
//
//	template<typename T>
//	class AddCommand: public ICommand<T> {
//			const T &valueToAdd;
//		public:
//			AddCommand(const T &valueToAdd){
//				this->valueToAdd = valueToAdd;
//			}
//			void execute(T &currentValue) override;
//			void undo(T &currentValue) override;
//	};
//
//	template<typename T>
//	class SubructCommand: public ICommand<T> {
//
//	};
//
//	template<typename T>
//	class Calculator {
//			T currentValue { 0 };
//			std::stack<std::shared_ptr<ICommand<T>>> history;
//
//		public:
//
//			Calculator(T &currentValue){
//				this->currentValue = currentValue;
//			};
//			T executeCommand(std::shared_ptr<ICommand<T>>);
//			T undoCommand(std::shared_ptr<ICommand<T>>);
//			T getValue() const;
//	};

}

#endif /* COMMANDDESIGNPATTERN_H_ */
