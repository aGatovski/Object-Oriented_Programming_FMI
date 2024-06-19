#pragma once
#include<iostream>
#include<ctime>
#include "MyString.h"
#include "Collaboration.h"

namespace PROFILE_CONSTANTS {
	constexpr char fileUsers[] = "fileUsers.dat";
}

class Profile {
public:
	Profile(const MyString& _username,const MyString& _password);

    // Task-related Functions
    void addTask(MyString& taskName, time_t taskDueDate, MyString& description);
    void updateTaskName(size_t _ID, MyString& newTaskName);
    void startTask(size_t _ID);
    void updateTaskDescription(size_t _ID, MyString& newDescription);
    void removeTaskFromDashboard(size_t _ID);
    void addTaskToDashboard(size_t _ID);
    void deleteTask(size_t _ID);
    void getTask(const MyString& name) const;
    void getTaskByID(size_t _ID) const;
    void listTasksByDate(time_t date) const;
    void listAllTasks() const;
    void listCompletedTasks() const;
    void listDashboardTasks() const;
    void finishTask(size_t _ID);
   
    const MyString& getUsername();
private:
	MyString username;
	MyString password;
    Vector<Task> tasks;
    Vector<Collaboration> collabs;

    Vector<Task> dashboard; 
   
};