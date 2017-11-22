#include <stdio.h>

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

	int findFirst(bool (*predFuncTest)(int))
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
	
	auto f = [](int x) {return x < 10 ? x % 2 == 0 : x % 3 == 0;};
	
	int idx = col.findFirst(f);

	printf("Result: %d\n", idx>=0?col[idx]:idx);
}