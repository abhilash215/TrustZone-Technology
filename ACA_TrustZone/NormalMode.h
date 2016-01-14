#include <iostream>
#include <condition_variable>

extern std::condition_variable ncv;
extern bool normalStart;
extern bool normalDone;

class NormalMode
{
public:
	NormalMode();
	~NormalMode();

	void doWrite();
};
