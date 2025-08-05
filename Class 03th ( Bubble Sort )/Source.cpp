#include <iostream>

using namespace std;



int main()
{
#pragma region 거품 정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘입니다.
	//int arr[]{ 6,4,2,7,9 };
	//int index = 0;
	//int i = 0;
	//for (int j = 0; j < 4; j++)
	//{
	//
	//	for (int i = 0; i < 4; i++)
	//	{
	//
	//		if (arr[i] < arr[i + 1]) continue;
	//		else if (arr[i] > arr[i + 1])
	//		{
	//			int temp = arr[i];
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//		}
	//
	//		if (arr[0] < arr[1])
	//		{
	//			if (arr[1] < arr[2])
	//			{
	//				if (arr[2] < arr[3])
	//				{
	//					if (arr[3] < arr[4])
	//					{
	//						break;
	//					}
	//				}
	//			}
	//		}
	//		index++;
	//	}
	//}
	int list[] = { 5,3,1,4,7 };
	int size = sizeof(list) / sizeof(list[0]);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < (size - i); j++)
		{
			if (list[j] > list[j + 1])
			{
				std::swap(list[j], list[j + 1]);
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << index << endl;


#pragma endregion

	return 0;
}


