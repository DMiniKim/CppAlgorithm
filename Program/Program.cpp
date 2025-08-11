#include <iostream>
#include <random>
using namespace std;

void combine(int list[], int middle, int end )
{
	//정렬된 걸 합치는 것만 구현
}

void merge_sort(int list[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(list, start, mid);
		merge_sort(list, mid + 1, end);

	}
	else if (start >= end)
	{
		return;
	}
	in




	delete[] temp;
}

int main()
{
#pragma region 병합 정렬
	// 하나의 리스트를 두개의 균일한 크기로 분할하고 분할된
	// 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를
	// 합하여 전체가 정렬된 리스트가 되게 하는 방법.

	// 1. 리스트의 길이가 0 또는 1이 되면 이미 정렬된 것으로 본다

	// 2. 그렇지 않은 경우

	//		2-1. 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 
	//			 두 부분 리스트로 나눈다.

	//		2-2. 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬한다.

	//		2-3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합한다.

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<int> dist(0, 50);

	int arr[12] = {};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		arr[i] = dist(eng);
	}
	merge_sort(arr, 0, size - 1);
#pragma endregion
	return 0;
}