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
    Profile() = default;
	Profile(const MyString& _username,const MyString& _password);

    // Task-related Functions
    void addTask(const MyString& taskName, time_t taskDueDate, const MyString& description);
    void updateTaskName(size_t _ID, const MyString& newTaskName);
    void startTask(size_t _ID);
    void updateTaskDescription(size_t _ID, const MyString& newDescription);
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
   
    const MyString& getUsername() const;
     const MyString& getPassword() const;
    /*bool isSameTask(const MyString& taskName, time_t taskDueDate, const MyString& description);*/

private:
	MyString username;
	MyString password;
    Vector<Task> tasks;
    //Vector<Collaboration> collabs;
    Vector<Task> dashboard; 
   
    //Helper Functions that need access to tasks
    size_t getProfileIndexByName(const MyString& name) const;
    const Vector<size_t>& getProfilesIndexesByName(const MyString& name) const;
    size_t getProfileIndexByID(size_t ID) const;
    bool isSameTask(size_t indexTask,const MyString& taskName, time_t taskDueDate, const MyString& description);
};
