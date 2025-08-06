#include <iostream>

using namespace std;

void sieve(int n)
{
	int* temp = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (i + 1 == 1)
		{
			temp[i] = 0;
		}
		if (((i + 1) % 2 == 0) || ((i + 1) % 3 == 0))
		{
			temp[i] = 0;
			if (i + 1 == 2)	temp[i] = i + 1;
			if (i + 1 == 3)	temp[i] = i + 1;
		}
		else
		{
			temp[i] = i + 1;
		}
		if (i + 1 == 1)
		{
			temp[i] = 0;
		}

	}
	for (int i = 0; i < n; i++)
	{
		if (temp[i] != 0)
		{
			cout << temp[i] << endl;
		}
	}
	delete[]  temp;

}


int main()
{
#pragma region 에라토스의 체

	// 미니 킴 버전
	int minority = 1;

	while (minority < 50)
	{
		minority++;
		int a = 1;
		int aCount = 0;
		while (a <= minority)
		{
			if (minority % a == 0)
			{
				aCount++;
			}
			a++;
		}
		if (aCount < 3)
		{
			cout << minority << endl;
		}

	}
	cout << "===========================" << endl;

	// 강사님 버전
	int j = 0;
	int n = 50;

	for (int i = 2; i <= n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "===========================" << endl;

	sieve(16);


#pragma endregion


	return 0;
}


