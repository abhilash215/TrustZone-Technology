#include "MonitorMode.h"
#include "SecureMode.h"
#include "NormalMode.h"
#include  "global.h"
#include <thread>


using namespace std;

MonitorMode::MonitorMode() {
}
MonitorMode::~MonitorMode() {

}
void MonitorMode::startModes() {
	
	std::thread t1(&SecureMode::doWrite, SecureMode());
	std::thread t2(&NormalMode::doWrite, NormalMode());


	t1.join();
	t2.join();

	return;
}
void MonitorMode::smc() 
{

	int input = 0;
	//Check for the input and release the lock
	//Keep monitoring the lock once free lock it again

	//startModes();
	while (1) {
		cout << "Enter 1 : Secure mode\n 2 : Normal Mode  \n 0: Exit program " << endl;
		cin >> input;
		if (input == 1) {
			//Secure lock
			{
				std::unique_lock<std::mutex> slock(secureMode);
				secureStart = true;
			}
			scv.notify_one();
			{
				std::unique_lock<std::mutex> slock(secureMode);
				scv.wait(slock, [] {return secureDone; });
			}
			secureDone = false;
		}
		else if (input == 2)			
		{
			//Normal lock
			{
				std::unique_lock<std::mutex> nlock(normalMode);
				normalStart = true;
			}
			ncv.notify_one();
			{
				std::unique_lock<std::mutex> nlock(normalMode);
				ncv.wait(nlock, [] {return normalDone; });
			}
			normalDone = false;
		}
		else
		{
			
			exit(0);
		}
	}
}
