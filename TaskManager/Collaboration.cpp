#include "Collaboration.h"

Collaboration::Collaboration(const MyString& name, const Profile& creator)
    : collaborationName(name) , collaborationCreator(creator.getUsername())
{
    //workgroup.pushBack(creator.getUsername());
}

void Collaboration::printTasks() const
{
}

void Collaboration::addUser(const MyString& user)
{  
    size_t length = workgroup.getSize();
    for (size_t i = 0; i < length; i++)
    {
        if (workgroup[i] == user) {
            throw std::runtime_error("This user is already part of the collaboration!");
        }
    }
    workgroup.pushBack(user);
}


void Collaboration::assignTask(const Profile* assignee, const MyString& taskName, time_t taskDueDate, const MyString& description)
{
    size_t length = collaborationTasks.getSize();
    for (size_t i = 0; i < length; i++)
    {
        if (collaborationTasks[i].getName() == taskName) {
            throw;
        }
    }
    collaborationTasks.pushBack(CollaborationTask(taskName, taskDueDate, description,assignee));
}

void Collaboration::listTasks(const MyString& collaborationName) const
{
    size_t length = collaborationTasks.getSize();
    for (size_t i = 0; i < length; i++)
    {
        collaborationTasks[i].printTaskInformation();
        std::cout << "Assignee: " << collaborationTasks[i].getAssigneeName() << std::endl;
    }
}

const MyString& Collaboration::getName() const
{
    return collaborationName;
}

const MyString& Collaboration::getCollaborationCreator() const
{
    return collaborationCreator;
}

Vector<MyString>& Collaboration::getWorkgroup() 
{
    return workgroup;
}

size_t Collaboration::getTasksIDByAssignee(const MyString& name)
{
    size_t length = collaborationTasks.getSize();
    for (size_t i = 0; i < length; i++)
    {
        if (collaborationTasks[i].getAssigneeName() == name) {
            return collaborationTasks[i].getID();
        }
    }
    throw;
}

Task* Collaboration::getTaskByName(const MyString& taskName) 
{
    size_t length = collaborationTasks.getSize();
    for (size_t i = 0; i < length; i++)
    {
        if (collaborationTasks[i].getName() == taskName) {
            return &collaborationTasks[i];
        }
    }
    return nullptr;
}
