/*구단 관리 프로그램*/  
#include<Stdio.h>
#include<string.h>
#include<windows.h>

struct club
{
    char name[10];
	double perinfo[4];//신상정보:출생년도,키,몸무게,주급 
	char condition[10];//출전가능 여부
	char position[10];//포지션 
};

void menu();
void inputFunc(struct club* st);//입력함수 
void outputFunc(struct club* st);//출력함수 
int ranking(struct club* st,int tmp);//순위함수 
void modFunc(struct club* st);
void delFunc(struct club* st);
int searchFunc(struct club* st);//검색 
void sortFunc(struct club* st);

int main()
{
	struct club st[30];//선수 30명
	int selMenu,i,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<5;j++)
		
		(st[i].perinfo[j]=-1);
		
	}
	while(1)
{
		system("cls");
		menu();
		printf("선택하세요 > ");	scanf("%d", &selMenu);
		fflush(stdin);
		system("cls");//clean screen
		switch(selMenu)//메뉴 선택. 
		{
		case 1:
			inputFunc(st);
			break;
		case 2:
			outputFunc(st);
			break;
		case 3:
			modFunc(st);
			break;
		case 4:
			delFunc(st);
			break;
		case 5:
			sortFunc(st);
			break;
		case 0:
			printf("프로그램을 종료하겠습니다.\n");
			return 0;
		default:
			break;
		}
		system("pause");
	}
	return 0;
 } 
 
 void menu()
 {
    printf("┏━━━━━━━━━━━━━┓\n");
    printf("┃    구단관리 프로그램     ┃\n");
    printf("┃                          ┃\n");
    printf("┃       1. 입   력         ┃\n");
    printf("┃       2. 출   력         ┃\n");
    printf("┃       3. 수   정         ┃\n");
    printf("┃       4. 삭   제         ┃\n");
    printf("┃       5. 정   렬         ┃\n");
    printf("┃       0. 종   료         ┃\n");
    printf("┃                          ┃\n");
    printf("┗━━━━━━━━━━━━━┛\n");
}

void inputFunc(struct club* st)
{
	int i;
	printf("▤▤ 입력 ▤▤ \n");
	for(i=0;i<10;i++)
	{
		if((*(st+i)).perinfo[0] == -1)
		{
			break;
		}
	}
	
	printf("이름 : ");		scanf("%s",(*(st+i)).name);
	fflush(stdin);
	printf("출생 년도 : ");	scanf("%d",&(*(st+i)).perinfo[0]);
	printf("       키 : ");	scanf("%d",&(*(st+i)).perinfo[1]);
	printf("   몸무게 : ");	scanf("%d",&(*(st+i)).perinfo[2]);
	printf("     주급 : ");	scanf("%d",&(*(st+i)).perinfo[3]);
	printf("   포지션 : "); scanf("%s",(*(st+i)).position);
	printf("출전 가능 : ");	scanf("%s",(*(st+i)).condition);
	
	
	fflush(stdin);//\n 비움. 
}

void outputFunc(struct club* st)
{
	int i;
	int sum = 0;
	printf("▤▤ 출력 ▤▤ \n");
	printf(" %8s | %5s | %5s | %5s | %5s | %5s | %6s | %4s |\n","이름","년도","키","몸무게","주급","포지션","출전가능여부","순위");
	for(i=0;i<30;i++)
	{
            if((*(st+i)).perinfo[0] != -1)
            {
			printf(" %8s | %5d | %5d | %6d | %6d | %5s | %11s | %4d | \n"
				,(*(st+i)).name,(*(st+i)).perinfo[0],(*(st+i)).perinfo[1],(*(st+i)).perinfo[2],(*(st+i)).perinfo[3],(*(st+i)).position,(*(st+i)).condition,ranking(st,i));
		}
	}
}


int ranking(struct club* st,int tmp)
{
	int rank=1;
	int i;
	float a;
	float a1;
	for(i=0;i<30;i++)
	{
		a=(*(st+i)).perinfo[3];
		a1=(*(st+tmp)).perinfo[3];
			if(a<a1)
			{
				rank++;
			}
		}
		

	return rank;
}

void modFunc(struct club* st)
{
    int i;
    
    printf("▤▤ 수정 ▤▤ \n");
	printf("수정 할 이름 > ");
	if((i = searchFunc(st)) >= 0)
	{
		printf("출생 년도 : ");scanf("%d",&(*(st+i)).perinfo[0]);
		printf("키 : ");scanf("%d",&(*(st+i)).perinfo[1]);
		printf("몸무게 : ");scanf("%d",&(*(st+i)).perinfo[2]);
		printf("주급 : ");scanf("%d",&(*(st+i)).perinfo[3]);
		printf("포지션 : ");scanf("%s",(*(st+i)).position);
		printf("출전 : ");scanf("%s",(*(st+i)).condition);
		fflush(stdin);
	}
	else
	{
		printf(" 해당 이름이 없습니다 \n");
		printf(" 메뉴로 돌아가겠습니다 \n");
	}
}


void delFunc(struct club* st)
{
	int i,j;
    
    printf("▤▤ 삭제 ▤▤ \n");
    printf("삭제 할 이름 > ");
    if((i=searchFunc(st)) >= 0)
    {
        for(j=0;j<4;j++)
        { 
           (*(st+i)).perinfo[j] = -1;
	  }
    }
    else
    {
        printf(" 해당 이름이 없습니다 \n");
        printf(" 메뉴로 돌아가겠습니다 \n");
    }

}

int searchFunc(struct club* st)
{
	int i;
	char selName[10];

	scanf("%s",selName);
	fflush(stdin);
	for(i=0; i<10; i++)
	{
		if(strcmp(selName, (*(st+i)).name) == 0)
			return i;
	}
	return -1;
}

void sortFunc(struct club* st)
{
	int i,j;
	int sum=0, sum1=0, sum2=0;
	struct club tmpSt;
    
	for(i=0;i<9;i++)
	{
	    for(j=i+1;j<4;j++)
	    {
	        sum1 = (*(st+i)).perinfo[3];
	        sum2 = (*(st+j)).perinfo[3];
			if(sum1 < sum2)
			{
				tmpSt = st[i];
				st[i] = st[j];
				st[j] = tmpSt;
			}
    	}
	}
	
	printf("▤▤ 정렬 ▤▤ \n");
    printf(" %8s | %5s | %5s | %5s | %5s | %4s | %10s | \n","이름","국어","영어","수학","과학","순위","주소");
	for(i=0;i<10;i++)
	{
		if((*(st+i)).perinfo[0] != -1)
		{			
			

			printf(" %8s | %5d | %5d | %5d | %5d | %5s | %6.2s | %4d | \n"
				,(*(st+i)).name,(*(st+i)).perinfo[0],(*(st+i)).perinfo[1],(*(st+i)).perinfo[2],(*(st+i)).perinfo[3],(*(st+i)).position,(*(st+i)).condition,ranking(st,i));
		}
	}
}
