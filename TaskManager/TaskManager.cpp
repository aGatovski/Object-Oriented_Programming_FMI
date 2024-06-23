#include "TaskManager.h"
namespace HPF {
	time_t stringToTime(const MyString& dateStr) {
		std::tm tm = {};
		char delimiter;

		std::stringstream ss(dateStr.c_str());
		ss >> tm.tm_year >> delimiter >> tm.tm_mon >> delimiter >> tm.tm_mday;

		if (ss.fail() || delimiter != '-') {
			throw std::runtime_error("Failed to parse date string");
		}

		// Adjust tm_year and tm_mon as they are counted from 1900 and 0 respectively
		tm.tm_year -= 1900;
		tm.tm_mon -= 1;

		// Convert tm structure to time_t
		time_t time = std::mktime(&tm);
		if (time == -1) {
			throw std::runtime_error("Failed to convert tm structure to time_t");
		}

		return time;
	}
}

using namespace SourceFail;

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

void TaskManager::registerUser(const Profile& newUser, const TaskHolder& th)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++) {
		if (users[i].getUsername() == newUser.getUsername()) {
			//Create a custom exception if u have the time
			throw std::runtime_error("Trying to register a user that already exists!");
		}
	}

	users.pushBack(newUser);
	taskHolders.pushBack(th);
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

				//DashboardLogic
				taskHolders[indexLoggedUser].loadDashboard();
				return;
			}
				
			throw std::invalid_argument("Incorrect password! Please try again!");
		}
	}
	throw std::runtime_error("Trying to log a user that does not exist!");
}

void TaskManager::logout()
{
	
	std::ofstream ofs(failUsers, std::ios::binary | std::ios::_Nocreate /*| std::ios::ate*/);
	if (!ofs.is_open()) {
		throw std::runtime_error("file failed to open!");
	}



	indexLoggedUser = -1;
	ofs.close();
	//logic for saving everything
}

void TaskManager::exit()
{
	//logout();

	std::ofstream ofsProfiles(SourceFail::failUsers, std::ios::_Nocreate | std::ios::binary);
	if (!ofsProfiles.is_open()) {
		throw std::runtime_error("Failed to open profiles.dat for writing!");
	}

	for (size_t i = 0; i < users.getSize(); ++i) {
		ofsProfiles.write(reinterpret_cast<const char*>(&users[i]), sizeof(Profile));
	}

	ofsProfiles.close();

	// Write TaskHolders to binary files
	for (size_t i = 0; i < taskHolders.getSize(); ++i) {
		MyString fileName = users[i].getUsername() + MyString(".dat");
		std::ofstream ofsTaskHolder(fileName.c_str(), std::ios::binary);
		if (!ofsTaskHolder.is_open()) {
			throw std::runtime_error("Failed to open file for writing!");
		}

		ofsTaskHolder.write(reinterpret_cast<const char*>(&taskHolders[i]), sizeof(TaskHolder));
		ofsTaskHolder.close();
	}


	std::ofstream ofsCollabs(SourceFail ::collabsTM, std::ios::binary);
	if (!ofsCollabs.is_open()) {
		throw std::runtime_error("Failed to open profiles.dat for writing!");
	}

	for (size_t i = 0; i < collabHolder.getSize(); ++i) {
		ofsCollabs.write(reinterpret_cast<const char*>(&collabHolder[i]), sizeof(Collaboration));
	}
	ofsCollabs.close();
	//std::terminate();
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

void TaskManager::addTask(const Task& other)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].addTask(other);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::addUserTask(size_t indexUser, const Task& newTask)
{
	try
	{
		taskHolders[indexUser].addTask(newTask);
	}
	catch (const std::exception& e)
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
		std::cout << "Task deleted successfully!" << std::endl;
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

void TaskManager::listTasksByDate(const MyString& date) const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{// Convert MyString date to time_t
		time_t taskDate = HPF::stringToTime(date);
		//i have to convert date to time_t ?
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

void TaskManager::removeTaskFromDashboard(size_t _ID)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].removeTaskFromDashboard(_ID);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::addTaskToDashboard(size_t _ID)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].addTaskToDashboard(_ID);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::listDashboardTasks() const
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].listDashboardTasks();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TaskManager::loadDashboard()
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	try
	{
		taskHolders[indexLoggedUser].loadDashboard();
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

void TaskManager::addCollaboration(const Collaboration& newCollaboration)
{
	
	try
	{
		collabHolder.pushBack(newCollaboration);
		size_t indexCoreespondingCollab = getCollabIndexByName(newCollaboration.getName());
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

void TaskManager::deleteCollaboration(const MyString& name)
{
	if (indexLoggedUser < 0) {
		throw std::runtime_error("No Logged User!");
	}
	size_t indexCoreespondingCollab = getCollabIndexByName(name);
	if (collabHolder[indexCoreespondingCollab].getCollaborationCreator() != users[indexLoggedUser].getUsername()) {
		throw std::logic_error("Only the collaboration creator can alter the collaboration!");
	}

	try
	{
		Vector<MyString> workgroup = taskHolders[indexCoreespondingCollab].getCollaborationWorkgroupAtIndex(name);
		size_t length = workgroup.getSize();
		for (size_t i = 0; i < length; i++)
		{
			size_t indexCorrespondingUSer = getProfileIndexByName(workgroup[i]);
			taskHolders[indexCorrespondingUSer].deleteCollaboration(name,users[indexCorrespondingUSer]);
		}
		
		collabHolder.popAt(indexCoreespondingCollab);
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
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

		size_t taskIdx = taskHolders[correspondingProfile].getCollaborationIndexByName(collaborationName);

		taskHolders[correspondingProfile].addTask(*taskHolders[correspondingProfile]
			.getCollaborationTaskByName(collaborationName,taskName));
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
