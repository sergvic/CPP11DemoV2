#include <stdio.h>
#include <iostream>

#include <functional>

using namespace std;

class SuperCollection
{
	int data[1000];
	int len;

public:
	SuperCollection()
	{
		data[0] = 1;
		data[1] = 3;
		data[2] = 13;
		data[3] = 513;
		data[4] = 1234;
		len = 5;
	}

	int operator[](int i) { return data[i]; }

	int findFirst(function<bool (int)> predFuncTest)
	{
		for (int i = 0;i < len;i++)
		{
			if (predFuncTest(data[i])) return i;
		}
		return -1;
	}
};

bool checkEven(int x)
{
	return x % 2 == 0;
}

function<bool(int)> getChecker(int thresold) {
	return [thresold](int x) {return x > thresold;};
}

void main()
{
	SuperCollection col;
	function<bool(int)> testers[10];
	
	for (int i = 0;i < 10;i++) {
		testers[i] = getChecker(i*i);
	}

	int x = 17;
	int count = 0;
	for (int i = 0;i < 10;i++) {
		if (testers[i](x))
			count++;
	}
	
	printf("Result: %d\n", count);
}