#include<stdio.h>

int main()
{
	int num=0;
	int sum=0;
	int a,b;
	printf("ó�� ���� ������ �Է��Ͻÿ� : ");
	scanf("%d%d",&a,&b);
	do
	{
		num=a++;
		sum+=num;
	 }
	 while(num<b);
	 printf("1~100������ ��:%d\n",sum);
	 return 0;
}
