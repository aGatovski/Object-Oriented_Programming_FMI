#include"TaskHolder.h"

//Tasks Functions
void TaskHolder::addTask(const MyString& taskName, time_t taskDueDate, const MyString& description)
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

void TaskHolder::addTask(const Task& newTask)
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		//logika za sravnenie na taskove
		if (newTask.getName() == tasks[i].getName()) {
			throw std::runtime_error("Trying to create a task that already exists!");
		}
	}
	tasks.pushBack(newTask);
}

void TaskHolder::updateTaskName(size_t _ID, const MyString& newTaskName)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		tasks[indexCorrespondingTask].setName(newTaskName);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::startTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		tasks[indexCorrespondingTask].setStatus(TaskStatus::IN_PROCESS);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::updateTaskDescription(size_t _ID, const MyString& newDescription)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		tasks[indexCorrespondingTask].setDescription(newDescription);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::deleteTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		tasks.popAt(indexCorrespondingTask);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


void TaskHolder::getTask(const MyString& name) const
{
	try
	{

		size_t indexCorrespondingTask = getTaskIndexByID(name);
		tasks[indexCorrespondingTask].printTaskInformation();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::listTasksByDate(time_t date) const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++) {
		time_t getDate = tasks[i].getDueDate();
		std::tm* getDateLocalTime = std::localtime(&getDate);
		std::tm* askedDateLocalTime = std::localtime(&date);
		if (std::mktime(getDateLocalTime) == std::mktime(askedDateLocalTime)) {
			
				tasks[i].printTaskInformation();
			
		}
	}
}

//Dashboard Functions
void TaskHolder::removeTaskFromDashboard(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getDashboardTaskIndexByID(_ID);
		dashboard.popAt(indexCorrespondingTask);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::addTaskToDashboard(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		size_t length = dashboard.getSize();
		for (size_t i = 0; i < length; i++)
		{
			if (dashboard[i]->getID() == _ID) {
				throw std::logic_error("This task is already on the dashboard");
			}
		}
		dashboard.pushBack(&tasks[indexCorrespondingTask]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::listDashboardTasks() const
{
	size_t length = dashboard.getSize();
	for (size_t i = 0; i < length; i++)
	{
		dashboard[i]->printTaskInformation();
	}
}

void TaskHolder::loadDashboard()
{
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (!dashboardContainsTask(&tasks[i])) {
			std::tm* taskDueDate = tasks[i].getDueDateFormated();
			std::time_t currentTime = std::mktime(localTime);

			if (std::mktime(taskDueDate) == currentTime) {
				if (tasks[i].getStatus() != TaskStatus::DONE) {
					dashboard.pushBack(&tasks[i]);
				}
			}
		}
	}
}

size_t TaskHolder::getDashboardTaskIndexByID(size_t _ID)
{
	size_t length = dashboard.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (dashboard[i]->getID() == _ID) {
			return i;
		}
	}
	throw;
}

bool TaskHolder::dashboardContainsTask(const Task* task)
{
	size_t length = dashboard.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (dashboard[i]->getID() == task->getID()) {
			return true;
		}
	}
	return false;
}

const Task* TaskHolder::getCollaborationTaskByName(const MyString& collaborationName, const MyString& name) const
{
	try
	{
		size_t indexCorrespondingCollab = getCollaborationIndexByName(collaborationName);
		return collabs[indexCorrespondingCollab]->getTaskByName(name);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

//Universal Functions
void TaskHolder::getTaskByID(size_t _ID) const
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		//size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].printTaskInformation();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::listAllTasks() const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		tasks[i].printTaskInformation();
	}
}

void TaskHolder::listCompletedTasks() const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (tasks[i].getStatus() == TaskStatus::DONE)
			tasks[i].printTaskInformation();
	}
}

void TaskHolder::finishTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		//size_t indexCorrespondingTask = getTaskIndexByID(_ID);
		tasks[indexCorrespondingTask].setStatus(TaskStatus::DONE);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

size_t TaskHolder::getTaskIndexByID(size_t ID) const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (tasks[i].getID() == ID) {
			return i;
		}
	}
	throw std::logic_error("Trying to access a task with ID that does not exist!");
}

//Collaboration functions
void TaskHolder::addCollaboration(Collaboration* newCollaboration)
{
	collabs.pushBack(newCollaboration);
}

void TaskHolder::listCollaborations() const
{
	size_t length = collabs.getSize();
	for (size_t i = 0; i < length; i++)
	{
		std::cout << collabs[i]->getName() << std::endl;
	}
}

void TaskHolder::addUser(const MyString& collaborationName, const MyString& user)
{
	try
	{
		size_t indexCorrespondingCollaboration = getCollaborationIndexByName(collaborationName);
		collabs[indexCorrespondingCollaboration]->addUser(user);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::assignTask(const MyString& collaborationName, const Profile& user, const MyString& taskName, time_t taskDueDate, const MyString& description)
{
	try
	{
		size_t indexCorrespondingCollaboration = getCollaborationIndexByName(collaborationName);
		collabs[indexCorrespondingCollaboration]->assignTask(&user,taskName,taskDueDate,description);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

size_t TaskHolder::getCollaborationIndexByName(const MyString& name) const
{
	size_t length = collabs.getSize();
	for (size_t i = 0; i < length; i++){
		if (collabs[i]->getName() == name) {
			return i;
		}
	}
}

void TaskHolder::deleteCollaboration(const MyString& name,const Profile& assignee)
{
	try
	{
		size_t indexCorrespondingCollaboration = getCollaborationIndexByName(name);
		size_t iDCorrespondingTask = collabs[indexCorrespondingCollaboration]->getTasksIDByAssignee(assignee.getUsername());
		deleteTask(iDCorrespondingTask);
		collabs.popAt(indexCorrespondingCollaboration);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Vector<MyString>& TaskHolder::getCollaborationWorkgroupAtIndex(const MyString& name)
{
	try
	{
		size_t indexCorrespondingCollaboration = getCollaborationIndexByName(name);
		return collabs[indexCorrespondingCollaboration]->getWorkgroup();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
