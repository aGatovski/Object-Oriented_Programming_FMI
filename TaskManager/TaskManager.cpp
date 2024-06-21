#include"TaskManager.h"

//TaskManager::TaskManager(const MyString& _username, const MyString& _password): user(_username,_password)
//{
//}

void TaskManager::addTask(const MyString& taskName, time_t taskDueDate, const MyString& description)
{
	Task newTask(taskName, taskDueDate, description);
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (newTask == tasks[i]) {
			throw std::runtime_error("Trying to create a task that already exists!");
		}
	}
	tasks.pushBack(newTask);
}

void TaskManager::updateTaskName(size_t _ID, const MyString& newTaskName)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].setName(newTaskName);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::startTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].setStatus(TaskStatus::IN_PROCESS);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::updateTaskDescription(size_t _ID, const MyString& newDescription)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].setDescription(newDescription);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
//to do
void TaskManager::removeTaskFromDashboard(size_t _ID)
{
	try
	{
		size_t indexCorrespondingProfile = getTaskIndexByID(_ID);
		tasks.popAt(indexCorrespondingProfile);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
//to do
void TaskManager::addTaskToDashboard(size_t _ID)
{

}
//oshte trqq gledash tuka
void TaskManager::deleteTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks.popAt(indexCorrespondingTask);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::getTask(const MyString& name) const
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByName(name);
		tasks[indexCorrespondingTask].printTaskInformation();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::getTaskByID(size_t _ID) const
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].printTaskInformation();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::listTasksByDate(time_t date) const
{
	/*> list-tasks 2024-03-15
	Task name: Group_project
	Task ID: 1287
	Due date: Fri Mar 15 00:00:00 2024
	Task desc: example desc
	Status: ON HOLD
	Assignee: user567
	*/
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++) {
		if (tasks[i].getDueDate() == date) {
			tasks[i].printTaskInformation();
		}
	}

}

void TaskManager::listAllTasks() const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		tasks[i].printTaskInformation();
	}
}

void TaskManager::listCompletedTasks() const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (tasks[i].getStatus() == TaskStatus::DONE)
			tasks[i].printTaskInformation();
	}
}

void TaskManager::listDashboardTasks() const
{
	size_t length = dashboard.getSize();
	for (size_t i = 0; i < length; i++)
	{
		dashboard[i].printTaskInformation();
	}
}

void TaskManager::finishTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].setStatus(TaskStatus::DONE);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

size_t TaskManager::getTaskIndexByID(size_t ID) const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (tasks[i].getID() == ID) {
			return i;
		}
	}
	throw std::logic_error("Trying to access a task with ID that does not exists!");
}

size_t TaskManager::getTaskIndexByName(const MyString& name) const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (tasks[i].getName() == name) {
			return i;
		}
	}
	throw std::logic_error("Trying to access a task with name that does not exists!");
}


//Collaboration Functions
void TaskManager::addCollaboration(const MyString& collaborationName)
{
	collabs.pushBack(Collaboration(collaborationName), //how do i access the profile name ?);
}

void TaskManager::deleteCollaboration(const MyString& name, const MyString& creator)
{
}

void TaskManager::listCollaborations() const
{
}
