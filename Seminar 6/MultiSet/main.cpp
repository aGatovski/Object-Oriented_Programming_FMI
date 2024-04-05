#include "MultiSetClass.h"
#include <iostream>

int main(){
	MultiSet set(5);
	set.addNumber(4);
	set.addNumber(4);
	set.addNumber(4);
	set.addNumber(3);
	set.addNumber(3);
	//set.removeInstancesOfNumber(4);


	MultiSet set2(5);
	set2.addNumber(2);
	set2.addNumber(2);
	set2.addNumber(1);
	set2.addNumber(4);
	set2.addNumber(3);

	set.unionSets(set2);

	set.printSet();
}
