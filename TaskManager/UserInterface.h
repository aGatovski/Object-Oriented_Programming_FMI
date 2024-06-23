#pragma once
#include "TaskManager.h"
#include <sstream>
#include <iomanip>
#include<ctime>	
size_t toDigit(const MyString& string);
bool isDate(const MyString& string);
std::time_t parseDate(const MyString& dateString);

void run(TaskManager& tm);