#include<stdio.h>

int main()
{
	int a,b,i,sum;
	printf("처음수와 끝수를 입력하시오.");
	scanf("%d %d",&a,&b);
	do
	{
		for(i=a;i<=b;i++)
		{
			sum+=i;
		}
	}
	
	while(sum>5051);
	printf("%d",sum);
}
