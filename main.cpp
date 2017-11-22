#include <stdio.h>
#include <iostream>
#include <vector>

#include <functional>

using namespace std;

class Test {
public:
	Test(int x, int y) : b(x), a(y) {};
	
	int a;
	int b;
};

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
	Test obj = {3, 5};
	
	int len;
	cin >> len;

	vector<function<bool(int)>> testers;
	testers.resize(len);
	
	for (int i = 0;i < len;i++) {
		testers[i] = getChecker(i*i);
	}

	int x = 17;
	int count = 0;
	for (auto tester: testers) {
		if (tester(x))
			count++;
	}
	
	printf("Result: %d\n", count);
}