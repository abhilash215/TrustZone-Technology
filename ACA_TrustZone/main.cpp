#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <mutex>
#include <condition_variable>
#include "MonitorMode.h"
#include "SecureMode.h"
#include "NormalMode.h"
using namespace std;



std::mutex secureMode;
std::mutex normalMode;
std::condition_variable scv;
std::condition_variable ncv;
bool secureStart = false;
bool secureDone = false;
bool normalStart = false;
bool normalDone = false;

// a global variable
/*
std::list<int>myList;

// a global instance of std::mutex to protect global variable
std::mutex myMutex1;
std::condition_variable con_var1;
std::mutex myMutex2;
std::condition_variable con_var2;
*/
int main(int argc, char *argv[])
{
	
	MonitorMode mm;

	//std::thread t3(&MonitorMode::monitor, MonitorMode());
	std::thread t1(&SecureMode::doWrite, SecureMode());
	std::thread t2(&NormalMode::doWrite, NormalMode());
	mm.smc();

	t1.join();
	t2.join();
	//t3.join();
	return 0;
}