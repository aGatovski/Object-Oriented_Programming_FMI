//#include "CollectionTaskManagers.h"
//
//void CollectionTaskManagers::registerUser(const MyString& _username, const MyString& _password)
//{
//	size_t length = taskManagerUsers.getSize();
//	for (size_t i = 0; i < length; i++) {
//		if (taskManagerUsers[i].user.getUsername() == _username) {
//			//Create a custom exception if u have the time
//			throw std::runtime_error("Trying to register a user that already exists!");
//		}
//	}
//	users.pushBack(Pair<Profile, TaskManager>(Profile(_username, _password), TaskManager()));
//}
//
//size_t CollectionTaskManagers::loginUser(const MyString& _username, const MyString& _password)
//{
//    return size_t();
//}
//
//void CollectionTaskManagers::logout() {
//	//logic for saving everything
//
//}
//
//void CollectionTaskManagers::exit() {
//	logout();
//	std::terminate();
//}
