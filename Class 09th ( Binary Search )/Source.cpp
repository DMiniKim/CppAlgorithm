#include <iostream>

using namespace std;

int BinarySearch(int list[], int left, int right, int key)
{
	int pivot = (left + right) / 2;
	int findKey;
	if (right <= left)
	{
		cout << "찾는 key 가 없습니다." << endl;
		return false;
	}
	if (list[pivot] == key)	return list[pivot];
	else if (list[pivot] > key)
	{
		findKey = BinarySearch(list, left, pivot - 1, key);
	}
	else if (list[pivot] < key)
	{
		findKey = BinarySearch(list, pivot + 1, right, key);
	}

	return findKey;
}
// 백준 이분탐색 부분 문제
int main()
{
#pragma region 이분 탐색
	// 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	// 좁혀나가는 방식으로 동작하는 알고리즘.

	int arr[] = { 1,2,6,7,10,23,45,82,100,105,143,178,200 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << BinarySearch(arr, 0, size - 1, 22) << endl;
#pragma endregion

	return 0;
}


