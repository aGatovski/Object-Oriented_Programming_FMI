#include "Profile.h"

Profile::Profile(const MyString& _username, const MyString& _password) : username(_username) , password(_password)
{ }

void Profile::addTask(MyString& taskName, time_t taskDueDate, MyString& description)
{

}

void Profile::updateTaskName(size_t _ID, MyString& newTaskName)
{
}

void Profile::startTask(size_t _ID)
{
}

void Profile::updateTaskDescription(size_t _ID, MyString& newDescription)
{
}

void Profile::removeTaskFromDashboard(size_t _ID)
{
}

void Profile::addTaskToDashboard(size_t _ID)
{
}

void Profile::deleteTask(size_t _ID)
{
}

void Profile::getTask(const MyString& name) const
{
}

void Profile::getTaskByID(size_t _ID) const
{
}

void Profile::listTasksByDate(time_t date) const
{
}

void Profile::listAllTasks() const
{
}

void Profile::listCompletedTasks() const
{
}

void Profile::listDashboardTasks() const
{
}

void Profile::finishTask(size_t _ID)
{
}

const MyString& Profile::getUsername()
{
    // TODO: insert return statement here
}
