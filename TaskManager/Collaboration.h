#pragma once
#pragma once
#include <iostream>
#include "Vector.hpp"
#include "MyString.h"
#include "Profile.h"
#include "Task.h"

class Collaboration {
public:
    Collaboration() = default;
    Collaboration(const MyString& name, const MyString& creator);

    // Collaboration functionalities
  /*  void addCollaboration(const MyString& newCollaboration);
    void deleteCollaboration(const MyString& name, const MyString& creator);
    void listCollaborations() const;*/
    void addUser(const MyString& collaborationName, const MyString& _username);
    // void addUser(Profile* user);
    void assignTask(const MyString& collaborationName, const MyString& _username, const MyString& taskName, time_t taskDueDate, const MyString& description);
    void listTasks(const MyString& collaborationName) const;

private:
    size_t ID = 0;
    MyString collaborationName;
    MyString collaborationCreator;
    Vector< Profile*> workgroup;
   /* bool isAssigned = 0;

    Vector<MyString> wg;*/
    /* Vector<MyString> wg;
     Vector<size_t> wgIds;*/

    static size_t existingCollaborations;
};
