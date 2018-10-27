#include <stdio.h>

typedef struct
{
	int id;
	char name[50];
	int age;
	double salary;
	int worked;

	
}info_t;

typedef struct
{
	int id;
	char name[50];
	info_t info[10];
}employee_t;

void get_info(FILE *ptr, employee_t *employee)
{
	int i=0;
	int j=0;
	
	while(!feof(ptr))
	{
		fscanf(ptr,"%d %[^\n]s",&employee[j].id,employee[j].name);
		
		for(i=0;i<10;i++)
		{
			fscanf(ptr,"%d %s %d %d",&employee[j].info[i].id,employee[j].info[i].name,&employee[j].info[i].age,&employee[j].info[i].worked);
		}
		j++;
	}
	
	
}

void calculate(employee_t *employee)
{
	
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<10;i++)
	{
		if(employee[j].info[i].worked<40)
		employee[j].info[i].salary=40*2;
		else
		{
			employee[j].info[i].salary=80+ 5*(employee[j].info[i].worked-40);
		}
	}
	
	}
	
}
void display(employee_t *employee)
{
	for(int j=0;j<3;j++)
	{
		printf("INFORMATÝON OF A %s DEPARTMENT \n",employee[j].name);
		printf("ID \t NAME \t AGE \t HOURS WORKED \t SALARY\n ");
		printf("*** \t ***** \t ***** \t ***** \t ***** \t \n");
		
		for(int i=0;i<10;i++)
		{
			printf("%-5d  %-5s  %10d  %10d  %30.2lf\n",employee[j].info[i].id,employee[j].info[i].name,employee[j].info[i].age,employee[j].info[i].worked,employee[j].info[i].salary);
		}
	}
}

int main()
{
	employee_t employee[3];
	
	
	FILE *ptr=fopen("Employee.txt","r");
	
	if(ptr==NULL)
	printf("FILE is not opened!!\n");
	else
	{
		get_info(ptr,employee);
		calculate(employee);
		display(employee);
		
		fclose(ptr);
		
	}
	
	
	
	return 0;
}
