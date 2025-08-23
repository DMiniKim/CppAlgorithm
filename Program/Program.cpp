#include <iostream> // 콘솔 입출력(cout 등)을 위한 라이브러리
#include <vector>   // 동적 배열(std::vector)을 사용하기 위한 라이브러리
#include <random>   // C++ 표준 난수 생성을 위한 라이브러리
#include <chrono>   // C++ 표준 시간 측정을 위한 라이브러리

using namespace std;

constexpr double SECONDS_PER_DAY = 0.01;						// 1일 = 0.01초
constexpr int DAYS_PER_YEAR = 365;								// 365일
constexpr int SIMULATION_DURATION_IN_DAYS = DAYS_PER_YEAR * 2;	// 2년
constexpr int NUM_PEOPLE = 2000000;								// ㅋㅋㅋㅋ 200만명 ㅋㅋㅋ
constexpr double BASE_SUCCESS_PROB = 0.0005;					// 기본 강화확률 0.05%
constexpr double PROBABILITY_INCREASE_ON_FAIL = 0.0001;			// 실패하면 오르는 확률 0.01%
constexpr int MAX_FAIL_STACKS = 10;								// 실패 스택의 최대치


class Person {
	
private:	
	int failStack;			// 실패 스택
	bool isSuccess;			// 성공한 상태인가?
	
public:	
	Person() : failStack(0), isSuccess(false) {}
	
	bool TryEnhance(std::mt19937& rng, std::uniform_real_distribution<>& dist)
	{		
		double currentPercent = BASE_SUCCESS_PROB + (failStack * PROBABILITY_INCREASE_ON_FAIL);

		if (isSuccess == false)
		{
			if (dist(rng) < currentPercent)
			{			
				failStack = 0;			// 어차피 성공하면 건드릴 필요 없긴하지만 혹시모르니 초기화
				isSuccess = true;			// 성공 처리
				
				return true;	//성공
			}
			else
			{			
				if (failStack < MAX_FAIL_STACKS) // 강화실패 스택이 최대치가 아니라면
				{
					failStack++;					// 실패스택 증가
				}	
				return false;	//실패
			}
		}
	}
	const bool GetSuccess() const { return isSuccess; };
};


void EnhanceSimulation()
{

	cout << "강화 시작!\n";
	cout << "참가 인원: " << NUM_PEOPLE << "명, 시뮬레이션 기간: " << SIMULATION_DURATION_IN_DAYS << "일 (가상 시간)\n";
	cout << "==================================================\n";

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<> dist(0.0, 1.0);

	std::vector<Person> people(NUM_PEOPLE);	// 사람 수 만큼 배열 생성

	long long successPeople = 0;		// 성공한 사람 체크할 변수

	int simulatedDays = 0;				// 며칠 지났는 지 저장

	double elapseTime = 0.0;			// 경과된 시간 저장

	auto lastTime = std::chrono::high_resolution_clock::now();		// delta_time 측정용 변수

	// while 루프: simulated_days가 목표 기간에 도달할 때까지 계속 반복합니다.
	while (simulatedDays < SIMULATION_DURATION_IN_DAYS)
	{

		auto currentTime = std::chrono::high_resolution_clock::now();		// 현재시간

		std::chrono::duration<double> deltaDuration = currentTime - lastTime;	//현재 시간 - 마지막 시간 = deltaTime

		double deltaTime = deltaDuration.count();

		lastTime = currentTime;			// 갱신

		elapseTime += deltaTime; 		// 얼마나 시간이 흘렀는 지 갱신

		if (elapseTime >= SECONDS_PER_DAY)
		{
			elapseTime -= SECONDS_PER_DAY;

			simulatedDays++;

			// 순회 시작 == 강화 시작
			for (auto& person : people) \
			{
				if (person.GetSuccess() == true)	continue; // 이미 성공한 놈은 패스

				if (person.TryEnhance(rng, dist))
				{
					successPeople++;			// 성공한 사람 카운트
				}
			}			
			if (simulatedDays % 100 == 0)		// 100일 마다 출력
			{
				std::cout << "경과일: " << simulatedDays << "일 / 성공 횟수: " << successPeople << "회\n";
			}
		}
	}
	// 최종 결과
	std::cout << "------------------------------------------\n";
	std::cout << "시뮬레이션 종료!\n";
	std::cout << "총 " << SIMULATION_DURATION_IN_DAYS << "일 동안 " << successPeople << "번의 강화에 성공했습니다.\n";
}


int main() {
	
	EnhanceSimulation();

	return 0;
}