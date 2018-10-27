#include <stdio.h>

typedef struct
{
	char name[50],
	surname[50],
	date[50],
	brand[100];
}info_t;

int main()
{
	
	info_t info[10];
	int i=0;
	
	FILE *ptr=fopen("customers.txt","r");
	
	if(ptr==NULL)
	printf("file is not opened!\n");
	else
	{
		while(!feof(ptr))
{
	fscanf(ptr,"%s %[^-]--%[^-]--%[^\n]s",info[i].name,info[i].surname,info[i].date,info[i].brand);
	i++;
}

for(int j=0;j<i;j++)
{
	info[j].name[1]='.';
	info[j].name[2]='\0';
	
	info[j].date[5]='\0';
	
}

for(int j=0;j<i;j++)
{
	printf("%5s %-5s %-20s ",info[j].date,info[j].name,info[j].surname);
	printf("%5s\n",info[j].brand);
}

	}
	
	return 0;
}
