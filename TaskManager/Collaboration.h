#pragma once
#include <iostream>
#include "Vector.hpp"
#include "MyString.h"
#include "Profile.h"
#include "CollaborationTask.h"
class Collaboration {
public:
    Collaboration() = default;
    Collaboration(const MyString& name, const Profile& creator);


    void printTasks() const;
    void addUser(const MyString& user);
    void assignTask(const Profile* assignee, const MyString& taskName, time_t taskDueDate, const MyString& description);
    void listTasks(const MyString& collaborationName) const;

    const MyString& getName() const;
    const MyString& getCollaborationCreator() const;
     Vector<MyString>& getWorkgroup();
     size_t getTasksIDByAssignee(const MyString& name);

     Task* getTaskByName(const MyString& taskName);

private:
    size_t ID = 0;
    MyString collaborationName;
    MyString collaborationCreator;
    Vector <CollaborationTask> collaborationTasks;
    Vector<MyString> workgroup;

    static size_t existingCollaborations;
};
