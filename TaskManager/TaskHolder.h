#pragma once
#include "MyString.h"
#include "Task.h"
#include "Profile.h"
#include "Collaboration.h"
class TaskHolder {
public:
    TaskHolder() = default;

    // Task-related Functions
    void addTask(const MyString& taskName, time_t taskDueDate, const MyString& description);
    void addTask(const Task& newTask);
    void updateTaskName(size_t _ID, const MyString& newTaskName);
    void startTask(size_t _ID);
    void updateTaskDescription(size_t _ID, const MyString& newDescription);
    void deleteTask(size_t _ID);
    //void deleteTask(const MyString& taskName);
    void getTask(const MyString& name) const;
    void getTaskByID(size_t _ID) const;
    void listTasksByDate(time_t date) const; 
    void listAllTasks() const;
    void listCompletedTasks() const;
    void finishTask(size_t _ID);

    //Dashboard Function
    void removeTaskFromDashboard(size_t _ID);
    void addTaskToDashboard(size_t _ID);
    void listDashboardTasks() const;
    void loadDashboard();
    size_t getDashboardTaskIndexByID(size_t _ID);
    bool dashboardContainsTask(const Task* task);

    //Since dashboard is Vector Task* it does not work like the Vector Task so the template function cannot be applied
    size_t getTaskIndexByID(size_t ID) const;

    //Collaboration functions
    void addCollaboration(Collaboration* newCollaboration);
    void listCollaborations() const;
    void addUser(const MyString& collaborationName, const MyString& user); 
    void assignTask(const MyString& collaborationName, const Profile& user, const MyString& taskName, time_t taskDueDate, const MyString& description);
    void deleteCollaboration(const MyString& name, const Profile& assignee);

    size_t getCollaborationIndexByName(const MyString& name) const;
    Vector<MyString>& getCollaborationWorkgroupAtIndex(const MyString& name);
    const Task* getCollaborationTaskByName(const MyString& collaborationName, const MyString& taskName) const;


    template<typename T>
    size_t getTaskIndexByID(const Vector<T>& elements, size_t ID) const;

    template<typename T>
    size_t getIndexByName(const Vector<T>& elements, const MyString& name);


private:
    Vector<Task> tasks;
    Vector<Collaboration*> collabs;
    Vector<Task*> dashboard;

};

template<typename T>
size_t TaskHolder::getTaskIndexByID(const Vector<T>& elements, size_t ID) const
{
    size_t length = elements.getSize();
    for (size_t i = 0; i < length; i++)
    {
        if (elements[i].getID() == ID) {
            return i;
        }
    }
    throw std::logic_error("Trying to access a task with ID that does not exist!");
}

template<typename T>
 size_t TaskHolder::getIndexByName(const Vector<T>& elements, const MyString& name)
{
    size_t length = elements.getSize();
    for (size_t i = 0; i < length; i++)
    {
        if (elements[i].getName() == name) {
            return i;
        }
    }
    throw std::logic_error("Trying to access a task with name that does not exist!");
}
