#pragma once
#include "TaskManager.h"

void TaskManagerLoad( TaskManager& tm) {
    std::ifstream ifs("failUsers.dat",std::ios::_Nocreate | std::ios::binary);
    if (!ifs.is_open()) {
        throw;
    }

    while (!ifs.eof()) {
        Profile obj;
        ifs.read(reinterpret_cast<char*>(&obj), sizeof(Profile));
        // if (ifs.gcount() != sizeof(Profile)) {
        if (ifs.eof()) {
            break; // If failed to read entire Profile, break out of loop
        }
        TaskHolder th;

        MyString fileName(obj.getUsername());
        MyString dat(".dat");
        fileName += dat;
        std::cout << fileName.c_str();
        std::ifstream ifsTaskHolder(fileName.c_str(), std::ios::binary);
        if (!ifsTaskHolder.is_open()) {
            throw std::runtime_error("Failed to open file for writing!");
        }
        ifsTaskHolder.read(reinterpret_cast<char*>(&th), sizeof(TaskHolder));
        th.listAllTasks();
        tm.registerUser(obj,th);
    }
    std::ifstream ifsCollabs(SourceFail::collabsTM, std::ios::binary);
    if (!ifsCollabs.is_open()) {
        throw;
    }
    while (!ifsCollabs.eof()) {
        Collaboration obj;
        ifs.read(reinterpret_cast<char*>(&obj), sizeof(Profile));
        // if (ifs.gcount() != sizeof(Profile)) {
        if (ifsCollabs.eof()) {
            break; // If failed to read entire Profile, break out of loop
        }
        if (obj.getName() == "") {
            break;
        }
        else
        tm.addCollaboration(obj);
    }

}