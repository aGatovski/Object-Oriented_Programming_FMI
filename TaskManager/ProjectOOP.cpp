// ProjectOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TaskManager.h"
int main()
{
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	int year = localTime->tm_year + 1900;
	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;

	std::cout << "Current date: " << year << "-" << month << "-" << day << std::endl;
	TaskManager tm;
	tm.registerUser("osama", "binladen");
	tm.registerUser("Borat", "S Golemiq");
	tm.loginUser("osama", "binladen");
	tm.addTask("9/11", now, "bomb");
	tm.finishTask(0);
	tm.getTaskByID(0);

	tm.addCollaboration("imecollab");
	tm.listCollaborations();
	tm.assignTask("imecollab", "Borat", "dagolapa", now, "s2ruce");
	tm.listTasks("imecollab");
	tm.listAllTasks();
	std::cout << "-----------------------------------------" << std::endl;
	tm.addUser("imecollab", "Borat");
	tm.loginUser("Borat", "S Golemiq");
	tm.listCollaborations();
	tm.listTasks("imecollab");
	tm.listAllTasks();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
