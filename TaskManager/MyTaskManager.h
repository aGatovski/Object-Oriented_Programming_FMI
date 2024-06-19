#pragma once
#include <iostream>
#include "Vector.hpp"
#include "MyString.h"
#include "Profile.h"
#include "Task.h"

class TaskManager {
public:
	void registerUser(const MyString& _username,const MyString& _password);
	size_t loginUser(const MyString& _username, const MyString& _password); 
	void logout();
	void exit();
private:
	Vector<Profile> users;
	//Vector<Task> tasks;

};