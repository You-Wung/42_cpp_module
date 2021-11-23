#include <stdio.h>
#include <stdlib.h>
void check(int *a, int **b)
{
	printf("2: %p\n",a);
	printf("3: %p\n",*b);

	a = malloc(sizeof(int));
	//*b = malloc(sizeof(int));
	//**b = 123;
}

int main()
{
	int *a = malloc(sizeof(int));
	printf("1: %p\n",a);
	check(a, &a);
	printf("4: %p\n",a);
}