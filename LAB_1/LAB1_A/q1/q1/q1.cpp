#include <stdio.h>

int main()
{

	FILE *ptr = fopen("num.txt", "r");

	int i = 0, j = 0;
	int status;

	if (ptr == NULL)
		printf("error\n");
	else
	{


		int arr[4][4],diagonal[4];



		while (!feof(ptr))
		{

			for (i = 0; i<4; i++)
				fscanf(ptr, "%d", (*(arr + j) + i));
				j++;

		};


		printf("Matrix is:\n");

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%5d ", *(*(arr + i) + j));

			}

			printf("\n");
		}
			
		printf("\n\ndiagonal is: ");
		for (int i = 0; i < 4; i++)
			{
				*(diagonal + i) = *(*(arr + i) + i);
				printf("%5d ", *(diagonal + i));
			}
		printf("\n");

		int max=**arr;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (*(*(arr + j) + i) > max)
					max = *(*(arr + j) + i);
			}
			

		}

		printf("\nThe maksimum number is: %d", max);
		printf("\n\n");

		int top=1;

		for (int i = 0; i < 4; i++)
		{
			top *= diagonal[i];
			
		}
		printf("Total product : %d", top);
				
	}

	return 0;
}