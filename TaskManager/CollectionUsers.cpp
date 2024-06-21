#include "CollectionUsers.h"

void CollectionUsers::registerUser(const MyString& _username, const MyString& _password)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++) {
		if (users[i].getFirst().getUsername() == _username) {
			//Create a custom exception if u have the time
			throw std::runtime_error("Trying to register a user that already exists!");
		}
	}
	users.pushBack( Pair<Profile,TaskManager>( Profile(_username, _password),TaskManager()));
}

size_t CollectionUsers::loginUser(const MyString& _username, const MyString& _password)
{
	size_t length = users.getSize();
	for (size_t i = 0; i < length; i++) {
		if (users[i].getFirst().getUsername() == _username) {
			if (users[i].getFirst().getPassword() == _password)
				return i;
			throw std::invalid_argument("Incorrect password! Please try again!");	
		}
	}
	throw std::runtime_error("Trying to log a user that does not exist!");
}

void CollectionUsers::logout() {
	//logic for saving everything
	
}

void CollectionUsers::exit() {
	logout();
	std::terminate();
}
