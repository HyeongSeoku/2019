#include<stdio.h>
struct student
{
	char name[10];
	int subject[3];//국영수
	 
 };
 
int main()
{
    struct student st[3];//3명
	int i,j,a,tota;
	int sum[4],average[4];
	printf("성적을 입력할 학생 수 :");scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		printf("학생이름 :");scanf("%s",(st[i]).name);
		printf("국어 성적 :");scanf("%d",&(st[i]).subject[0]);
		printf("영어 성적 :");scanf("%d",&(st[i]).subject[1]);
		printf("수학 성적 :");scanf("%d",&(st[i]).subject[2]);
		
		sum[i]=(st[i].subject[0]+st[i].subject[1]+st[i].subject[2]);//총합
		average[i]=sum[i]/3; 
		tota=average[i]/a;
    }
        for(j=0;j<a;j++)
        {
        printf("======================================================\n");
		printf("%s의 총점 :%d 평균 : %d\n",st[j].name,sum[j],average[j]);

    }
     printf("======================================================\n");
        printf("전체 평균 : %d\n",tota);
        printf("======================================================\n");
        return 0;
}
