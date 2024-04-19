#pragma once
#include <iostream>
#include <assert.h>

namespace HELPER_FUNCTIONS {
    unsigned int getNextPowerOf2(unsigned number);
    bool checkBitValue(unsigned number, unsigned index);
} 

class MultiSet {
private:
    unsigned char* data = nullptr;
    size_t maxNum = 0;
    size_t bits = 0;
	size_t bucketsCount=0;
    size_t maxCountOccurences = 0;

public:
    MultiSet(size_t  n, size_t  k);
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);
    ~MultiSet();

    bool addNumber(size_t num);//  Добавяне на число.
    size_t getCountOfOccurrences(size_t num) const;//Проверка колко пъти се съдържа число.
    void printNumbersInSet() const;// Принтиране на всички числа, които се съдържат в мултимножеството.
    void printMultiSet() const;//Принтиране на това как мултимножеството е представено в паметта.


    //   Сериализация / десериализация в / от двоичен файл.?
     void serialise(const char* fileName);
     void deserialise(const char* fileName);

   
    friend MultiSet intersect(const MultiSet& s1, const MultiSet& s2);// Сечение / Разлика на две мултимножества.
    friend MultiSet difference(const MultiSet& s1, const MultiSet& s2);
    friend MultiSet unify(const MultiSet& s1, const MultiSet& s2);//  Допълнение на мултимножество(ако x се е срещал p пъти, то в допълнението се среща 2 ^ k - 1 - p пъти).
    void complete();

private:
    void free();
    void copyFrom(const MultiSet& other);
    bool numberInTwoBuckets(size_t num) const;
};

