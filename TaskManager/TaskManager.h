#pragma once
#include "Vector.hpp"
#include"Task.h"
#include "Collaboration.h"
class TaskManager {
public:
    TaskManager()=default;
    //TaskManager(const MyString& _username, const MyString& _password);
   
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

    size_t getTaskIndexByID(size_t ID) const;
    size_t getTaskIndexByName(const MyString& name) const;

    //  Collaboration-related Functions
    void addCollaboration(const MyString& newCollaboration);
    void deleteCollaboration(const MyString& name, const MyString& creator);
    void listCollaborations() const;
private:
	Vector<Task> tasks;
	Vector<Collaboration> collabs;
	Vector<Task> dashboard;
    Profile user;
};