#include <stdio.h>
#include <string.h>

typedef struct
{
	int id;
	char name[30],
	surname[30];
	int salary;
}employe_t;



int main()
{
	employe_t employe,arr[50];
	int i=0;
	
	
	FILE *ptr1=fopen("Employee.txt","r");
	FILE *ptr=fopen("binary.bin","wb");
	
	if(ptr1==NULL || ptr==NULL )
	printf("file ist not opened\n");
	else
	{
		while(!feof(ptr1))
		{
			fscanf(ptr1,"%d %s %s %d",&employe.id,employe.name,employe.surname,&employe.salary);
			fwrite(&employe,sizeof(employe_t),1,ptr);
			i++;
		}
		
		fclose(ptr1);
		fclose(ptr);
		
		ptr=fopen("binary.bin","rb");
		
		fread(arr,sizeof(employe_t),i,ptr);
		
		for(int k=0;k<i;k++)
		{
		printf("%d %s %s %d \n",arr[k].id,arr[k].name,arr[k].surname,arr[k].salary);	
		}
		
	
		
	
		

		

	
	return 0;
}
}
