#include <stdio.h>

int main(void)
{
	int total_second;
	int sec, min, hour;

	printf("총 시간을 초 단위로 입력하세요: ");
	scanf_s("%d", &total_second);

	sec = total_second / 3600;
	min= (total_second%60)/60
	printf("%d초는 .\n", total_second);

	return 0;
}