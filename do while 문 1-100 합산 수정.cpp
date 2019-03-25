#include<stdio.h>

int main()
{
	int num=0;
	int sum=0;
	int a,b;
	printf("처음 수와 끝수를 입력하시오 : ");
	scanf("%d%d",&a,&b);
	do
	{
		num=a++;
		sum+=num;
	 }
	 while(num<b);
	 printf("1~100까지의 합:%d\n",sum);
	 return 0;
}
