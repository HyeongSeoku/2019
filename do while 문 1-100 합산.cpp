#include<stdio.h>

int main()
{
	int a,b,i,sum;
	printf("ó������ ������ �Է��Ͻÿ�.");
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
