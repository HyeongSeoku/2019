#include <stdio.h>

int main(void)

{

double total, rate, investment;  //(�ѱ�, ����, ����)

int year, n;    //(�� �ñ�� �Ⱓ, ��� �⵵)

n =1;

printf("������ �Է��ϼ���");

scanf("%lf", &investment);

printf("������ �Է��ϼ���");

scanf("%lf", &rate);

printf("�Ⱓ(��)�� �Է��ϼ���");

scanf("%d", &year);

total = investment;

rate = rate / 100.0; 

printf("����	������\n");

while(year>0)

{

total = total *(1+rate);

printf("%d	%lf\n",n, total);

year--;

n++;

}

return 0;



}


