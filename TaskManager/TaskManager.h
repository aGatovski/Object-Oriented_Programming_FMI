#pragma once
#include "Vector.hpp"
#include "TaskHolder.h"
//#include "Collaboration.h"
class TaskManager {
public:

	//Profile Handling Functions
	void registerUser(const MyString& _username, const MyString& _password);
	void loginUser(const MyString& _username, const MyString& _password);
	void logout();
	void exit();

	//Task Functions
	void addTask(const MyString& taskName, time_t taskDueDate, const MyString& description);
	void updateTaskName(size_t _ID, const MyString& newTaskName);
	void startTask(size_t _ID);
	void updateTaskDescription(size_t _ID, const MyString& newDescription);
	void deleteTask(size_t _ID);
	void getTask(const MyString& name) const;
	void getTaskByID(size_t _ID) const;
	void listTasksByDate(time_t date) const;
	void listAllTasks() const;
	void listCompletedTasks() const;
	void finishTask(size_t _ID);

	//Collaboration Functions
	void addCollaboration(const MyString& newCollaboration);
	void addUserCollaboration(size_t indexUser,Collaboration* newCollaboration);
	void deleteCollaboration(const MyString& name);
	void listCollaborations() const;
	void addUser(const MyString& collaborationName, const MyString& user);
	void assignTask(const MyString& collaborationName, const MyString& _username, const MyString& taskName, time_t taskDueDate, const MyString& description);
	void listTasks(const MyString& collaborationName) const;


	size_t getProfileIndexByName( const MyString& name);
	size_t getCollabIndexByName(const MyString& name);
	


private:
	Vector<Profile> users;
	Vector<TaskHolder> taskHolders;
	Vector<Collaboration> collabHolder;
	int indexLoggedUser = -1;
};
