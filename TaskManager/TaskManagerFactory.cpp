#pragma once
#include"TaskManagerFactory.h"

void TaskManagerLoad(TaskManager& tm) {
   
    std::ifstream ifs(SourceFail::failUsers, std::ios::in | std::ios::binary); 
    if (!ifs.is_open()) {
        throw;
    }

    while (!ifs.eof()) {
        Profile user;
        ifs.read(reinterpret_cast<char*>(&user), sizeof(Profile));

        if (ifs.eof()) {
            break;
        }

        TaskHolder th;
        MyString fileName = user.getUsername() + MyString(".dat");

        std::ifstream ifsTaskHolder(fileName.c_str(), std::ios::binary);
        if (!ifsTaskHolder.is_open()) {
            throw std::runtime_error("Failed to open file for writing!");
        }
        ifsTaskHolder.read(reinterpret_cast<char*>(&th), sizeof(TaskHolder));
        tm.registerUser(user, th);
    }


    std::ifstream ifsCollabs(SourceFail::collabsTM, std::ios::binary);
    if (!ifsCollabs.is_open()) {
        throw;
    }

    while (!ifsCollabs.eof()) {
        Collaboration obj;
        ifs.read(reinterpret_cast<char*>(&obj), sizeof(Profile));
        
        if (ifsCollabs.eof()) {
            break;
        }

        if (obj.getName() == "") {
            break;
        }

        else
        tm.addCollaboration(obj);
    }

}
