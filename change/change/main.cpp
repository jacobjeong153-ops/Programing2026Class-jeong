#include <stdio.h>

int main(void)
{
	int pay_fee, get_fee, number, total_pay_fee, change;
	printf("Unit Price (KRW): ");
	scanf_s("%d", &pay_fee);
	printf("Quantity: ");
	scanf_s("%d", &number);
	printf("\n");

	printf("Subtotal  : %dKRW\n", pay_fee * number);
	printf("Discount(10%) : %dKRW\n", -pay_fee * number / 10);
	printf("Total Payable  : %dKRW\n", pay_fee * number - pay_fee * number / 10);
	printf("\n");
	
	total_pay_fee = pay_fee * number - pay_fee * number / 10;

	printf("Amount Paid (KRW): ");
	scanf_s("%d", &get_fee);
	printf("Change Due  : %dKRW\n", get_fee - total_pay_fee);

	change = get_fee - total_pay_fee;

	printf(" 1,000 KRW bills : %d\n", change / 1000);
	printf("  500 KRW coins  : %d\n", change % 1000 / 500);
	printf("  100 KRW coins  : %d\n", change % 1000 % 500 / 100);
	printf("   50 KRW coins  : %d\n", change % 100 / 50);
	printf("  Remaining  : %dKRW\n", change % 100 % 50);
	
	return 0;
}