#include "stack.h"

using namespace Logs;

stackElem::stackElem(stackElem* p, std::string val) {
	previous = p;
	data = val;
}

std::string stackElem::value() {
	return data;
}

stackElem* stackElem::getPrev() {
	return previous;
}


stack::stack(std::string k, stack* previous) {
	key = k;
	this->next = 0;
	this->previous = previous;

	last = 0;
}

stackElem stack::peak() {
	if (last != 0) {
		stackElem result = *last;
		stackElem* ll = last;
		last = last->getPrev();
		delete ll;
		return result;
	}
	return stackElem(0, "");
}

void stack::add(stackElem data) {
	stackElem* nl = new stackElem(last, data.value());
	last = nl;
}

bool stack::keyEqual(std::string someKey) {
	return someKey == key;
}

void stack::setNext(stack* next) {
	this->next = next;
}

stack* stack::getNext() {
	return next;
}

stack* stack::getPrev() {
	return previous;
}

void stack::add(std::string data) {
	add(stackElem(last, data));
}