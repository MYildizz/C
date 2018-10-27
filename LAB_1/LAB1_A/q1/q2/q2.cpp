#include <stdio.h>

int main()
{

	FILE *ptr = fopen("bowling.txt", "r");

	if (ptr == NULL)
		printf("file is not opened\n");
	else
	{
		int	arr[10][4], team[10];
		int i = 0, j = 0;

		while (!feof(ptr))
		{
			for (i = 0; i < 10; i++)
			{
				fscanf(ptr, "%d", (team + i));

				for (j = 0; j < 4; j++)
					fscanf(ptr, "%d", (*(arr + i) + j));

					
			}
				

		}

		double teamAvg[10],top=0;

		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 4; j++)
			{
				top += *(*(arr + i) + j);
			}
			*(teamAvg + i) = top / 4.0;
			top = 0;
		}

		printf("Team Number   Average\n");
		printf("**********************\n");

		for (int i = 0; i < 10; i++)
		{
			printf("%d    %.2lf \n", *(team + i), *(teamAvg + i));
		}

		double gameAvg[4],toplam=0;

		printf("Game Number    Average\n");
		printf("**********************\n");

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 10; j++)
			{
				toplam += *(*(arr + j) + i);
			}
			*(gameAvg + i) = toplam / 10.0;
			toplam= 0;
		}

		for (i = 0; i < 4; i++)
			printf("%d %.1lf \n", i + 1, *(gameAvg + i));
			
	}
	return 0;
}