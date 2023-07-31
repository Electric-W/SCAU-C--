#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    int data; //数据
    char name[6];  //名字
    struct node *next;
}node;
//初始化链表
node *setLink()
{
	node *p,*s,*s1;
	s=(node*)malloc(sizeof(node));
	s->data=2;
	strcpy(s->name,"哈哈");
	s1=(node*)malloc(sizeof(node));
	s->next=s1;
	s1->data=3;
	strcpy(s1->name,"xixi");
	s1->next=NULL;
	return s;  //返回链表头节点
}

//从文件中读取数据存入链表
node *take()  //从文件中读取数据存储于链表 （尾插法）
{
    node *head =(node*)malloc(sizeof(node));
    int t;
    char name[6];
    node *p;
    node *q;//始终指向为下一个节点
    p=q=head;
    FILE * r= fopen("data.txt","r");
    if(r==NULL)
    {
        printf("打开文件失败!");
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

//将链表节点的数据存储在文件中
void save(node *head)
{
   node *p=head;
   FILE *w =fopen("data.txt","w");
   if(w==NULL)
   {
       printf("打开文件失败!");
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
void show(node *head)//输出链表 节点的数据
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

