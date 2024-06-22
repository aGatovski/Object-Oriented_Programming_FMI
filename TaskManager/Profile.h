#pragma once
#include"MyString.h"
class Profile {
public:
	Profile() = default;  // Default Constructor
	Profile(const MyString& _username, const MyString& _password);

	const MyString& getUsername() const;
	const MyString& getPassword() const;

private:
	MyString username;
	MyString password;
};