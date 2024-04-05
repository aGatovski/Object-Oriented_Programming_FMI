#pragma once

namespace GLOBAL_CONSTANTS {
	constexpr short MINIMAL_SET_SIZE = 3;
}

class MultiSet {
private:
	unsigned n;
	int* multiSet = nullptr;
	unsigned multiSetSize = 0;
	unsigned currMultiSetIndex = 0;

	void free();
	void copyFrom(const MultiSet& other);
public:
	MultiSet() = default;
	MultiSet(const unsigned n);
	MultiSet(const MultiSet& other);
	MultiSet& operator=(const MultiSet& other);
	~MultiSet();
	void setN(unsigned n);
	unsigned getN() const;

	void setMultiSet();

	void addNumber(unsigned number);

	void resizeSet(unsigned number);

	void printSet();

	unsigned printCountNumberInSet(int number) const;

	void removeInstancesOfNumber(unsigned number);

	void removeFirstInstanceOfANumber(unsigned number);

	void intersectSets(const MultiSet& other);

	void unionSets(const MultiSet& other);
};
