#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char num[10];/*ѧ��*/
    char name[20];/*����*/
    int fgrade;/*�γ�1�ɼ�*/
    int cgrade;/*�γ�2�ɼ�*/
    int egrade;/*�γ�3�ɼ�*/
    int total;/*�ܷ�*/
}st[100];

void menu();              //�˵� 
void input();             //����ѧ����Ϣ������ 
void save(int m);         //�����ļ�����   
void save();              //�����ļ�����     
void display();          //���ѧ����Ϣ���� 
void search();          //��ѯ���� 
void search_num();     //��ѧ�Ų��� 
void search_name();   //���������� 
void sort_total();   //���ܷ����� 
int load();/*���������*/
int m;

int main()
{
     menu();
     int n=0,flag;
     char a;
   do
   {
     printf("��ѡ������Ҫ�����Ĳ���(1--4):\n"); 
	 scanf("%d",&n);
     if(n>=0&&n<=4)
     {
        flag=1;
        break;
     }
     else
     {
        flag=0;
        printf("��������������ѡ��");
     }
}
     while(flag==0);
     while(flag==1)
     {
        switch(n)
        {
    case 1:printf("\n ����������ѧ����Ϣ������\n");
           printf("\n");
	       input();
	       break; 
    case 2:printf("\n ���������ѧ����Ϣ������\n");
           printf("\n");
           display();
		   break; 
	case 3:printf("\n ���������ܷ����������\n");
	       printf("\n");
		   sort_total();
		   break;
    case 4:printf("\n ��������ѯѧ����Ϣ������\n");
	       printf("\n");
		   search();
		   break;
	case 0:exit(0);
	       break;
    default:break;
}
   getchar();
   printf("\n");
   printf("�Ƿ�������У�y or n��:\n");
   scanf("%c",&a);
   if(a=='y')
   {
     flag=1;
     system("cls"); /*����*/
     menu(); /*���ò˵�����*/
     printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--4):\n");
     scanf("%d",&n);
     printf("\n");
   }
   else
     exit(0);
   }
}

void menu() /*�˵�����*/
{
     printf(" ***************************************************\n"); 
	 printf("               1.¼��ѧ����Ϣ\n");
     printf("               2.���ѧ����Ϣ\n");
     printf("               3.���ܷ�����\n");
     printf("               4.��ѯѧ����Ϣ\n");
     printf("               0.�˳�\n");
     printf(" ****************************************************\n"); 
	 printf("\n");
     printf("\n");
}

void input() /*����ѧ����Ϣ������*/
{
     int i;
     printf("��������Ҫ������Ϣ��ѧ������(1--10):\n");
     scanf("%d",&m);
     for(i=0;i<m;i++)
     {
      printf("������ѧ��:");
      scanf("%s",st[i].num);
      printf("����������:");
      scanf("%s",st[i].name);
      printf("������γ�1�ɼ�:");
      scanf("%d",&st[i].fgrade);
      printf("������γ�2�ɼ�:");
      scanf("%d",&st[i].cgrade);
      printf("������γ�3�ɼ�:");
      scanf("%d",&st[i].egrade);
      st[i].total=st[i].fgrade+st[i].cgrade+st[i].egrade;
/*��Ϣ�����Ѿ����*/
     }
     save(m);
     return;/*����������*/
}

void display()/*���ѧ����Ϣ*/
{
     int i;
     m=load();
     printf("\nѧ��\t����\t�γ�1�ɼ�\t�γ�2�ɼ�\t�γ�3�ɼ�\t�ܷ�\n");/*���ѧ����Ϣ*/ 
	 for(i=0;i<m;i++)
    {
      printf("\n%s\t%s\t%d\t\t%d\t\t%d\t\t%d\n",st[i].num,st[i].name,st[i].fgrade,st[i].cgrade,st[i].egrade,st[i].total);
     }
}

void sort_total() /*���ܷ�����*/
{
     int i,j;
     struct student temp; /*�����ṹ�����*/
     printf("\tѧ��\t����\t�γ�1�ɼ�\t�γ�2�ɼ�\t�γ�3�ɼ�\t�ܷ�\n");
     for(i=0;i<m;i++)/*�����ݽ�������*/
     {
     for(j=i+1;j<m;j++)
     if(st[i].total<st[j].total)
     {
     temp=st[i];
     st[i]= st[j];
     st[j]=temp;
     }
     printf("\n\t%s\t%s\t%d\t\t%d\t\t%d\t\t%d\n",st[i].num,st[i].name,st[i].fgrade,st[i].cgrade,st[i].egrade,st[i].total);
     }
}

void search() /*��ѯ����*/
{
     int k; /*����ֲ�����*/
     m=load();
     printf("\n��ѧ�Ų�ѯ�밴1��\t��������ѯ�밴2\n");
     printf("\n�������ѯ��ʽ:");
     scanf("%d",&k);
     switch(k)/*��ѯ��ʽ��ѡ��*/
     {
     case 1:search_num();break;/*��ѧ�Ų�ѯ*/
     case 2:search_name();break;/*��������ѯ*/
    }
     printf("\nPress any key to enter menu......");
     getchar();
     return; /*����������*/
}

void search_num()/*(1)��ѧ�Ų���*/
{
     int i;
     char temp[30];
     printf("\n ������Ҫ���ҵ�ѧ��:");
     scanf("%s",temp);
     for( i=0;i<m;i++)
    {
     if(strcmp(temp,st[i].num)==0)
     {
     printf("\nѧ��\t����\t�γ�1�ɼ�\t�γ�2�ɼ�\t�γ�3�ɼ�\t�ܷ�\n");
     printf("\n%s\t%s\t%d\t\t%d\t\t%d\t\t%d\n",st[i].num,st[i].name,st[i].fgrade,st[i].cgrade,st[i].egrade,st[i].total);
     }
    }
}

void search_name()/*(2)����������*/
{
     int i;
     char temp[30];
     printf("\n ������Ҫ���ҵ�����:");
     scanf("%s",temp);
     for( i=0;i<m;i++)
     {
      if(strcmp(temp,st[i].name)==0)
      {
        printf("\nѧ��\t����\t�γ�1�ɼ�\t�γ�2�ɼ�\t�γ�3�ɼ�\t�ܷ�\n");
        printf("\n%s\t%s\t%d\t\t%d\t\t%d\t\t%d\n",st[i].num,st[i].name,st[i].fgrade,st[i].cgrade,st[i].egrade,st[i].total);
      }
     }
}

int load() /*���뺯��*/
{
     FILE*fp;
     int n=0;
     if((fp=fopen("student_list","rb"))==NULL)
    {
      printf("cannot open file\n");
      exit(0);
    }
     else
    {
      do
      {
        fread(&st[n],sizeof(struct student),1,fp);
        n++;
      }
      while(feof(fp)==0);
    }
    fclose(fp);
    return(n-1);
}

void save(int m)/*�����ļ�����*/
{
    int i;
    FILE*fp;
    if((fp=fopen("student_list","wb"))==NULL)/*�����ļ����ж��Ƿ��ܴ�*/ 
	 {
    printf("cannot open file\n");
    exit(0);
}
    for(i=0;i<m;i++)/*���ڴ���ѧ������Ϣ����������ļ���ȥ*/ 
	if(fwrite(&st[i],sizeof(struct student),1,fp)!=1)
    printf("file write error\n");
    fclose(fp);
}
