#pragma once

#include <iostream>
#include <thread>
#include <mutex>

extern std::mutex secureMode;
extern std::mutex normalMode;
extern std::condition_variable scv;
extern std::condition_variable ncv;
extern bool secureStart;
extern bool normalStart;
extern bool secureDone;
extern bool normalDone;

class MonitorMode {

public:
	MonitorMode();
	~MonitorMode();
	void smc();
	void startModes();
};