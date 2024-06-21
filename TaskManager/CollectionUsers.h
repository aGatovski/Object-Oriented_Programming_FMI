#pragma once
#include "Vector.hpp"
#include "Pair.hpp"
#include "MyString.h"
#include "Profile.h"
#include "TaskManager.h"
class CollectionUsers {
public:
	void registerUser(const MyString& _username, const MyString& _password);
	size_t loginUser(const MyString& _username, const MyString& _password);
	void logout();
	void exit();
private:
	Vector<Pair<Profile, TaskManager>> users;
};