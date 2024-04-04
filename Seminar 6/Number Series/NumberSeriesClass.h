#pragma once
namespace GLOBAL_CONSTANTS{
	constexpr unsigned firstLengthSeries = 10;
}


class NumSeries {
private:
	int a_0 = 0;
	int (*funcPointer)(int a_i) = nullptr;
	int* numberSeries = nullptr;
	unsigned seriesCount = 0;

	void copyFrom(const NumSeries& other);
	void free();
public:

	NumSeries() = default;
	NumSeries(const int newa_0, int (*newFuncPointer)(int));
	NumSeries(const NumSeries& other);
	NumSeries& operator=(const NumSeries& other);
	~NumSeries();

	
	int getA_0() const;
	void setA_0(const int newA);

	//int getFuncPointer()  const;
	void setFuncPointer(int(*newFuncPointer)(int));

	void setNumSeries();
	

	int getNumberAtIndex(unsigned index);

	int getNextNumber();

	void setSeriesUpToIndex(const unsigned index);

	bool isNumberInSeries(int number);
};

