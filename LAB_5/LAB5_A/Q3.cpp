#include <stdio.h>

typedef struct
{
	char name[30];
	int age;
	double gpa;
}stu_t;

int menu()
{
	int num;
	
	printf("1) Go to record X from top\n");
	printf("2) Move X records ahead \n");
	printf("3) Go X records back from bottom \n");
	printf("4) Exit \n");
	scanf("%d",&num);
	
	while(num<1 || num>4)
	{
		printf("Again choice ");
		scanf("%d",&num);
	}
	return num;
}

int main()
{
	stu_t stu,num;
	int choice,x;
	
	FILE *ptr2=fopen("info.txt","r");
	FILE *ptr1=fopen("binary.bin","wb");
	
	if(ptr2==NULL || ptr1==NULL)
	printf("ERROR!");
	else
	{
		while(!feof(ptr2))
		{
			fscanf(ptr2,"%s %d %lf",stu.name,&stu.age,&stu.gpa);
			fwrite(&stu,sizeof(stu_t),1,ptr1);
		}
		fclose(ptr1);
		fclose(ptr2);
		
		ptr1=fopen("binary.bin","rb");
		
		choice=menu();
		
		switch(choice)
		{
			case 1:
				printf("Enter X");
				scanf("%d",&x);
				
				fseek(ptr1,sizeof(stu_t)*(x-1),SEEK_SET);
				fread(&num,sizeof(stu_t),1,ptr1);
				
				printf("%s %d %.2lf\n",num.name,num.age,num.gpa);
				break;
				case 2:
					printf("Enter X");
					scanf("%d",&x);
					fseek(ptr1,sizeof(stu_t)*(x-1),SEEK_CUR);
					fread(&num,sizeof(stu_t),1,ptr1);
					printf("%s %d %lf \n",num.name,num.age,num.gpa);
					break;
					case 3:
					printf("Enter X");
					scanf("%d",&x);
					fseek(ptr1,sizeof(stu_t)*(-x),SEEK_END);
					fread(&num,sizeof(stu_t),1,ptr1);
					printf("%s %d %lf \n",num.name,num.age,num.gpa);
					break;
					case 4:
						break;
						default:
							break;
				
		}
		
	}
	
	return 0;
}
