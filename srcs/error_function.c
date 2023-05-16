#include "../include/main.h"

void	error_exit(char *str)
{
	//메모리 해제 함수 추가할 것.
	printf("Error\n");
	printf("%s", str);
	exit(1);
}