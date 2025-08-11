#include <iostream>
#include <random>
using namespace std;

void quick_sort(int list[], int start, int end)
{
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (right > left) // right 인덱스가 left와 교차될때 까지 진행
	{
		while (list[left] <= list[pivot] && left <= end)	// left인덱스가 end보다 작고 <- 안전장치
		{											// left인덱스의 list값이 pivot보다 작다면 ++
			left++;
		}
		while (list[right] >= list[pivot] && right >= start + 1)	// right인덱스가 start + 1보다 크고 <- 안전장치
		{													// right인덱스의 list값이 pivot보다 크다면 --
			right--;
		}
		if (left == right)						//기존에 정렬이 잘되어있어서 left나 right둘중 하나는 가만히 있고
		{										//하나만 움직이다보면 같아지는 현상이 나타나는 데 그 때를 위한
			right = left - 1;						//안전장치
		}
		if (right > left)						// left와 right가 엇갈리지 않았다면 
		{										// swap
			int temp = list[left];
			list[left] = list[right];
			list[right] = temp;
		}
		else
		{
			int temp = list[right];
			list[right] = list[start];
			list[start] = temp;
		}
	}
	//cout << left << " " << right << endl;
	quick_sort(list, start, right - 1);
	quick_sort(list, right + 1, end);

}


int main()
{
#pragma region 퀵 정렬
	// 기준점을 획득한 다음 기준점을 기준으로 배열을 나누고 한 쪽에는
	// 기준점보다 작은 값들이 위치하게 한다음 다른 한 쪽에는 기준점보다
	// 큰 값들이 위치하도록 정렬한다.

	// 나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여
	// 모든 배열이 기본 배열이 될 때까지 반복하면서 정렬하는 알고리즘입니다.
	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<int> dist(0, 50);

	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		arr[i] = dist(eng);
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "==============================" << endl;
	quick_sort(arr, 0, size - 1);
#pragma endregion
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}