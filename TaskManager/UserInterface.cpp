#include "UserInterface.h"

size_t toDigit(const MyString& string) {
    std::stringstream iss(string.c_str());
    size_t result;
    iss >> result;
    return result;
}

bool isDate(const MyString& string) {
    if (string.getLength() != 10) {
        return false;
    }

    // Check the positions of the hyphens
    if (string[4] != '-' || string[7] != '-') {
        return false;
    }

    // Extract year, month, and day parts
    MyString year = string.substr(0, 4);
    MyString month = string.substr(5, 2);
    MyString day = string.substr(8, 2);

    // Check if year, month, and day are all numbers
    if (!year.isDigit() || !month.isDigit() || !day.isDigit()) {
        return false;
    }

    return true;
}

std::time_t parseDate(const MyString& dateString) {
    std::tm tm = {};
    std::stringstream ss(dateString.c_str());

    ss >> std::get_time(&tm, "%Y-%m-%d");

    if (ss.fail()) {
        throw std::runtime_error("Failed to parse date string");
    }

    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;

    return std::mktime(&tm);
}

void run(TaskManager& tm) {
    char commandBuff[1024];
    char dataBuff[1024];
    while (true) {

        std::cin.getline(commandBuff, 1024, ' ');
        std::cin.getline(dataBuff, 1024);
        std::stringstream line(dataBuff);

        MyString commandLine(commandBuff);

        if (commandLine == ">register") {
            try {
                MyString username;
                MyString password;
                line >> username;
                line >> password;
                tm.registerUser(username, password);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">login") {
            try {
                MyString username;
                MyString password;
                line >> username;
                line >> password;
                tm.loginUser(username, password);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">logout") {
            tm.logout();

        }
        else if (commandLine == ">exit") {
            tm.exit();
            return;

        }
        else if (commandLine == ">add-task") {
            try {
                MyString name;
                MyString due_date;
                MyString description;
                line >> name;
                line >> due_date;
                line >> description;
                tm.addTask(name, parseDate(due_date), description);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">get-task") {
            try {
                MyString input;
                line >> input;
                if (input.isDigit()) {
                    size_t idx = toDigit(input);
                    tm.getTaskByID(idx);
                    continue;
                }
                tm.getTask(input);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">update-task-name") {
            try {
                size_t ID;
                MyString name;
                line >> ID;
                line >> name;
                tm.updateTaskName(ID, name);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">start-task") {
            try {
                size_t id;
                line >> id;
                tm.startTask(id);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">update-task-description") {
            try {
                size_t id;
                MyString description;
                line >> id;
                line >> description;
                tm.updateTaskDescription(id, description);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">delete-task") {
            try {
                size_t id;
                line >> id;
                tm.deleteTask(id);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">list-tasks") {
            try {
                MyString input;
                line >> input;

                if (input.getLength() == 0) {
                    tm.listAllTasks();
                }
                else if (isDate(input)) {
                    tm.listTasksByDate(parseDate(input));
                }
                else {
                    tm.listTasks(input);
                }
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">finish-task") {
            try {
                size_t id;
                line >> id;
                tm.finishTask(id);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">remove-task-from-dashboard") {
            try {
                size_t id;
                line >> id;
                tm.removeTaskFromDashboard(id);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">add-task-to-dashboard") {
            try {
                size_t id;
                line >> id;
                tm.addTaskToDashboard(id);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">list-dashboard") {
            tm.listDashboardTasks();

        }
        else if (commandLine == ">add-collaboration") {
            try {
                MyString collaborationName;
                line >> collaborationName;
                tm.addCollaboration(collaborationName);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">delete-collaboration") {
            try {
                MyString collaborationName;
                line >> collaborationName;
                tm.deleteCollaboration(collaborationName);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">list-collaborations") {
            tm.listCollaborations();

        }
        else if (commandLine == ">add-user") {
            try {
                MyString collaborationName;
                MyString userName;
                line >> collaborationName;
                line >> userName;
                tm.addUser(collaborationName, userName);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else if (commandLine == ">assign-task") {
            try {
                MyString collaborationName;
                MyString username;
                MyString nameTask;
                MyString due_date;
                MyString description;
                line >> collaborationName >> username >> nameTask >> due_date >> description;

                tm.assignTask(collaborationName, username, nameTask, parseDate(due_date), description);
            }
            catch (const std::exception& e) {
                std::cout << e.what();
            }

        }
        else {
            std::cout << "The command you have given does not exist! Please try again!" << std::endl;
        }
    }
}