#include <stdio.h>

int main()
{

	FILE *ptr = fopen("input.txt", "r");

	if (ptr == NULL)
		printf("file is not opened\n");
	else
	{
		int city[4],degree[4][5];

		int i = 0,j = 0;

		while (!feof(ptr))
		{
			fscanf(ptr, "%d", (city + i));
			for (j = 0; j < 5; j++)
				fscanf(ptr, "%d", (*(degree + i) + j));
			i++;
		}

		int max = **degree,k=0,year=2012;

		for(i=0;i<4;i++)
			for (j = 0; j < 5; j++)
			{
				if (*(*(degree + i) + j) > max)
				{
					max = *(*(degree + i) + j);
					k = i;
					year = 2012 + k;
				}
					
			}

		printf("Average highest degree is: %d \n ",max);
		printf("Year: %d\n", year);
		printf("City: 0%d\n", *(city + k));

		int total[4], top = 0;;

		for (int i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				top += *(*(degree + i) + j);
			}
			*(total + i) = top;
			top = 0;
		}

		printf("City   Total\n");

		for (int i = 0; i < 4; i++)
			printf("%5d %5d\n",*(city + i), *(total + i));


	}

	



	

	return 0;
}