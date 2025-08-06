#include <iostream>

using namespace std;

unsigned int GCD(int a, int b)
{
	if (b == 0)
	{
		cout << "최대 공약수는 " << a << " 입니다" << endl;
		return a;
	}
	return GCD(b, a % b);
	// 1. 두 개의 자연수 x , y 가 있을 때,
	//	  x 와 y 를 나눈 나머지를 r 이라고 한다.

	// 2. r 이 0 이라면 , x 와 y 의 최대공약수가 y 가 됩니다.

	// 3. r 이 0 이 아니라면 , x 와 y 의 최대공약수는 y 와 r 의
	//	  최대공약수와 같기 때문에 x 에는 y 그리고 y 에는 r 을 대입하고
	//    1 번으로 돌아갑니다.
}

int main()
{
#pragma region 유클리드 호제법
	// 2 개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로
	// 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘이다.

	//int a = 3;
	//int b = 5;
	//
	//int gcd = 0;
	//
	//int temp = 0;
	//while (temp <= a)
	//{
	//	temp++;
	//	if (a % temp == 0)
	//	{
	//		if (b % temp == 0)
	//		{
	//			gcd = temp;
	//		}
	//	}
	//}
	//cout << gcd << endl;
	GCD(20, 36);


#pragma endregion

	return 0;
}


