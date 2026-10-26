#include <stdio.h>
// 표준 입출력 함수(printf, scanf_s, getchar 등)를 사용하기 위한 헤더 파일 포함

int main(void)
// 프로그램 실행 시 가장 먼저 호출되는 메인 함수 시작
{
	int initial_energy = 0;
	// 초기 엔진 에너지(시작 정수)를 저장할 변수 선언 및 0으로 초기화

	// 올바른 양의 정수가 입력될 때까지 무한 반복하는 입력 검증 루프
	while (1)
	{
		printf("Enter the initial engine energy: ");
		// 사용자에게 초기 엔진 에너지 입력 요청 메시지 출력

		int result = scanf_s("%d", &initial_energy);
		// scanf_s 결과를 저장 (성공 시 1 반환, 문자 입력 또는 정수형 초과 시 0/EOF 반환)

		// 1. 사용자 강제 종료(Ctrl+Z 또는 Ctrl+D) 예외 처리
		if (result == EOF)
		{
			printf("\nProgram terminated by user.\n"); // 종료 안내 메시지 출력
			return 0; // 프로그램 정상 종료
		}

		// 2. 문자 입력 또는 정수 입력 형식 실패 예외 처리
		if (result != 1)
		{
			printf("Invalid input! Please enter a positive integer.\n"); // 경고 메시지 출력
			while (getchar() != '\n'); // 입력 버퍼 초기화 (남아있는 잘못된 문자 제거)
			continue; // 반복문의 처음으로 돌아가 재입력 받음
		}

		// 3. 실수(소수점) 입력 방지 예외 처리
		char c = getchar(); // 정수 입력 뒤에 남아있는 문자를 1개 읽어옴
		if (c != '\n' && c != EOF)
		{
			printf("Invalid input! Floating point numbers or extra characters are not allowed.\n"); // 실수 입력 경고
			while (getchar() != '\n'); // 개행 문자가 나올 때까지 버퍼 전체 비우기
			continue; // 반복문의 처음으로 돌아가 재입력 받음
		}

		// 4. 0 이하의 값(음수 및 0) 예외 처리
		// (콜라츠 추측 공식은 양의 정수에서만 작동하며, 0 또는 음수 입력 시 무한 루프 발생)
		if (initial_energy <= 0)
		{
			printf("Initial energy must be a positive integer (greater than 0).\n"); // 경고 메시지 출력
			continue; // 반복문의 처음으로 돌아가 재입력 받음
		}

		break; // 모든 예외 검사를 통과한 유효한 양의 정수이면 무한 루프 탈출
	}

	printf("Sequence: %d", initial_energy);
	// 수열 계산 시작을 알리며 첫 번째 초기 에너지 값 출력

	int steps = 0;
	// 총 도달 단계(횟수)를 저장할 변수 선언 및 0으로 초기화
	int max_altitude = initial_energy;
	// 도달한 최고 고도(최대값)를 저장할 변수 선언 및 초기 에너지 값으로 설정

	// initial_energy가 1에 도달할 때까지 우주선 이탈 수열(콜라츠 추측) 반복 실행
	while (initial_energy != 1)
	{
		if (initial_energy % 2 == 0)
			// 에너지가 짝수인 경우 조건 확인
		{
			initial_energy = initial_energy / 2;
			// 짝수일 경우 에너지를 2로 나눔

			if (initial_energy > max_altitude)
				// 현재 에너지가 기존 최고 고도보다 높은지 확인
			{
				max_altitude = initial_energy;
				// 최고 고도를 현재 에너지로 갱신
			}
		}
		else
			// 에너지가 홀수인 경우
		{
			// 오버플로우 방지: (initial_energy * 3 + 1) 계산 전 32비트 signed int 최대값(2,147,483,647) 초과 여부 검사
			if (initial_energy > (2147483647 - 1) / 3)
			{
				printf("\n\nError: Energy value exceeded integer limit (Overflow)!\n"); // 오버플로우 에러 출력
				return 1; // 프로그램 비정상 종료 코드 반환
			}

			initial_energy = (initial_energy * 3) + 1;
			// 홀수일 경우 에너지를 3배하고 1을 더함

			if (initial_energy > max_altitude)
				// 현재 에너지가 기존 최고 고도보다 높은지 확인
			{
				max_altitude = initial_energy;
				// 최고 고도를 현재 에너지로 갱신
			}
		}

		printf(" -> %d", initial_energy);
		// 계산된 다음 에너지 값을 수열 형태로 출력
		steps++;
		// 실행 단계(단계 수) 1 증가
	}

	printf("\nEscape successful!\n");
	// 탈출 성공 안내 메시지 출력
	printf("Total steps: %d\n", steps);
	// 1에 도달하기까지 걸린 총 단계 수 출력
	printf("Maximum altitude reached: %d\n", max_altitude);
	// 시뮬레이션 과정 중 도달한 최고 고도 출력

	return 0;
	// 프로그램 정상 종료 (메인 함수 반환 값 0)
}