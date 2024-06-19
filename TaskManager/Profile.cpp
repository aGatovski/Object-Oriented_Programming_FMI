#include "Profile.h"


Profile::Profile(const MyString& _username, const MyString& _password) : username(_username) , password(_password)
{ }

void Profile::addTask(const MyString& taskName, time_t taskDueDate,const MyString& description)
{
	Vector<size_t> existingTaskWithCorrespondingName = getProfilesIndexesByName(taskName);
	size_t length = existingTaskWithCorrespondingName.getSize();
	for (size_t i = 0; i < length; i++) {
		if (isSameTask(existingTaskWithCorrespondingName[i], taskName, taskDueDate, description)) {
			throw std::runtime_error("Trying to create a task that already exists!");
		}
	}
	tasks.pushBack(Task(taskName, taskDueDate, description));
}

void Profile::updateTaskName(size_t _ID,const MyString& newTaskName)
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks[indexCorrespondingProfile].setName(newTaskName);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::startTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks[indexCorrespondingProfile].setStatus(TaskStatus::IN_PROCESS);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::updateTaskDescription(size_t _ID,const MyString& newDescription)
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks[indexCorrespondingProfile].setDescription(newDescription);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::removeTaskFromDashboard(size_t _ID)
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks.popAt(indexCorrespondingProfile);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::addTaskToDashboard(size_t _ID)
{

}
//oshte trqq gledash tuka
void Profile::deleteTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks.popAt(indexCorrespondingProfile);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::getTask(const MyString& name) const
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByName(name);
		tasks[indexCorrespondingProfile].printTaskInformation();
	}
	catch (const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::getTaskByID(size_t _ID) const
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks[indexCorrespondingProfile].printTaskInformation();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Profile::listTasksByDate(time_t date) const
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

void Profile::listAllTasks() const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		tasks[i].printTaskInformation();
	}
}

void Profile::listCompletedTasks() const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if(tasks[i].getStatus() == TaskStatus::DONE)
		tasks[i].printTaskInformation();
	}
}

void Profile::listDashboardTasks() const
{
	size_t length = dashboard.getSize();
	for (size_t i = 0; i < length; i++)
	{
		dashboard[i].printTaskInformation();
	}
}

void Profile::finishTask(size_t _ID)
{
	try
	{
		size_t indexCorrespondingProfile = getProfileIndexByID(_ID);
		tasks[indexCorrespondingProfile].setStatus(TaskStatus::DONE);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

const MyString& Profile::getPassword() const
{
	return password;
}

const MyString& Profile::getUsername() const
{
	return username;
}

size_t Profile::getProfileIndexByName(const MyString& name) const
{
	Vector<size_t> existingTaskWithCorrespondingName = getProfilesIndexesByName(name);
	size_t length = existingTaskWithCorrespondingName.getSize();
	if (length == 0){
		throw std::logic_error("Trying to get a task with a name that does not exists!");
	}

	size_t minID = SIZE_MAX;
	size_t indexToReturn = 0;

	for (size_t i = 0; i < length; i++){
		if (tasks[existingTaskWithCorrespondingName[i]].getID() < minID) {
			minID = tasks[existingTaskWithCorrespondingName[i]].getID();
			indexToReturn = existingTaskWithCorrespondingName[i];
		}
	}
	return indexToReturn;
}

const Vector<size_t>& Profile::getProfilesIndexesByName(const MyString& name) const
{
	Vector<size_t> valuesToReturn;
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++) {
		if (tasks[i].getName() == name) {
			valuesToReturn.pushBack(i);
		}
	}
	return valuesToReturn;
}

size_t Profile::getProfileIndexByID(size_t ID, const Vector& vector ) const
{
	size_t length = tasks.getSize();
	for (size_t i = 0; i < length; i++) {
		if (tasks[i].getID() == ID) {
			return i;
		}
	}
	throw std::logic_error("Trying access a task at index that does not exists!");
}

bool Profile::isSameTask(size_t indexTask, const MyString& taskName, time_t taskDueDate, const MyString& description)
{
	return (tasks[indexTask].getName() == taskName) 
		&& tasks[indexTask].getDueDate() == taskDueDate 
		&& tasks[indexTask].getDescription()==description;
}

