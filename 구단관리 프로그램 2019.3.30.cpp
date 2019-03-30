/*���� ���� ���α׷�*/  
#include<Stdio.h>
#include<string.h>
#include<windows.h>

struct club
{
    char name[10];
	double perinfo[4];//�Ż�����:����⵵,Ű,������,�ֱ� 
	char condition[10];//�������� ����
	char position[10];//������ 
};

void menu();
void inputFunc(struct club* st);//�Է��Լ� 
void outputFunc(struct club* st);//����Լ� 
int ranking(struct club* st,int tmp);//�����Լ� 
void modFunc(struct club* st);
void delFunc(struct club* st);
int searchFunc(struct club* st);//�˻� 
void sortFunc(struct club* st);

int main()
{
	struct club st[30];//���� 30��
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
		printf("�����ϼ��� > ");	scanf("%d", &selMenu);
		fflush(stdin);
		system("cls");//clean screen
		switch(selMenu)//�޴� ����. 
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
			printf("���α׷��� �����ϰڽ��ϴ�.\n");
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
    printf("������������������������������\n");
    printf("��    ���ܰ��� ���α׷�     ��\n");
    printf("��                          ��\n");
    printf("��       1. ��   ��         ��\n");
    printf("��       2. ��   ��         ��\n");
    printf("��       3. ��   ��         ��\n");
    printf("��       4. ��   ��         ��\n");
    printf("��       5. ��   ��         ��\n");
    printf("��       0. ��   ��         ��\n");
    printf("��                          ��\n");
    printf("������������������������������\n");
}

void inputFunc(struct club* st)
{
	int i;
	printf("�Ǣ� �Է� �Ǣ� \n");
	for(i=0;i<10;i++)
	{
		if((*(st+i)).perinfo[0] == -1)
		{
			break;
		}
	}
	
	printf("�̸� : ");		scanf("%s",(*(st+i)).name);
	fflush(stdin);
	printf("��� �⵵ : ");	scanf("%d",&(*(st+i)).perinfo[0]);
	printf("       Ű : ");	scanf("%d",&(*(st+i)).perinfo[1]);
	printf("   ������ : ");	scanf("%d",&(*(st+i)).perinfo[2]);
	printf("     �ֱ� : ");	scanf("%d",&(*(st+i)).perinfo[3]);
	printf("   ������ : "); scanf("%s",(*(st+i)).position);
	printf("���� ���� : ");	scanf("%s",(*(st+i)).condition);
	
	
	fflush(stdin);//\n ���. 
}

void outputFunc(struct club* st)
{
	int i;
	int sum = 0;
	printf("�Ǣ� ��� �Ǣ� \n");
	printf(" %8s | %5s | %5s | %5s | %5s | %5s | %6s | %4s |\n","�̸�","�⵵","Ű","������","�ֱ�","������","�������ɿ���","����");
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
    
    printf("�Ǣ� ���� �Ǣ� \n");
	printf("���� �� �̸� > ");
	if((i = searchFunc(st)) >= 0)
	{
		printf("��� �⵵ : ");scanf("%d",&(*(st+i)).perinfo[0]);
		printf("Ű : ");scanf("%d",&(*(st+i)).perinfo[1]);
		printf("������ : ");scanf("%d",&(*(st+i)).perinfo[2]);
		printf("�ֱ� : ");scanf("%d",&(*(st+i)).perinfo[3]);
		printf("������ : ");scanf("%s",(*(st+i)).position);
		printf("���� : ");scanf("%s",(*(st+i)).condition);
		fflush(stdin);
	}
	else
	{
		printf(" �ش� �̸��� �����ϴ� \n");
		printf(" �޴��� ���ư��ڽ��ϴ� \n");
	}
}


void delFunc(struct club* st)
{
	int i,j;
    
    printf("�Ǣ� ���� �Ǣ� \n");
    printf("���� �� �̸� > ");
    if((i=searchFunc(st)) >= 0)
    {
        for(j=0;j<4;j++)
        { 
           (*(st+i)).perinfo[j] = -1;
	  }
    }
    else
    {
        printf(" �ش� �̸��� �����ϴ� \n");
        printf(" �޴��� ���ư��ڽ��ϴ� \n");
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
	
	printf("�Ǣ� ���� �Ǣ� \n");
    printf(" %8s | %5s | %5s | %5s | %5s | %4s | %10s | \n","�̸�","����","����","����","����","����","�ּ�");
	for(i=0;i<10;i++)
	{
		if((*(st+i)).perinfo[0] != -1)
		{			
			

			printf(" %8s | %5d | %5d | %5d | %5d | %5s | %6.2s | %4d | \n"
				,(*(st+i)).name,(*(st+i)).perinfo[0],(*(st+i)).perinfo[1],(*(st+i)).perinfo[2],(*(st+i)).perinfo[3],(*(st+i)).position,(*(st+i)).condition,ranking(st,i));
		}
	}
}
