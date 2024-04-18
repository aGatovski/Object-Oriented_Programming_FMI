#include "MultiSet.h"
#include <exception>
namespace GLOBAL_CONSTANTS {
	constexpr size_t BYTE_SIZE = 8;
};
using namespace GLOBAL_CONSTANTS;

namespace HELPER_FUNCTIONS {
	unsigned int getNextPowerOf2(unsigned number) {
		unsigned int power = 1;
		while (power < number) {
			power <<= 1;
		}
		return power;
	}
	bool checkBitValue(unsigned number, unsigned index) {
		unsigned int mask = 1;
		
		mask <<= index;

		return (mask & number) == mask;
	}
};
using namespace HELPER_FUNCTIONS;

//add try catch
MultiSet::MultiSet(size_t  n, size_t  k) : maxNum(n) , bits(k){
	// maxNum + 1 in order to Add the zero ;
	// +1 for accurate bucketCount;
	bucketsCount = ((maxNum + 1) / bits) + 1;
	maxCountOccurences = (1 << k) - 1;
	data = new unsigned char [bucketsCount]{ 0 };
}

MultiSet::MultiSet(const MultiSet& other){
	copyFrom(other);
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MultiSet::~MultiSet()
{
	free();
}

bool MultiSet::addNumber(size_t num) {
	if (num > maxNum || num < 0) {
		throw std::out_of_range("Number must be greater than 0 and equal to or less than n!");
	}
	if (getCountOfOccurrences(num) == maxCountOccurences) {
		throw std::exception("Max occurences of this number has been reached! Try a different one!");
	}
	size_t currentBucket = (num * bits) / BYTE_SIZE;
	size_t firstIndexNumber = (num*bits) % BYTE_SIZE;
	
	if (numberInTwoBuckets(num)) {
		int bitsInFirstBucket = std::min(8 - firstIndexNumber, bits);
		int bitsInSecondBucket = bits - bitsInFirstBucket;

		// Create masks for the two buckets
		unsigned char mask1 = (1 << bitsInFirstBucket) - 1;
		unsigned char mask2 = (1 << bitsInSecondBucket) - 1;

		// Shift mask2 to align with the bits in the second bucket
		mask2 <<= BYTE_SIZE - bitsInSecondBucket;

		// Extract bits from the two buckets
		unsigned char bucket1Bits = data[currentBucket] & mask1;
		unsigned char bucket2Bits = data[currentBucket + 1] & mask2;

		// Combine the bits from both buckets into tempMask
		unsigned char tempMask = (bucket1Bits << bitsInSecondBucket) | (bucket2Bits >> (BYTE_SIZE - bitsInSecondBucket));

		// Number ++
		tempMask += 1;

		// Update the data in both buckets
		data[currentBucket] = ((data[currentBucket] >>= bitsInFirstBucket) <<= bitsInFirstBucket);
		data[currentBucket] |= (tempMask >> bitsInSecondBucket);
		data[currentBucket + 1] = ((data[currentBucket + 1] <<= bitsInSecondBucket) >>= bitsInSecondBucket);
		data[currentBucket + 1] |= (tempMask << (BYTE_SIZE - bitsInSecondBucket));

		
	}

	else {
		unsigned char mask = (1 << bits) - 1;
		mask <<= (BYTE_SIZE - (bits + firstIndexNumber));
		
		unsigned char tempMaskWith1 = ~mask;
		unsigned char bitsToSet = ((mask & data[currentBucket]) >> (BYTE_SIZE - bits - firstIndexNumber));

		bitsToSet +=1;
		
		data[currentBucket] &= tempMaskWith1;

		data[currentBucket] |= (bitsToSet)<< (BYTE_SIZE - bits - firstIndexNumber);

	}
	return false;
}

size_t MultiSet::getCountOfOccurrences(size_t num) const {
	size_t currentBucket = (num * bits) / BYTE_SIZE;
	size_t firstIndexNumber = (num * bits) % BYTE_SIZE;

	if (numberInTwoBuckets(num)) {
		int bitsInFirstBucket = std::min(8 - firstIndexNumber, bits);
		int bitsInSecondBucket = bits - bitsInFirstBucket;

		unsigned char mask1 = (1 << bitsInFirstBucket) - 1;
		unsigned char mask2 = (1 << bitsInSecondBucket) - 1;

		mask2 <<= BYTE_SIZE - bitsInSecondBucket;

		unsigned char bucket1Bits = data[currentBucket] & mask1;
		unsigned char bucket2Bits = (data[currentBucket + 1] & mask2) >> (BYTE_SIZE - bitsInSecondBucket);

		unsigned char combinedBits = (bucket1Bits << bitsInSecondBucket) | bucket2Bits;

		return (size_t)combinedBits;
	}
	else {
		unsigned char mask = (1 << bits) - 1;
		mask <<= BYTE_SIZE - (bits + firstIndexNumber);

		unsigned char bitsToSet = (mask & data[currentBucket]) >> (BYTE_SIZE - bits - firstIndexNumber);
	
		return (size_t)bitsToSet;
	}
}

void MultiSet::printNumbersInSet() const{
	std::cout << "All Numbers in set: ";
	for (size_t i = 0; i < maxNum; i++){
		if (getCountOfOccurrences(i) > 0) {
			std::cout << i << " ";
		}
	}
}

void MultiSet::printMultiSet() const {
	for (size_t bucketIndex = 0; bucketIndex < bucketsCount; ++bucketIndex) {
		for (int bitIndex = BYTE_SIZE-1; bitIndex >=0; bitIndex--) {
			std::cout << checkBitValue(data[bucketIndex], bitIndex) << " ";
		}
		std::cout << std::endl;
	}
}

void MultiSet::free(){
	delete[] data;
	data = nullptr;
	maxNum = 0;
	bits = 0;
	bucketsCount = 0;
}

void MultiSet::copyFrom(const MultiSet& other){
	maxNum = other.maxNum;
	bits = other.bits;
	bucketsCount = other.bucketsCount;

	data = new unsigned char[bucketsCount] { 0 }; 
	for (int i = 0; i < bucketsCount; i++) {
		data[i] = other.data[i];
	}
}

bool MultiSet::numberInTwoBuckets(size_t num) const{
	return  ((  (num*bits) % BYTE_SIZE) + bits) > BYTE_SIZE;
}

//!proveri gi
//! nesh ne mi se haresvat
MultiSet intersect(const MultiSet& s1, const MultiSet& s2){
	if (s1.bits != s2.bits) {
		//sig mojesh ama shte e tolkova trujdno che prosto ne!
		throw std::logic_error("Cannot intersect sets with diferent bit counts");
	}
	size_t maxNum = std::min(s1.maxNum, s2.maxNum);
	MultiSet result(maxNum, s1.bits);

	for (size_t i = 0; i <= maxNum; i++) {
		// Check if the number exists in both multisets
		if (s1.getCountOfOccurrences(i) > 0 && s2.getCountOfOccurrences(i) > 0) {

			// Add the number to the intersection multiset
			size_t minimalOccurances = std::min(s1.getCountOfOccurrences(i), s2.getCountOfOccurrences(i));
			for (size_t j = 0; j < minimalOccurances; j++) {
				result.addNumber(i);
			}
		}
	}

	return result;
	
}

MultiSet difference(const MultiSet& s1, const MultiSet& s2) {
	if (s1.bits != s2.bits) {
		throw std::logic_error("Cannot compute difference between sets with different bit counts");
	}

	size_t maxNum = std::max(s1.maxNum, s2.maxNum);
	MultiSet result(maxNum, s1.bits);

	// Iterate over each possible number up to the maximum number in s1
	for (size_t num = 0; num <= s1.maxNum; ++num) {
		// Check if the current number is present in s1 but not in s2
		if (s1.getCountOfOccurrences(num) > 0 && s2.getCountOfOccurrences(num) == 0) {
			// Add the current number to the result multiset
			result.addNumber(num);
		}
	}

	return result;
}

MultiSet unify(const MultiSet& s1, const MultiSet& s2) {
	if (s1.bits != s2.bits) {
		throw std::logic_error("Cannot unify sets with different bit counts");
	}

	size_t maxNum = std::max(s1.maxNum, s2.maxNum);
	MultiSet result(maxNum, s1.bits);

	// Iterate over each possible number up to the maximum number in either set
	for (size_t num = 0; num <= maxNum; ++num) {
		// Determine the maximum occurrences of the current number in either set
		size_t maxOccurrences = std::max(s1.getCountOfOccurrences(num), s2.getCountOfOccurrences(num));

		// Add the current number to the result multiset the maximum number of times it occurs in either set
		for (size_t count = 0; count < maxOccurrences; ++count) {
			result.addNumber(num);
		}
	}

	return result;
}
