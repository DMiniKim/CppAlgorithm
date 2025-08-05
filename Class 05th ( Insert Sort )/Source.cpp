#include <iostream>

using namespace std;

int main()
{
#pragma region 삽입 정렬
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘입니다.
	int arr[] = { 18, 3, 5, 44, 39, 28, 33, 27, 14, 30 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key;
	for (int i = 1; i < size; i++) // key는 1번인덱스부터 해야해서 i = 1
	{
		key = arr[i];
		for (int j = i - 1; j >= 0; j--) // key보다 -1 부터 역순으로 써치하기 위해
		{								// j = i-1
			if (key < arr[j])			// key보다 이전 인덱스가 크다면
			{
				arr[j + 1] = arr[j];
			}
			else { break; }

			arr[j] = key; // 외부에 j를 선언해서  for 문밖으로빼서	
			// 연산을 줄이는 게 가능
		}
	}

	for (const auto& element : arr)
	{
		cout << element << " ";
	}

#pragma endregion

	return 0;
}


