#pragma once
#include"Task.h"
#include "Profile.h"
class CollaborationTask : public Task {
public:
	CollaborationTask() = default;
	CollaborationTask(const MyString& _name, time_t _dueDate, const MyString& _description, const Profile* assignee);

	const MyString& getAssigneeName() const;
private:
	MyString assignee;
	const Profile* assignee2;
	size_t indexAssignee;
};