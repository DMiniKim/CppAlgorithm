#include <iostream>

using namespace std;


int main()
{
#pragma region 완전 탐색
    // 가능한 모든 경우의 수를 탐색하면
    // 결과를 찾아내는 알고리즘.
    int passWord[4] = { 5,5,3,6 };
    int searchArr[4] = { 0,0,0,0 };
    int count = 0;
    while ((passWord[0] != searchArr[0]) || (passWord[1] != searchArr[1]) || (passWord[2] != searchArr[2]) || (passWord[3] != searchArr[3]))
    {
        searchArr[3]++;
        if (searchArr[3] == 10)
        {
            searchArr[3] = 0;
            searchArr[2]++;
        }
        if (searchArr[2] == 10)
        {
            searchArr[2] = 0;
            searchArr[1]++;
        }
        if (searchArr[1] == 10)
        {
            searchArr[1] = 0;
            searchArr[0]++;
        }

        count++;
    }

    cout << "자물쇠를 풀기 위해 " << count << " 만큼 뻘 짓을 했습니다 " << endl;
#pragma endregion

    return 0;
}


