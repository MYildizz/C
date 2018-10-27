#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFromFile(FILE *ptr, char arr[][50])
{
	int i = 0;

	while (!feof(ptr))
	{
		fscanf(ptr, " %s", arr[i]);
		i++;
	}
	return i;
}
void updatedirectory(char arr[][50], int i)
{
	int j;
	char temp[50] = {""};
	
	for (j = 0; j<i; j++)
	{
		if (strlen(arr[j])<8)
		{
			strcpy(temp, arr[j]);
			strcpy(arr[j], "(312) ");
			strcat(arr[j], temp);
		}
		else if (strlen(arr[j]) == 10)
		{
			strcpy(temp, "(");
			strncat(temp, arr[j], 3);
			strcat(temp, ") ");
			//temp[4] = {')'};
			strcat(temp, &arr[j][3]);
			strcpy(arr[j], temp);
		}
	}
}
void printdirectory(char arr[][50], int i)
{
	printf("There are %d phone numbers in the directory \n",i);

	for (int j = 0; j<i; j++)
		printf("%s \n", arr[j]);
}

int main()
{
	char arr[10][50];
	int i;

	FILE *ptr = fopen("phones.txt", "r");

	if (ptr == NULL)
		printf("file is not opened!\n");
	else
	{
		i=readFromFile(ptr, arr);
		updatedirectory(arr, i);
		printdirectory(arr, i);
	}


	return 0;
}
