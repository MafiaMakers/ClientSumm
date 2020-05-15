#ifndef STACK
#define STACK
#include <iostream>
namespace Logs {
	class stackElem {
	public:
		std::string value();

		stackElem* getPrev();

		stackElem(stackElem* p, std::string val);

	private:
		std::string data;
		stackElem* previous;
	};


	class stack
	{
	public:
		stack(std::string k, stack* previous = 0);

		stackElem peak();

		bool keyEqual(std::string someKey);

		void setNext(stack* next);

		void add(stackElem val);

		void add(std::string);

		stack* getPrev();

		stack* getNext();
	private:
		std::string key;

		stack* next = 0;
		stack* previous = 0;

		stackElem* last = 0;

	};
}



#endif // !STACK


