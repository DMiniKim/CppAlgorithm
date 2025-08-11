#include <iostream>

using namespace std;

void CountingSort(int list[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (max < list[i])
		{
			max = list[i];
		}
	}
	int* temp = new int[max]();

	for (int i = 0; i < size; i++)
	{
		temp[list[i] - 1]++;
	}
	for (int i = 0; i < max; i++)
	{
		cout << temp[i] << " ";
	}
	delete[] temp;
}

int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는 지
	// 개수를 세어 저장한 다음 정렬하는 알고리즘.

	int list[] = { 1,2,3,5,2,3,5,5,1,2,2,5,4,2,1,1,3,2,3,2,1 };
	int size = sizeof(list) / sizeof(list[0]);
	CountingSort(list, size);
#pragma endregion

	return 0;
}


