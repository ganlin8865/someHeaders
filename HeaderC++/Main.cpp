//hello!
#include "littletools.h"
#include <iostream>

int main()
{
	int a[10] = { 1, 2, 7, 4, 3, 100, 65 };
	sort s;
	s.sort::BubbleSort(a, 10);
	std::cout << a[1] << a[2] << a[3] << a[4];
}