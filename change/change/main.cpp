#include <stdio.h>

int main(void)
{
	int pay_fee, get_fee, number, total_pay_fee, change;
	printf("상품 단가(원): ");
	scanf_s("%d", &pay_fee);
	printf("수령(개): ");
	scanf_s("%d", &number);
	printf("\n");

	printf("합계 금액  : %d원\n", pay_fee * number);
	printf("할인(10%) : %d원\n", -pay_fee * number / 10);
	printf("결제 금액  : %d원\n", pay_fee * number - pay_fee * number / 10);
	printf("\n");
	
	total_pay_fee = pay_fee * number - pay_fee * number / 10;

	printf("받은 금액(원): ");
	scanf_s("%d", &get_fee);
	printf("거스름돈  : %d원\n", get_fee - total_pay_fee);

	change = get_fee - total_pay_fee;

	printf(" 1000원권 : %d장\n", change / 1000);
	printf("  500원권  : %d장\n", change % 1000 / 500);
	printf("  100원권  : %d장\n", change % 1000 % 500 / 100);
	printf("   50원권  : %d장\n", change % 100 / 50);
	printf("  나머지  : %d장\n", change % 100 % 50);
	
	return 0;
}