#include<stdio.h>

void hanoi_top(int n ,char from,char temp,char to);

int main()
{
    int top_num;
    printf("�ϳ��� ž�� ������ �Է��ϼ���.");
    scanf("%d",&top_num);
    hanoi_top(top_num,'A','B','C');
}


void hanoi_top(int n,char from,char temp,char to)
{
	if(n==1)
	printf("����1�� %c���� %c�� �ű⼼��\n",from,to);
	else
	{
		hanoi_top(n-1,from,to,temp);
		printf("���� %d�� %c���� %c�� �ű⼼��\n",n,from,to);
		hanoi_top(n-1,temp,from,to); 
	}
}
