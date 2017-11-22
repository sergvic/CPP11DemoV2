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
		data[2] = 513;
		data[3] = 1234;
		len = 4;
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

void main()
{
	SuperCollection col;
	int thresold = 0;

	cin>>thresold;

	auto f = [thresold](int x) {return x > thresold;};
	
	int idx = col.findFirst(f);
	
	printf("Result: %d\n", idx>=0?col[idx]:idx);
}