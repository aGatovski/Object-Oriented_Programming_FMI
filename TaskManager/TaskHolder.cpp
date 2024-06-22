#include"TaskHolder.h"

TaskHolder::TaskHolder(Profile& profile) : user(&profile)
{
	loadDashboardTasks();
}

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

void TaskHolder::updateTaskName(size_t _ID, const MyString& newTaskName)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		/*size_t indexCorrespondingTask = getTaskIndexByID(_ID);*/
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
		//size_t indexCorrespondingTask = getTaskIndexByID(_ID);
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
		//size_t indexCorrespondingTask = getTaskIndexByID(_ID);
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
		//size_t indexCorrespondingTask = getTaskIndexByID(_ID);
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

		size_t indexCorrespondingTask = (name);
		tasks[indexCorrespondingTask].printTaskInformation();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::listTasksByDate(time_t date) const
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
//Dashboard Functions
void TaskHolder::removeTaskFromDashboard(size_t _ID)
{
	try
	{
		size_t indexCorrespondingTask = getTaskIndexByID(dashboard, _ID);
		//size_t indexCorrespondingProfile = getTaskIndexByID(_ID);
		tasks.popAt(indexCorrespondingTask);
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
		size_t indexCorrespondingTask = getTaskIndexByID(tasks, _ID);
		//size_t indexCorrespondingProfile = getTaskIndexByID(_ID);
		dashboard.pushBack(tasks[indexCorrespondingTask]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskHolder::listDashboardTasks() const
{
	//loadDashboardTasks();

	//wtora logica che da ne maham const dokato ne izmislq nesh drugo
	std::time_t currentTime = std::time(nullptr);
	listTasksByDate(currentTime);

	size_t length = dashboard.getSize();
	for (size_t i = 0; i < length; i++)
	{
		dashboard[i].printTaskInformation();
	}
}

void TaskHolder::loadDashboardTasks()
{
	// Get current time as std::time_t
	std::time_t currentTime = std::time(nullptr);

	// Iterate over tasks using an index-based loop
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; ++i) {
		//Task& task = tasks[i]; // Get reference to current task

		// Compare task's due date with current time
		if (tasks[i].getDueDate() == currentTime) {
			dashboard.pushBack(tasks[i]);
		}
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

//Helping Function For identifying tasks at certain positions
//size_t TaskManager::getTaskIndexByID(size_t ID ) const
//{
//	size_t length = tasks.getSize();
//	for (size_t i = 0; i < length; i++)
//	{
//		if (tasks[i].getID() == ID) {
//			return i;
//		}
//	}
//	throw std::logic_error("Trying to access a task with ID that does not exists!");
//}
//
//size_t TaskHolder::getTaskIndexByName(const MyString& name) const
//{
//	size_t length = tasks.getSize();
//	for (size_t i = 0; i < length; i++)
//	{
//		if (tasks[i].getName() == name) {
//			return i;
//		}
//	}
//	throw std::logic_error("Trying to access a task with name that does not exists!");
//}
//
//
////Collaboration Functions
//void TaskHolder::addCollaboration(const MyString& collaborationName)
//{
//	//logica dali veche ne sushstestvuva
//	collabs.pushBack(Collaboration(collaborationName, user->getUsername()));
//}
//
//void TaskHolder::addCollaboration(const Collaboration& newCollaboration)
//{
//	collabs.pushBack(newCollaboration);
//}
//
//void TaskHolder::deleteCollaboration(const MyString& name)
//{
//	size_t length = collabs.getSize();
//	for (size_t i = 0; i < length; i++)
//	{
//		if (collabs[i].getName() == name) {
//			collabs.popAt(i);
//			return;
//		}
//	}
//	throw std::logic_error("No instance of a collaboration exist with this name!");
//}
//
//void TaskHolder::listCollaborations() const
//{
//	size_t length = collabs.getSize();
//	for (size_t i = 0; i < length; i++)
//	{
//		std::cout << collabs[i].getName() << std::endl;
//	}
//}
//
//void TaskHolder::addUser(const MyString& collaborationName, const Profile& user)
//{
//	try
//	{
//		size_t indexCorrespondingTask = getIndexByName(collabs, collaborationName);
//		//size_t indexCorrespondingTask = getTaskIndexByID(_ID);
//		collabs[indexCorrespondingTask].addUser(&user);
//	}
//	catch (const std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//}
//
//void TaskHolder::assignTask(const MyString& collaborationName, const MyString& _username, const MyString& taskName, time_t taskDueDate, const MyString& description)
//{
//}
//
//void TaskHolder::listTasks(const MyString& collaborationName) const
//{
//	size_t length = collabs.getSize();
//	for (size_t i = 0; i < length; i++)
//	{
//		if (collabs[i].getName() == collaborationName) {
//			collabs[i].printTasks();
//		}
//	}
//
//
//	//Tasks for collab:
//	//Task name : Group_project
//	//	Task ID : 1287
//	//	Due date : Fri Mar 15 00 : 00 : 00 2024
//	//	Task desc : example desc
//	//	Status : ON HOLD
//	//	Assignee : user567
//
//}
//
//
