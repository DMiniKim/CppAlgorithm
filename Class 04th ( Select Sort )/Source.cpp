#include <iostream>

using namespace std;



int main()
{
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서
	// 결과를 교체하는 방식으로 정렬하는 알고리즘입니다.
	int arr[] = { 13, 44, 7, 21, 14, 17, 20, 6, 37, 22, 26, 10, 3, 8, 33, 16, 24, 1, 34, 39, 18, 12, 42, 35, 38, 25, 31, 32, 28, 27 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int min_index = 999999999;
	for (int i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i) // 최소 index의 위치가 i의 위치가 아니라면 
		{
			std::swap(arr[min_index], arr[i]);
		}

	}


	for (const auto element : arr)
	{
		cout << element << " ";
	}


#pragma endregion

	return 0;
}


