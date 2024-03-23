
#include <iostream>
#include <sstream>
#include <fstream>
#pragma warning(disable : 4996)


namespace GlobalConstants {
	constexpr unsigned FIELD_MAX_SIZE = 50;
	constexpr unsigned MAX_COLUMN_COUNT = 15;
	constexpr unsigned MAX_ROW_COUNT = 100;
	constexpr char OPEN_BRACKET = '<';
	constexpr char CLOSE_BRACKET = '>';

	constexpr unsigned MAX_FILENAME_SIZE = 50;
	constexpr unsigned BUFFER_SIZE = 1024;
};


bool flagIsInText = false;

struct Cell {
	char cell[GlobalConstants::FIELD_MAX_SIZE];// cells with maximum 50 charachters 
	bool isHeader = false;

	Cell() {
		// Initialize cell with an empty string
		cell[0] = '\0';
	}

};

struct Row
{
	Cell cells[GlobalConstants::MAX_COLUMN_COUNT];
	
};


struct HTMLTABLE
{
	Row* rows = new Row[GlobalConstants::MAX_ROW_COUNT];
	size_t rowsCount = 0;
	size_t colsCount = 0;
};
bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

bool containsTH(const char* str) {
	while (*str != '\0') {
		if (*str == 't' || *str == 'T') {
			if (*(str + 1) == 'h' || *(str + 1) == 'H') {
					return true;
			}
		}
		++str;
	}

	return false;
}

bool containsTR(const char* str) {
	while (*str != '\0') {
		if (*str == 't' || *str == 'T') {
			if (*(str + 1) == 'r' || *(str + 1) == 'R') {
				return true;
			}
		}
		++str;
	}

	return false;
}

bool containsTD(const char* str) {
	while (*str != '\0') {
		if (*str == 't' || *str == 'T') {
			if (*(str + 1) == 'd' || *(str + 1) == 'D') {
				return true;
			}
		}
		++str;
	}

	return false;
}

bool containsSlashTH(const char* str) {
	while (*str != '\0') {
		if (*str == '/') {
			if(*(str + 1) == 't' || *(str + 1) == 'T') {
				if (*(str + 2) == 'h' || *(str + 2) == 'H') {
					return true;
				}
			}
		}
		++str;
	}

	return false;
}

bool containsSlashTD(const char* str) {
	while (*str != '\0') {
		if (*str == '/') {
			if (*(str + 1) == 't' || *(str + 1) == 'T') {
				if (*(str + 2) == 'd' || *(str + 2) == 'D') {
					return true;
				}
			}
		}
		++str;
	}

	return false;
}

bool containsSlashTR(const char* str) {
	while (*str != '\0') {
		if (*str == '/') {
			if (*(str + 1) == 't' || *(str + 1) == 'T') {
				if (*(str + 2) == 'r' || *(str + 2) == 'R') {
					return true;
				}
			}
		}
		++str;
	}

	return false;
}



//opravi gi
//ASCI > 255 RETURN -1 FOR ERROR HANDLING
int extractAsciiNumber(const char* str, size_t& startIdx) {
	unsigned asciiNumber = 0;
	for (size_t i = startIdx; i < startIdx+1; i++) {
		if (isdigit(str[i]) && asciiNumber < 256) {
			asciiNumber = asciiNumber * 10 + (str[i] - '0');
			startIdx++;
		}
		else {
			//Invalid ASCII code => the text reamins &#256 e.x
			if (asciiNumber > 255) {
				return -1;
			}
			//The char is not a digit => we have the ASCII number
			break;
		}
	}
	return asciiNumber;
}

char convertIntToChar(unsigned asciiNumber) {
	return char(asciiNumber);
}

void replaceSubstring(char* str, size_t startIdx,size_t endIdx, unsigned asciiNumber) {
	char ch = convertIntToChar(asciiNumber);
	size_t length = strlen(str);

	str[startIdx++] = ch;
	for (; endIdx < length; startIdx++){
		str[startIdx] = str[endIdx++];
	}

	str[startIdx] = '\0';
}

void containsValueToBeConverted(char* str) {
	unsigned strLen = strlen(str);

	for (size_t i = 0; i < strLen; i++) {
		if (str[i] == '&') {
			if (str[i + 1] == '#') {
				size_t currIndex = i + 2;
				int asciiNumber = extractAsciiNumber(str,currIndex);


				if (asciiNumber < 0) {
					continue;
				}
				else {
					replaceSubstring(str, i,currIndex, asciiNumber);
				}
			}
		}
	}
}


void parseFromRow(const char* rowStr, HTMLTABLE& table) {

	std::stringstream rowStream(rowStr);
	char buff[GlobalConstants::BUFFER_SIZE];

	while (!rowStream.eof() && table.colsCount < GlobalConstants::MAX_COLUMN_COUNT) {

		if (flagIsInText) {
			rowStream.getline(buff, GlobalConstants::BUFFER_SIZE, '<');
			if (containsSlashTH(buff) || containsSlashTD(buff)) {
				flagIsInText = false;
				containsValueToBeConverted(table.rows[table.rowsCount].cells[table.colsCount].cell);
				table.colsCount++;
			}
			else {
				strcat(table.rows[table.rowsCount].cells[table.colsCount].cell, buff);
				std::cout << "Full Header " << table.rows[table.rowsCount].cells[table.colsCount].cell;
				
			}
			
		}


		rowStream.clear();
		rowStream.getline(buff, GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::CLOSE_BRACKET);



		//defence to always get the right colls count and cell idx
		if(containsSlashTH(buff) || containsSlashTD(buff)) {
			///work it later
			containsValueToBeConverted(table.rows[table.rowsCount].cells[table.colsCount].cell);
			flagIsInText = false;
			table.colsCount++;
			continue;
		}
		if (containsSlashTR(buff)) {
			table.rowsCount++;
			continue;
		}

		if (containsTR(buff)) {
			//table.rowsCount++;
			table.colsCount = 0;
			//flagIsTR = true;
		}
		
		else if (containsTH(buff)) {
			table.rows[table.rowsCount].cells[table.colsCount].isHeader = true;
			rowStream.getline(table.rows[table.rowsCount].cells[table.colsCount].cell, GlobalConstants::BUFFER_SIZE, '<');
			std::cout << "Header " << table.rows[table.rowsCount].cells[table.colsCount].cell << std::endl;
			flagIsInText = true;
		}

		else if (containsTD(buff)) {
			rowStream.getline(table.rows[table.rowsCount].cells[table.colsCount].cell, GlobalConstants::BUFFER_SIZE, '<');
			std::cout << "Der " << table.rows[table.rowsCount].cells[table.colsCount].cell << std::endl;
			flagIsInText = true;
		}

		else {
			continue;
		}
	
	}

}

void parseFromFile(std::istream& ifs, HTMLTABLE& result) {
	//HTMLTABLE result;
	char fileLine[GlobalConstants::BUFFER_SIZE];

	while (!ifs.eof() && result.rowsCount < GlobalConstants::MAX_ROW_COUNT) {
		ifs.getline(fileLine, GlobalConstants::BUFFER_SIZE, '\n');
		parseFromRow(fileLine, result);
	}

	//return result;
}

void parseFromFile(const char* fileName, HTMLTABLE& table)
{
	//HTMLTABLE table;
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "File failed to open file!";
		//return {};
	}
	parseFromFile(ifs, table);
	//return table = parseFromFile(ifs);
}

void calculateMaxWidthCells(const HTMLTABLE& table,size_t* maxWidths) {
	

	// Calculate maximum width for each column
	for (size_t i = 0; i < table.rowsCount; ++i) {
		for (size_t j = 0; j < table.colsCount; ++j) {
			int currentWidth = strlen(table.rows[i].cells[j].cell);

			

			if (currentWidth > maxWidths[j]) {
				maxWidths[j] = currentWidth;
			}
		}
	}
}

char* getPadding(size_t cellLength, size_t maximumWidth) {
	

	int end = maximumWidth - cellLength;
	char* ptr = new char[end];
	for (size_t i = 0; i < end; i++)
	{
		ptr[i] = ' ';
	}
	
	ptr[end] = '\0';
	return ptr;
}

void printTable(const HTMLTABLE& table) {
	size_t* maxWidth = new size_t[table.colsCount]{};

	calculateMaxWidthCells(table, maxWidth);

	for (size_t i = 0; i < table.rowsCount; i++) {
		for (size_t j = 0; j < table.colsCount; j++) {
			if (table.rows[i].cells[j].isHeader) {
				//std::cout << "|*" << table.rows[i].cells[j].cell;
					char* padding = getPadding(strlen(table.rows[i].cells[j].cell), maxWidth[j]);
					std::cout << "|*" << table.rows[i].cells[j].cell <<padding<< "*|";
				
			}
			else {
				char* padding = getPadding(strlen(table.rows[i].cells[j].cell), maxWidth[j]);
				std::cout << "| " << table.rows[i].cells[j].cell <<padding<< " |";
			}
		}
		std::cout << std::endl;
	}
}



int main() {
	//?? ????????? ?? ????????? ??? ??? ??????? ???? ? ??? ?? ???????       HTMLCODE.txt
	char fileName[GlobalConstants::MAX_FILENAME_SIZE];
	std::cin >> fileName;
	HTMLTABLE table;
	parseFromFile(fileName, table);

	printTable(table);

	//containsValueToBeConverted((char*)"&#97");
}
