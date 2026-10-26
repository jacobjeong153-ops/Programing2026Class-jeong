#include <stdio.h>
// 표준 입출력 함수(printf, scanf_s, getchar 등)를 사용하기 위한 헤더 파일 포함

// 매크로 상수를 이용한 아이템 가격 정의 (가독성 및 유지보수성 향상)
#define Red_Potion   1000
#define Magic_Scroll 2000
#define Elixir       3000

int main(void)
// 프로그램 실행 시 가장 먼저 호출되는 메인 함수 시작
{
	int count = 0;
	// 총 성공적인 구매 횟수를 저장할 변수 선언 및 0으로 초기화 (3번째 구매 시 50% 할인 판정에 사용)
	int Balance = 0;
	// 사용자의 잔액(골드)을 저장할 정수형 변수 선언

	// -------------------------------------------------------------------------
	// [1. 초기 잔액(Coins) 입력 및 예외 처리 루프]
	// -------------------------------------------------------------------------
	while (1)
	{
		printf("Insert coins (Current Balance): ");
		// 사용자에게 초기 투입 금액 입력 요청 메시지 출력

		int result = scanf_s("%d", &Balance);
		// scanf_s 결과를 저장 (성공 시 1 반환, 문자 입력 또는 정수 초과 시 0/EOF 반환)

		// 1-1. 사용자 강제 종료(Ctrl+Z 또는 Ctrl+D) 예외 처리
		if (result == EOF)
		{
			printf("\nProgram terminated by user.\n");
			return 0; // 프로그램 정상 종료
		}

		// 1-2. 문자 입력 또는 정수 입력 형식 실패 예외 처리
		if (result != 1)
		{
			printf("Invalid input! Please enter a valid number.\n");
			while (getchar() != '\n'); // 입력 버퍼 초기화 (남아있는 비정상 문자 제거)
			continue; // 재입력 요청
		}

		// 1-3. 실수(소수점) 입력 방지 예외 처리
		char c = getchar();
		if (c != '\n' && c != EOF)
		{
			printf("Invalid input! Floating point numbers or extra characters are not allowed.\n");
			while (getchar() != '\n'); // 줄바꿈 문자가 나올 때까지 버퍼 비우기
			continue; // 재입력 요청
		}

		// 1-4. 음수(0 미만) 금액 입력 차단 예외 처리
		if (Balance < 0)
		{
			printf("Balance cannot be negative! Please enter a positive amount.\n");
			continue; // 재입력 요청
		}

		break; // 모든 예외 검사를 통과한 유효한 잔액이면 초기 입력 루프 탈출
	}

	// 자판기 메뉴판 출력
	printf("\n\n--- Goblin's Vending Machine ---\n");
	printf("1. Red Potion (%d G)\n", Red_Potion);
	printf("2. Magic Scroll (%d G)\n", Magic_Scroll);
	printf("3. Elixir (%d G)\n", Elixir);
	printf("0. Exit\n");
	printf("--------------------------------\n\n");

	// -------------------------------------------------------------------------
	// [2. 아이템 선택 및 구매 반복 처리 루프]
	// -------------------------------------------------------------------------
	while (1)
	{
		int select_num = 0;
		// 사용자가 선택한 메뉴 번호를 저장할 변수 선언

		printf("Select an item: ");
		// 메뉴 선택 요청 메시지 출력

		int result = scanf_s("%d", &select_num);
		// 메뉴 선택 입력 결과를 저장

		// 2-1. 메뉴 선택 시 강제 종료(Ctrl+Z 또는 Ctrl+D) 예외 처리
		if (result == EOF)
		{
			printf("\nProgram terminated by user. Returning remaining balance: %d G\n", Balance);
			return 0;
		}

		// 2-2. 메뉴 선택 시 문자 입력 예외 처리
		if (result != 1)
		{
			printf("Invalid selection! Please enter a number (0~3).\n\n");
			while (getchar() != '\n'); // 입력 버퍼 비우기
			continue; // 루프 상단으로 이동하여 재입력
		}

		// 2-3. 메뉴 선택 시 실수 및 추가 입력 문자 검사 예외 처리
		char c = getchar();
		if (c != '\n' && c != EOF)
		{
			printf("Invalid selection! Please enter a single integer (0~3).\n\n");
			while (getchar() != '\n'); // 버퍼 클리어
			continue; // 재입력
		}

		// 2-4. 메뉴 범위를 벗어난 번호 입력 예외 처리 (0~3 외의 숫자)
		if (select_num < 0 || select_num > 3)
		{
			printf("Invalid menu option! Please select between 0 and 3.\n\n");
			continue; // 재입력
		}

		// -------------------------------------------------------------------------
		// [3. 아이템별 가격 설정 및 공통 구매/할인 로직 처리]
		// -------------------------------------------------------------------------

		// 3-1. 0번 선택 시 프로그램 종료 및 잔액 반환
		if (select_num == 0)
		{
			printf("Returning %d G. Goodbye!\n", Balance);
			break; // 자판기 무한 루프 탈출
		}

		int price = 0;                   // 선택한 아이템의 정가 저장 변수
		const char* item_name = "";      // [수정] const char* 형태로 선언하여 상수 문자열 대입 오류 해결

		// 선택한 번호에 따라 아이템 이름과 가격 매핑
		if (select_num == 1)
		{
			item_name = "Red Potion";
			price = Red_Potion;
		}
		else if (select_num == 2)
		{
			item_name = "Magic Scroll";
			price = Magic_Scroll;
		}
		else if (select_num == 3)
		{
			item_name = "Elixir";
			price = Elixir;
		}

		// 3-2. 구매 건수 판정 (3번째 구매 시 50% 할인 적용)
		// count가 2, 5, 8... 일 때 (count % 3 == 2) 50% 고블린의 축복 할인 적용
		int actual_price = price;
		int is_discounted = 0; // 할인 여부 플래그 (0: 정가, 1: 50% 할인)

		if (count % 3 == 2)
		{
			actual_price = (int)(price * 0.5); // 50% 할인 가격 계산
			is_discounted = 1;
		}

		// 3-3. 잔액 부족 예외 처리 (실제 지불해야 하는 금액과 잔액 비교)
		if (Balance < actual_price)
		{
			printf("Not enough balance! (Required: %d G, Current Balance: %d G)\n\n", actual_price, Balance);
			continue; // 잔액이 부족하면 구매 횟수(count)를 증가시키지 않고 루프 재선택
		}

		// 3-4. 차감 및 결제 처리
		Balance = Balance - actual_price; // 잔액 차감

		// 할인 여부에 따른 결제 메시지 출력
		if (is_discounted)
		{
			printf("*** GOBLIN'S BLESSING! 50%% DISCOUNT! ***\n");
			printf("[Purchased] %s for %d G. Balance: %d G\n\n", item_name, actual_price, Balance);
		}
		else
		{
			printf("[Purchased] %s. Balance: %d G\n\n", item_name, Balance);
		}

		count++; // 구매 성공 시에만 구매 횟수 1 증가
	}

	return 0; // 프로그램 정상 종료 (메인 함수 반환 값 0)
}