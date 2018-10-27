#include <stdio.h>

int main() {

	FILE *ptr=fopen("num.txt","r");

	int i=0,j=0;
	int status;

	if(ptr==NULL)
		return 0;
	else {


		int arr[4][4];



		while(!feof(ptr)) {

			for(i=0; i<4; i++)
				fscanf(ptr,"%d",(*arr +j)+i));
				j++;

			}


		printf("Matrix is:\n");

		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				printf("%5d ",*(*(arr+i)+j));
	}

	return 0;
}
