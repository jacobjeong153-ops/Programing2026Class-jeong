#include <stdio.h>

int main(void)
{
	int total_seconds;
	int hour, min, sec;
	printf("Enter total time in seconds: ");
	scanf_s("%d", &total_seconds);
	hour = total_seconds / 3600;
	min = (total_seconds % 3600) / 60;
	sec = total_seconds % 60;
	printf("%d seconds is %d hour(s) %d minute(s) %d second(s).\n", total_seconds, hour, min, sec);
	printf("Digital Format :%02d:%02d:%02d\n", hour, min, sec);
	return 0;
}