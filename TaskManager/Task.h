#pragma once
#pragma once
#include <iostream>
#include "MyString.h"
#pragma warning(disable : 4996)
enum class TaskStatus {
	ON_HOLD,
	IN_PROCESS,
	DONE,
	OVERDUE
};

class Task {
public:
	Task() = default;
	Task(const MyString& _name, time_t _dueDate, const MyString& _description);

	void printTaskInformation() const;

	//Get
	const MyString& getName() const;
	const MyString& getDescription() const;
	time_t getDueDate() const;
	size_t getID() const;
	const TaskStatus& getStatus() const;
	const MyString getTaskStatusToPrint() const;

	//Set
	void setName(const MyString& newName);
	void setDescription(const MyString& newDescription);
	void setStatus(const TaskStatus& newStatus);
private:
	size_t ID;
	MyString name;
	time_t dueDate;
	TaskStatus status = TaskStatus::ON_HOLD;
	MyString description;

	static size_t existingTask;
};

bool operator==(const Task& lhs, const Task& rhs);