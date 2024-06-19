#pragma once
#include <iostream>
#include "MyString.h"
/*Една задача се състои от следните атрибути:
id - уникален номер на задачата; 
name - име на задачата;
due_date (optional) - дата, до която със сигурност трябва да изпълним задачата;
status - може да е ON_HOLD, IN_PROCESS, DONE, OVERDUE;
description - описание на задачата;

*Note: За конкретен due_date не можем да имаме повече от една задача с едно и също име.
*Note: За проекта се позволява използването на библиотеката <ctime> за работата с време и <iomanip> за parse-ването от стринг към дата.
*/

enum class TaskStatus {
	ON_HOLD,
	IN_PROCESS,
	DONE,
	OVERDUE
};

class Task {
public:
	Task(const MyString& _name, time_t _dueDate , const MyString& _description);


	~Task();

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