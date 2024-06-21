#pragma once
#include"MyString.h"
#include "TaskManager.h"
class Profile {
public:
	Profile() = default;
	Profile(const MyString& _username, const MyString& _password);

	const MyString& getUsername() const;
	const MyString& getPassword() const;

private:
	MyString username;
	MyString password;
	//TaskManager* taskManager;
};