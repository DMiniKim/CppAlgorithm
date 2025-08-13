#include <iostream>
#include <random>

using namespace std;



int GreedyAlgorithm(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int count = 0;
	int change = 0;
	if (n >= 10000)
	{
		count = n / 10000;
		change = n % 10000;
		cout << "10000원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	else if (10000 > n && n >= 5000)
	{
		count = n / 5000;
		change = n % 5000;
		cout << "5000원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	else if (5000 > n && n >= 1000)
	{
		count = n / 1000;
		change = n % 1000;
		cout << "1000원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	else if (1000 > n && n >= 500)
	{
		count = n / 500;
		change = n % 500;
		cout << "500원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	else if (500 > n && n >= 100)
	{
		count = n / 100;
		change = n % 100;
		cout << "100원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	else if (100 > n && n >= 50)
	{
		count = n / 50;
		change = n % 50;
		cout << "50원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	else if (50 > n && n >= 10)
	{
		count = n / 10;
		change = n % 10;
		cout << "10원" << count << "개" << endl;
		count += GreedyAlgorithm(change);
	}
	cout << count << endl;
	return count;
}

int main()
{
#pragma region 탐욕법
	// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로
	// 여러 경우 중 하나를 검색해야 할 떄 마다 그 순간에
	// 최적이라고 생각되는 것을 선택해나가는 방식으로 진행하여
	// 최종적인 해답을 구하는 알고리즘.

	// 1. 탐욕 선택 속성
	// 각 단계에서 ' 최적의 선택 ' 을 했을 때 전체 문제에 대한
	// 최적의 해를 구할 수 있는 경우.

	// 2. 최적 부분 구조
	// 전체 문제의 최적의 해가 ' 부분 문제의 최적의 해로 구성 '
	// 될 수 있는 경우.

	// 탐욕 알고리즘으로 문제를 해결하는 방법

	// 1. 선택 절차 ( Selection Procedure )
	// 현재 상태에서의 최적의 해답을 선택.

	// 2. 적절성 검사 ( Feasibility Check )
	// 선택된 해가 문제의 조건을 만족하는 지 검사함.

	// 3. 해답 검사 ( Solution Check )
	// 원래의 문제가 해결되었는 지 검사하고 , 해결되지 않았다면
	// 선택 절차로 돌아가 위 과정을 반복.
	//GreedyAlgorithm(16420);

	int n = 1370;
	int count = 0;
	while (n >= 10)
	{
		if (n >= 1000)
		{
			n -= 1000;
			count++;
		}
		else if (n >= 500)
		{
			n -= 500;
			count++;
		}
		else if (n >= 100)
		{
			n -= 100;
			count++;
		}
		else if (n >= 50)
		{
			n -= 50;
			count++;
		}
		else if (n >= 10)
		{
			n -= 10;
			count++;
		}
	}
	cout << count << endl;


#pragma endregion

	return 0;
}