#include "CollaborationTask.h"

CollaborationTask::CollaborationTask
(const MyString& _name, time_t _dueDate, const MyString& _description, const Profile* assignee) 
	: Task(_name,_dueDate,_description), assignee2(assignee){ }

const MyString& CollaborationTask::getAssigneeName() const
{
	return assignee2->getUsername();
}
