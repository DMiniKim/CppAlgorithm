#include <iostream>

using namespace std;


int Maximum(int list[], int left, int right)
{
	if (left == right) return list[left];

	int center = left + (right - left) / 2;
	int leftMax = Maximum(list, left, center);
	int rightMax = Maximum(list, center + 1, right);

	return (leftMax < rightMax) ? rightMax : leftMax;

}


int main()
{
#pragma region 분할 정복
	// 주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분 문제에 대한
	// 답을 재귀 호출을 이용하여 계산한 다음,
	// 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘.

	// 분할 ( Divide ) :		주어진 문제를 두 개 혹은 그 이상의 형식으로 나눔.

	// 정복 ( Conquer ) :	나누어진 문제를 재귀적으로 해결해서 나누어진 문제를
	//						더이상 나누어서 문제가 필요없을 때 까지 계속 분할.

	// 통합 ( Combine ) :	나누어서 해결한 문제들을 통합해서 원래 해답을 생성합니다.


	int arr[] = { 20,15,99,1,12,46,34,7,37,357,257,58 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << Maximum(arr, 0, size - 1);

#pragma endregion


	return 0;
}


