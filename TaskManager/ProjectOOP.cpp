#include <iostream>
#include "TaskManager.h"
#include "TaskManagerFactory.h"
#include "UserInterface.h"
int main()
{
	TaskManager tm;
	run(tm);

	//if you want to see that the factory works go to TaskManager.cpp and comment the std::exit(0) command
	//than run this code again
	TaskManager tm1;
	TaskManagerLoad(tm1);
	return 0;
}
