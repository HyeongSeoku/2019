#include<stdio.h>

void hanoi_top(int n ,char from,char temp,char to);

int main()
{
    int top_num;
    printf("하노이 탑의 층수를 입력하세요.");
    scanf("%d",&top_num);
    hanoi_top(top_num,'A','B','C');
}


void hanoi_top(int n,char from,char temp,char to)
{
	if(n==1)
	printf("원판1을 %c에서 %c로 옮기세요\n",from,to);
	else
	{
		hanoi_top(n-1,from,to,temp);
		printf("원판 %d를 %c에서 %c로 옮기세요\n",n,from,to);
		hanoi_top(n-1,temp,from,to); 
	}
}
