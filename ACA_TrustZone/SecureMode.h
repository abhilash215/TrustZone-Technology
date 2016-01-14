#include <iostream>
#include <condition_variable>

extern std::condition_variable scv;
extern bool secureStart;
extern bool secureDone;

class SecureMode
{
public:
	SecureMode();
	~SecureMode();

	void doWrite();
};


