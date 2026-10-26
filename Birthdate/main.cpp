#include <stdio.h>
// 표준 입출력 함수(printf, scanf_s 등)를 사용하기 위한 헤더 파일 포함

int main(void)
// 프로그램 실행 시 가장 먼저 호출되는 메인 함수 시작
{
	int birthdate;
	// 사용자가 입력할 8자리 생년월일을 저장하는 정수형 변수 선언

	while (1)
		// 올바른 8자리 생년월일이 입력될 때까지 무한 반복하는 루프
	{
		printf("Enter your 8-digit birthdate (YYYYMMDD): ");
		// 사용자에게 생년월일 입력 요청 메시지 출력

		int result = scanf_s("%d", &birthdate);
		// 입력 결과를 저장 (성공 시 1 반환, 문자/오버플로우 시 0 또는 EOF 반환)

		// 1. 강제 종료(Ctrl+Z/Ctrl+D) 예외 처리
		if (result == EOF)
		{
			printf("\nProgram terminated by user.\n");
			return 0;
		}

		// 2. 문자 입력, 정수 오버플로우 등 입력 형식 오류 예외 처리
		if (result != 1)
		{
			printf("Invalid input! Please enter an 8-digit number only.\n");
			while (getchar() != '\n'); // 입력 버퍼 초기화
			continue;
		}

		// 3. 실수 및 남아있는 입력 검사 (소수점 입력 방지)
		char c = getchar();
		if (c != '\n' && c != EOF)
		{
			printf("Invalid input! Floating point numbers or extra characters are not allowed.\n");
			while (getchar() != '\n'); // 줄바꿈 문자까지 버퍼 비우기
			continue;
		}

		// 4. 음수 및 자릿수(8자리) 범위 확인 (10,000,000 ~ 99,999,999)
		if (birthdate < 10000000 || birthdate > 99999999)
		{
			printf("Please enter a valid '8-digit' birthdate (e.g. 19990101).\n");
			continue;
		}

		// 5. 실제 존재하지 않는 날짜(월/일) 유효성 예외 처리
		int year = birthdate / 10000;
		int month = (birthdate % 10000) / 100;
		int day = birthdate % 100;

		// 월(Month) 검사 (1~12월)
		if (month < 1 || month > 12)
		{
			printf("Invalid month! Month must be between 01 and 12.\n");
			continue;
		}

		// 각 월의 마지막 날짜 정의
		int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// 윤년 계산 (4년마다 윤년, 100년 단위 제외, 400년 단위 포함)
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			daysInMonth[2] = 29;
		}

		// 일(Day) 검사 (1일 ~ 해당 월의 마지막 날)
		if (day < 1 || day > daysInMonth[month])
		{
			printf("Invalid day! Please check the date for %04d-%02d.\n", year, month);
			continue;
		}

		break; // 모든 예외 검사를 통과한 유효한 날짜이면 무한 루프 탈출
	}

	printf("Calculating...\n");
	// 계산을 시작한다는 안내 메시지 출력

	int sum_digit = 0;
	// 각 자리 숫자의 합을 누적 저장할 변수 선언 및 0으로 초기화
	int remainder;
	// 각 자릿수를 10으로 나눈 나머지(현재 맨 뒷자리 숫자)를 저장할 변수 선언

	while (birthdate > 0)
		// birthdate의 자릿수가 남아있는 동안 반복 (0보다 클 때까지)
	{
		remainder = birthdate % 10;
		// birthdate를 10으로 나눈 나머지(마지막 자릿수)를 구함
		sum_digit = sum_digit + remainder;
		// 구해진 자릿수를 sum_digit에 더해서 누적함
		birthdate = birthdate / 10;
		// birthdate를 10으로 나눠서 마지막 자릿수를 제거함
	}
	printf("Sum of digits: %d\n", sum_digit);
	// 1차로 계산된 자릿수들의 합을 출력

	while (1)
		// 자릿수의 합이 한 자리가 될 때까지 줄여나가는 무한 반복 루프
	{
		if (sum_digit < 10)
			// sum_digit이 한 자리 숫자(10 미만)가 되었는지 먼저 확인
		{
			break;
			// 한 자리 숫자가 되면 반복 루프 탈출
		}

		sum_digit = sum_digit % 10 + sum_digit / 10;
		// 10의 자리 숫자와 1의 자리 숫자를 더해서 sum_digit을 갱신함
		printf("Sum of digits: %d\n", sum_digit);
		// 중간 계산 결과(각 자릿수의 합)를 출력
	}

	printf("Your Destiny Number is %d!\n\n", sum_digit); // 최종 계산된 운명의 숫자(Destiny Number) 출력

	printf("[Destiny Message]\n"); // 운명의 메시지 헤더 출력

	switch (sum_digit)
		// 계산된 운명의 숫자(sum_digit)의 값에 따라 해당하는 메시지를 선택
	{
	case 1: // 숫자가 1인 경우
		printf("Good luck is coming your way!\n"); // 행운 메시지 출력
		break; // switch 문 탈출
	case 2: // 숫자가 2인 경우
		printf("A new opportunity will soon appear!\n"); // 새로운 기회 메시지 출력
		break; // switch 문 탈출
	case 3: // 숫자가 3인 경우
		printf("Today is the perfect day to try something new!\n"); // 새로운 도전에 대한 메시지 출력
		break; // switch 문 탈출
	case 4: // 숫자가 4인 경우
		printf("Someone special may enter your life soon!\n"); // 특별한 사람에 대한 메시지 출력
		break; // switch 문 탈출
	case 5: // 숫자가 5인 경우
		printf("Your hard work will soon pay off!\n"); // 노력이 결실을 맺는다는 메시지 출력
		break; // switch 문 탈출
	case 6: // 숫자가 6인 경우
		printf("Unexpected happiness is waiting for you!\n"); // 뜻밖의 행복 메시지 출력
		break; // switch 문 탈출
	case 7: // 숫자가 7인 경우
		printf("Trust your instincts and follow your heart!\n"); // 직관과 마음에 관한 메시지 출력
		break; // switch 문 탈출
	case 8: // 숫자가 8인 경우
		printf("A small change will bring great results!\n"); // 작은 변화와 큰 결과에 대한 메시지 출력
		break; // switch 문 탈출
	case 9: // 숫자가 9인 경우
		printf("Good things happen when you stay positive!\n"); // 긍정적인 마음에 대한 메시지 출력
		break; // switch 문 탈출
	}
	return 0; // 프로그램 정상 종료 (메인 함수 반환 값 0)
}
