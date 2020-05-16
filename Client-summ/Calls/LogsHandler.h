#ifndef LOGS_HANDLER
#define LOGS_HANDLER
#include <thread>
#include <sstream>
#include <fstream>
#include "stack.h"
namespace Logs {
	class LogsHandler
	{
	public:
		LogsHandler();
		void add(std::string data, std::string thread_id);

		void remove(std::string thread_id);

		void showThread(std::string thread_id);

		void showAll();

        std::fstream outputLog;
	private:
		void createThread(std::string thread_id);

		stack* first;
		stack* last;
	};

	extern LogsHandler* lhs;

	std::string getKey();
}

#define raise_logs() Logs::lhs->showAll();

#define raise_thread_logs(s) Logs::lhs->showThread(s);

#define __init__() Logs::lhs = new Logs::LogsHandler()

#define call(func, var) 	Logs::lhs->add(#func, Logs::getKey()); \
							*var = func;\
							Logs::lhs->remove(Logs::getKey())

#define call_void(func)		Logs::lhs->add(#func, Logs::getKey()); \
							func;\
							Logs::lhs->remove(Logs::getKey())

#define LOG Logs::lhs->outputLog
#endif
