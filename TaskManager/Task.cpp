#include "Task.h"
 size_t Task::existingTask = 0;

Task::Task(const MyString& _name, time_t _dueDate, const MyString& _description) : name(_name), description(_description),
dueDate(_dueDate), ID(existingTask++) 
{ }

void Task::printTaskInformation() const {

	std::cout << "Task ID: " << ID << "\n"
		<< "Name: " << name.c_str() << "\n"
		<< "Due Date: " << std::ctime(&dueDate) // Convert time_t to string
		<< "Status: " << getTaskStatusToPrint().c_str() << "\n"
		<< "Description: " << description.c_str() << std::endl;
}

const MyString& Task::getName() const
{
	return name;
}

const MyString& Task::getDescription() const
{
	return description;
}

time_t Task::getDueDate() const
{
	return dueDate;
}

size_t Task::getID() const
{
	return ID;
}

const TaskStatus& Task::getStatus() const
{
	return status;
}

const MyString Task::getTaskStatusToPrint() const
{
	switch (status) {
	case TaskStatus::ON_HOLD: return MyString("ON_HOLD");
	case TaskStatus::IN_PROCESS: return MyString("IN_PROCESS");
	case TaskStatus::DONE: return MyString("DONE");
	case TaskStatus::OVERDUE: return MyString("OVERDUE");
	default: return MyString("UNKNOWN");
	}
}

void Task::setName(const MyString& newName)
{
	name = newName;
}

void Task::setDescription(const MyString& newDescription)
{
	description = newDescription;
}

void Task::setStatus(const TaskStatus& newStatus)
{
	status = newStatus;
}

//bool operator==(const Task& lhs, const Task& rhs)
//{
//	
//	return (lhs.getName() == rhs.getName())
//		&& (lhs.getDescription() == rhs.getDescription())
//		&& (lhs.getDueDate() == rhs.getDueDate());
//}
