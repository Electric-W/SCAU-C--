#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    int data; //����
    char name[6];  //����
    struct node *next;
}node;
//��ʼ������
node *setLink()
{
	node *p,*s,*s1;
	s=(node*)malloc(sizeof(node));
	s->data=2;
	strcpy(s->name,"����");
	s1=(node*)malloc(sizeof(node));
	s->next=s1;
	s1->data=3;
	strcpy(s1->name,"xixi");
	s1->next=NULL;
	return s;  //��������ͷ�ڵ�
}

//���ļ��ж�ȡ���ݴ�������
node *take()  //���ļ��ж�ȡ���ݴ洢������ ��β�巨��
{
    node *head =(node*)malloc(sizeof(node));
    int t;
    char name[6];
    node *p;
    node *q;//ʼ��ָ��Ϊ��һ���ڵ�
    p=q=head;
    FILE * r= fopen("data.txt","r");
    if(r==NULL)
    {
        printf("���ļ�ʧ��!");
        return NULL;
    }
    while(fscanf(r,"%d %s",&t,name)!=EOF)
    {
       q= (node*)malloc(sizeof(node));
       q->data=t;
       strcpy(q->name,name);
       p->next=q;
       p=q;
    }
    p->next=NULL;
    return head;
}

//������ڵ�����ݴ洢���ļ���
void save(node *head)
{
   node *p=head;
   FILE *w =fopen("data.txt","w");
   if(w==NULL)
   {
       printf("���ļ�ʧ��!");
       return;
   }
   while(p)
   {
       fprintf(w,"%d %s",p->data,p->name);
       p=p->next;
	   fprintf(w,"\n");
   }
   printf("\n");
   fclose(w);
   return;
}
void show(node *head)//������� �ڵ������
{
	node *p=head->next;
	while(p)
	{
		printf("%d %s\n",p->data,p->name);
		p=p->next;
	}
}

int main()
{
    node *head;
    head=setLink();
    save(head);
    show(take());
    return 0;
}

