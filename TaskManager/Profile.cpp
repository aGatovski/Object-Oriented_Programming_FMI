#include "Profile.h"

Profile::Profile(const MyString& _username, const MyString& _password) : username(_username), password(_password)
{ }

const MyString& Profile::getPassword() const
{
	return password;
}

const MyString& Profile::getUsername() const
{
	return username;
}

