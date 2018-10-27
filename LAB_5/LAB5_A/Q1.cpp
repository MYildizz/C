#include <stdio.h>

int ackerman(int m,int n)
{
	int k=0;
if(m==0)
{
	n=n+1;
	return n;
}
else if(m>0 && n==0)
ackerman(m-1,1);
else if(m>0 && n>0)
ackerman(m-1,ackerman(m,n-1));
}

int main()
{
	int n,m;
	
	printf("Enter the value of m: ");
	scanf("%d",&m);
	printf("\n Enter the value of n: ");
	scanf("%d",&n);
	
	printf("\nThe result is : %d \n",ackerman(m,n));
	
	return 0;
}
