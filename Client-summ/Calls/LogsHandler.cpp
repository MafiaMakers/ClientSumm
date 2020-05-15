#include "LogsHandler.h"

using namespace Logs;

Logs::LogsHandler* Logs::lhs = 0;

LogsHandler::LogsHandler() {
	if (lhs == 0) {
		first = 0;
		last = 0;
		lhs = this;
	}
	else {
		throw - 1;
	}
}

std::string Logs::getKey()
{
	std::stringstream ss;
	ss << std::this_thread::get_id();
	return ss.str();
}

void LogsHandler::createThread(std::string thread_id) {
	stack* ns = new stack(thread_id, last);
	if (last != 0) {
		last->setNext(ns);
	}
	else {
		first = ns;
	}
	last = ns;
}

void LogsHandler::add(std::string data, std::string key) {
	stack* s = first;
	while (s != 0) {
		if (s->keyEqual(key)) {
			s->add(data);
			return;
		}
		s = s->getNext();
	}
	createThread(key);
	last->add(data);
}

void LogsHandler::remove(std::string thread_id) {
	stack* s = first;
	while (s != 0) {
		if (s->keyEqual(thread_id)) {
			s->peak();
			return;
		}
		s = s->getNext();
	}
}

void LogsHandler::showThread(std::string thread_id) {
	stack* s = first;
	while (s != 0) {
		if (s->keyEqual(thread_id)) {
			stackElem se = s->peak();
			while (se.getPrev() != 0 || se.value() != "") {
				std::cout << se.value() << std::endl;
				se = s->peak();
			}
			return;
		}
		s = s->getNext();
	}
}

void LogsHandler::showAll() {
	stack* s = first;
	while (s != 0) {
		std::cout << "Next thread" << std::endl;
		stackElem se = s->peak();
		while (se.getPrev() != 0 || se.value() != "") {
			std::cout << se.value() << std::endl;
			se = s->peak();
		}
		std::cout << std::endl;
		s = s->getNext();
	}
}
