// ProjectOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TaskManager.h"
#include "TaskManagerFactory.h"
int main()
{
	std::time_t now = std::time(nullptr);
	TaskManager tm;
	tm.registerUser("osama", "binladen");
	tm.registerUser("Borat", "S Golemiq");
	tm.loginUser("osama", "binladen");
	tm.addTask("9/11", now, "bomb");
	tm.listAllTasks();
	std::cout << "-----------------------------------------" << std::endl;
	tm.exit();
	TaskManager tm1;
	TaskManagerLoad(tm1);


	//std::time_t now = std::time(nullptr);
	////MyString 2024-3-7 
	//std::tm* localTime = std::localtime(&now);
	//int year = localTime->tm_year + 1900;
	//int month = localTime->tm_mon + 1;
	//int day = localTime->tm_mday;
	///*std::ofstream ofs("failUsers.dat", std::ios::binary);
	//if (!ofs.is_open()) {
	//	return -1;
	//}*/

	//

	//std::cout << "Current date: " << year << "-" << month << "-" << day << std::endl;
	//TaskManager tm;
	//tm.registerUser("osama", "binladen");
	//tm.registerUser("Borat", "S Golemiq");
	//tm.loginUser("osama", "binladen");
	//tm.addTask("9/11", now, "bomb");
	//tm.listAllTasks();
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.listTasksByDate(MyString("2024-6-23"));
	////shte vurvqt zaedno
	//tm.loadDashboard();
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.listDashboardTasks();
	//tm.exit();
	//
	//
	//std::ifstream ifs("failUsers.dat", std::ios::binary);
	//if (!ifs.is_open()) {
	//	return -1;
	//}
	//Profile obj;
	//Profile obj2;
	//// Read the object directly from the file
	//ifs.read(reinterpret_cast<char*>(&obj), sizeof(Profile));
	//std::cout << obj.getUsername();
	//ifs.read(reinterpret_cast<char*>(&obj2), sizeof(Profile));
	//std::cout << obj2.getPassword()<<std::endl;
	//
	//std::ifstream ifs2("osama.dat", std::ios::binary);
	//if (!ifs.is_open()) {
	//	return -1;
	//}
	//TaskHolder th;
	//ifs2.read(reinterpret_cast<char*>(&th), sizeof(TaskHolder));
	//th.listAllTasks();
	//std::cout << "-----------------------------------------" << std::endl;



	//tm.deleteTask(0);
	////tm.finishTask(0);
	//tm.getTaskByID(0);
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.addCollaboration("imecollab");
	//tm.listCollaborations();
	////tm.assignTask("imecollab", "Borat", "dagolapa", now, "s2ruce");
	//
	//tm.listAllTasks();
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.addUser("imecollab", "Borat");
	//tm.assignTask("imecollab", "Borat", "dagolapa", now, "s2ruce");
	//tm.loginUser("Borat", "S Golemiq");
	//tm.listCollaborations();
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.listTasks("imecollab");
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.listAllTasks();
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.loginUser("osama", "binladen");
	//tm.deleteCollaboration("imecollab");
	//tm.listAllTasks();
	//std::cout << "-----------------------------------------" << std::endl;
	//tm.loginUser("Borat", "S Golemiq");
	//tm.listAllTasks();
}
