#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <mutex>

using namespace std;

// a global instance of std::mutex for secureMode
extern std::mutex secureMode;
//a global instace of std::mutex for normalMode
extern std::mutex normalMode;

