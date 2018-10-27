#include <stdio.h>

int main()
{

	FILE *ptr = fopen("result.txt", "w");

	int arr[10];

	for (int i = 0; i < 10; i++)
		*(arr + i) = 10 * (i + 1);

	fprintf(ptr, "Element Name    Value      Adreess\n  ");
	fprintf(ptr,"---------------       ------    ---------\n");

	for (int i = 0; i < 10; i++)
	{
		fprintf(ptr, "*(nums+i)    %d     %p\n", *(arr + i), (arr + i));
	}

	return 0;
}