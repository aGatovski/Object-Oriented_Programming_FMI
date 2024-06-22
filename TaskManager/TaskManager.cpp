#include "TaskManager.h"


void TaskManager::registerUser(const MyString& _username, const MyString& _password)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++) {
		if (users[i].getUsername() == _username) {
			//Create a custom exception if u have the time
			throw std::runtime_error("Trying to register a user that already exists!");
		}
	}
	users.pushBack(Profile(_username, _password));
	taskHolders.pushBack(TaskHolder());
	std::cout << "Registered successfully!" << std::endl;
}

void TaskManager::loginUser(const MyString& _username, const MyString& _password)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++) {
		if (users[i].getUsername() == _username) {
			if (users[i].getPassword() == _password) {
				indexLoggedUser = i;
				std::cout << "Welcome back, " <<_username << "!" << std::endl;
				return;
			}
				
			throw std::invalid_argument("Incorrect password! Please try again!");
		}
	}
	throw std::runtime_error("Trying to log a user that does not exist!");
}

void TaskManager::logout()
{
	//logic for saving everything
}

void TaskManager::exit()
{
	logout();
	std::terminate();
}

void TaskManager::addTask(const MyString& taskName, time_t taskDueDate, const MyString& description)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].addTask(taskName, taskDueDate, description);
	}
	catch (const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::updateTaskName(size_t _ID, const MyString& newTaskName)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].updateTaskName(_ID, newTaskName);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::startTask(size_t _ID)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].startTask(_ID);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::updateTaskDescription(size_t _ID, const MyString& newDescription)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].updateTaskDescription(_ID,newDescription);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::deleteTask(size_t _ID)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].deleteTask(_ID);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::getTask(const MyString& name) const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].getTask(name);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::getTaskByID(size_t _ID) const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].getTaskByID(_ID);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::listTasksByDate(time_t date) const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].listTasksByDate(date);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::listAllTasks() const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].listAllTasks();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::listCompletedTasks() const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].listCompletedTasks();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::finishTask(size_t _ID)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].finishTask(_ID);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::addCollaboration(const MyString& newCollaboration)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		collabHolder.pushBack(Collaboration(newCollaboration, users[indexLoggedUser]));
		size_t indexCoreespondingCollab = getCollabIndexByName(newCollaboration);
		taskHolders[indexLoggedUser].addCollaboration(&collabHolder[indexCoreespondingCollab]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::addUserCollaboration(size_t indexUser,Collaboration* newCollaboration)
{
	taskHolders[indexUser].addCollaboration(newCollaboration);
}

void TaskManager::listCollaborations() const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].listCollaborations();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::addUser(const MyString& collaborationName, const MyString& user)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		size_t collaborationIndex = getCollabIndexByName(collaborationName);
		taskHolders[indexLoggedUser].addUser(collaborationName, user);
		addUserCollaboration(getProfileIndexByName(user), &collabHolder[collaborationIndex]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::assignTask(const MyString& collaborationName, const MyString& _username, const MyString& taskName, time_t taskDueDate, const MyString& description)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		size_t collaborationIndex = getCollabIndexByName(collaborationName);
		size_t correspondingProfile = getProfileIndexByName(_username);
		taskHolders[indexLoggedUser].assignTask(collaborationName, users[correspondingProfile], taskName, taskDueDate, description);
		taskHolders[correspondingProfile].addTask(taskName, taskDueDate, description);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::listTasks(const MyString& collaborationName) const
{
	size_t length = collabHolder.getSize();
	for (size_t i = 0; i < length; i++)
	{
		collabHolder[i].listTasks(collaborationName);
	}
}

size_t TaskManager::getProfileIndexByName(const MyString& name)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (users[i].getUsername() == name) {
			return i;
		}
	}
	throw std::logic_error("Trying to access a task with name that does not exist!");
}

size_t TaskManager::getCollabIndexByName(const MyString& name)
{
	size_t length = collabHolder.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (collabHolder[i].getName() == name) {
			return i;
		}
	}
	throw std::logic_error("Trying to access a task with name that does not exist!");
}
