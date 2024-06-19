#include "MyTaskManager.h"

void TaskManager::registerUser(const MyString& _username, const MyString& _password)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++){
		if (users[i].getUsername() == _username) {
			//Create a custom exception if u have the time
			throw std::runtime_error("Trying to register a user that already exists!");
		}
	}
	users.pushBack(Profile(_username, _password));
}

size_t TaskManager::loginUser(const MyString& _username, const MyString& _password)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++) {
		if (users[i].getUsername() == _username) {
			if(users[i].getPassword() == _password)
			return i;
		}
	}
	throw std::runtime_error("Trying to log a user that does not exist!");
}

void TaskManager::logout(){
	//logic for saving everything
}

void TaskManager::exit(){
	logout();
	std::terminate();
}
