#include <stdio.h>

int main(void)
{
	int total_seconds;
	int hour, min, sec;
	printf("총 시간을 초 단위로 입력하세요: ");
	scanf_s("%d", &total_seconds);
	hour = total_seconds / 3600;
	min = (total_seconds % 3600) / 60;
	sec = total_seconds % 60;
	printf("%d초는 %d시간 %d분 %d초입니다.\n", total_seconds, hour, min, sec);
	printf("디지털 표기:%02d:%02d:%02d\n", hour, min, sec);
	return 0;
}