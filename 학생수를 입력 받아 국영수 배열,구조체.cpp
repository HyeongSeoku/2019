#include<stdio.h>
struct student
{
	char name[10];
	int subject[3];//������
	 
 };
 
int main()
{
    struct student st[3];//3��
	int i,j,a,tota;
	int sum[4],average[4];
	printf("������ �Է��� �л� �� :");scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		printf("�л��̸� :");scanf("%s",(st[i]).name);
		printf("���� ���� :");scanf("%d",&(st[i]).subject[0]);
		printf("���� ���� :");scanf("%d",&(st[i]).subject[1]);
		printf("���� ���� :");scanf("%d",&(st[i]).subject[2]);
		
		sum[i]=(st[i].subject[0]+st[i].subject[1]+st[i].subject[2]);//����
		average[i]=sum[i]/3; 
		tota=average[i]/a;
    }
        for(j=0;j<a;j++)
        {
        printf("======================================================\n");
		printf("%s�� ���� :%d ��� : %d\n",st[j].name,sum[j],average[j]);

    }
     printf("======================================================\n");
        printf("��ü ��� : %d\n",tota);
        printf("======================================================\n");
        return 0;
}
