#include <stdio.h>

int main(void)

{

double total, rate, investment;  //(총금, 이율, 원금)

int year, n;    //(돈 맡기는 기간, 출력 년도)

n =1;

printf("원금을 입력하세요");

scanf("%lf", &investment);

printf("이율을 입력하세요");

scanf("%lf", &rate);

printf("기간(년)을 입력하세요");

scanf("%d", &year);

total = investment;

rate = rate / 100.0; 

printf("연도	원리금\n");

while(year>0)

{

total = total *(1+rate);

printf("%d	%lf\n",n, total);

year--;

n++;

}

return 0;



}


