#include <iostream>
#include <sstream>
#include <fstream>

namespace GlobalConstants {
	constexpr unsigned FIELD_MAX_SIZE = 50;
	constexpr unsigned MAX_COLUMN_COUNT = 15;
	constexpr unsigned MAX_ROW_COUNT = 100;
	constexpr char OPEN_BRACKET = '<';
	constexpr char CLOSE_BRACKET = '>';

	constexpr unsigned MAX_FILENAME_SIZE = 50;
	constexpr unsigned BUFFER_SIZE = 1024;
};
unsigned rowsCountF = 0;
unsigned colsCountF = 0;

typedef char Field[GlobalConstants::FIELD_MAX_SIZE]; // field with maximum 50 charachters 

struct Row
{
	Field fields[GlobalConstants::MAX_COLUMN_COUNT];
};


struct HTMLTABLE
{
	Row rows[GlobalConstants::MAX_ROW_COUNT];
	size_t rowsCount = 0;
	size_t collsCount = 0;
};



//opravi gi
bool isTH(const char* text) {
	return text[0] == 't' && text[1] == 'h';
}
bool isTR(const char* text) {
	return text[0] == 't' && text[1] == 'r';
}
bool isTD(const char* text) {
	return text[0] == 't' && text[1] == 'd';
}





Row parseFromRow(const char* rowStr, const HTMLTABLE& table) {
	std::stringstream rowStream(rowStr);
	char buff[GlobalConstants::BUFFER_SIZE];


	while (!rowStream.eof()) {


		//za da ne sa problem _ spacesovete naprawi posle while dokato ne udarish < 
		
		
		if(isTD(buff) || isTH(buff)){
			rowStream.getline(buff, 1024, '<');
		}
		else {
			rowStream.ignore();
			rowStream.getline(buff, 1024, '>');
		}
		//rowStream.getline(buff, 1024, '>');

		std::cout << buff<<std::endl;
	}

	
	


	return {};
}

HTMLTABLE parseFromFile(std::istream& ifs)
{
	HTMLTABLE result;
	char rowStr[GlobalConstants::BUFFER_SIZE];


	int currRowIdx = 0;
	int currColIdx =0 ;



	while (!ifs.eof() && result.rowsCount < GlobalConstants::MAX_ROW_COUNT)
	{
		ifs.getline(rowStr, GlobalConstants::BUFFER_SIZE, '\n');
		result.rows[currRowIdx] = parseFromRow(rowStr, result);
	}
	return result;
}

HTMLTABLE parseFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "File failed to open file!";
		return {};
	}

	return parseFromFile(ifs);
}

int main(){
	//От конзолата ще прочетете път към текстов файл с код на таблица       HTMLCODE.txt
	char fileName[GlobalConstants::MAX_FILENAME_SIZE];
	std::cin >> fileName;
	HTMLTABLE table = parseFromFile(fileName);
	

}
