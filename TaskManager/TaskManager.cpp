#include <iostream>
#include <ctime>
#include<iomanip>
#include "Task.h"

int main()
{
    std::tm dueDateInfo = {};
    dueDateInfo.tm_year = 2024 - 1900; // Year since 1900
    dueDateInfo.tm_mon = 7 - 1;        // Month (0-11)
    dueDateInfo.tm_mday = 24;          // Day of the month
    time_t dueDate = std::mktime(&dueDateInfo);

    // Create a task
    Task t(MyString("Task Name"), dueDate, MyString("Task Description"));

    // Print task information
    t.printTaskInformation();

    return 0;
}

