#include "NormalMode.h"
#include "global.h"
#include <chrono>

using namespace std;

NormalMode::NormalMode()
{

}

NormalMode::~NormalMode()
{

}

void NormalMode::doWrite()
{
	while (1) {
		std::unique_lock<std::mutex> lk(normalMode);
		ncv.wait(lk, [] { return normalStart; });
		normalStart = false;

		cout << "This is running in normal mode for 10 sec" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));

		normalDone = true;
		lk.unlock();
		ncv.notify_one();
		cout << "Exiting normal mode" << endl;
	}
}