#include <stdio.h>

int recursive(int num,int div)
{
	int sum;
	if(div==1)
	sum=1;
	else
	{
		if(num%div==0)
		sum=div + recursive(num,div-1);
		else
		sum=recursive(num,div-1);
	}
	return sum;
}

int main()
{
	int num;
	
	printf("Enter a number");
	scanf("%d",&num);
	
	int sum=recursive(num,num/2);
	
	if(sum==num)
	printf("This is perfect number \n");
	else
	printf("this is not perfect number\n");
	
	return 0;
}
