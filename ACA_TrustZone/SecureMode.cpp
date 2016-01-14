#include "SecureMode.h"
#include "global.h"
#include <chrono>

using namespace std;

SecureMode::SecureMode()
{
	
}

SecureMode::~SecureMode()
{

}

void SecureMode::doWrite()
{
	while (1) {
		std::unique_lock<std::mutex> lk(secureMode);
		scv.wait(lk, [] { return secureStart; });
		secureStart = false;
		
		cout << "This is running in secure mode for 10 sec" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));
		
		secureDone = true;
		lk.unlock();
		scv.notify_one();
		cout << "Exiting secure mode" << endl;
	}
}