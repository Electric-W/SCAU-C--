#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>

void menu();//��ʼ�˵�
void ini_list();//�ļ���ȡ
void add_people();//��ϵ�����
void display_persons();//��ϵ�����
void delete_person();//��ϵ��ɾ��
void save_list();//�ļ����
void search_person();//��ϵ�˲���
void search_groups_phone();//�绰����
void static_groups_sex();//�Ա����
void display_number();//������ȡ����
void sort_people_by_name();//��������
void sort_people_by_addr();//��ַ����
void sort_people_by_age();//��������
void sort_people_by_tel();//�绰����
void change_something();//��ϵ���޸�
void sorting();//����˵�
void static_people_age();//����η���ͳ��
void search_groups_sex();//�Ա����
int login();//��¼�˻�����
struct A
{
    char name[10];//����
    char tel_num[20];//�绰����
    char address[20];//��ַ
    char age[3];//����
    char sex[5];//�Ա�
    struct  A *next;
};
typedef struct A NODE_P;
NODE_P *contact_now;

typedef struct LNode
{
    char name[10];//����
    char pass[10];//����
    struct LNode *next;
} ;
typedef struct LNode ANode;
typedef struct LNode* pNode;

pNode createList()//�����û�����
{
    pNode pHead = (pNode)malloc(sizeof(ANode));
    pHead->next=NULL;
    //ͷ��㲻�������
    FILE *fp = fopen("user.txt","r");
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }
    pNode cur = pHead;
    while(1)
    {
        pNode temp = (pNode)malloc(sizeof(ANode));
        if(!temp)
            exit(-1);

        //��⵽¼����Ϻ󽫷���Ŀռ������
        if(2!=fscanf(fp,"%s%s",temp->name,temp->pass))
        {
            free(temp);
            break;
        }
        cur->next=temp;
        cur = temp;

        //ʹ���һ���ڵ�ָ��գ������Ժ��ж�
        cur->next = NULL;
    }
    return pHead;
}


int login(pNode head)//��¼����
{
    if(NULL==head->next)
    {
        printf("δ���˺�¼��\n");
        getch();
        return 0;
    }
    char name[10];
    char pass[10];
    printf("�������˺�:");
    scanf("%s",name);
    printf("����������:");
    scanf("%s",pass);
    pNode temp = head->next;
    while(temp)
    {
        if(0==strcmp(temp->name,name) && 0==strcmp(temp->pass,pass))
        {
            printf("��¼�ɹ����밴�س�������");
            getch();
            return 1;
        }
        temp = temp->next;
    }
    printf("δ�ҵ����û���");
    getch();
    return 0;
}

void writeToFile(pNode head)//д��txt�ļ���ÿһ�д���һ���û�
{
    FILE *fw = fopen("user.txt","w");
    pNode temp=head->next;
    if(temp==NULL)
    {
        return;
    }
    while(temp)
    {
        fprintf(fw,temp->name);
        fprintf(fw,"\t");
        fprintf(fw,temp->pass);
        fprintf(fw,"\n");
        temp  = temp->next;
    }
}



void registerUser(pNode head)//ע���û�
{
    pNode temp = head->next;
    //���������û�ֱ����ͷ����ע��
    if(!temp)
    {
        temp = (pNode)malloc(sizeof(ANode));
        head->next = temp;
    }
    else
    {
        //�������û��������һ���ڵ�������½ڵ�
        while(temp->next)
        {
            temp = temp->next;
        }
        pNode last = (pNode)malloc(sizeof(ANode));
        temp->next = last;
        temp = last;
    }
    printf("�������˺�:");
    scanf("%s",temp->name);
    printf("����������:");
    scanf("%s",temp->pass);
    temp->next=NULL;
}

int login_menu()
{
    int choice;
    printf("\t1.��¼\n");
    printf("\t2.ע��\n");
    printf("\t#.�˳�\n");
    printf("��ѡ��:");
    scanf("%d",&choice);
    printf("\t*******************************\n");
    return choice;
}
int list_size;
int main()
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 16);//����ɫ���趨
    contact_now  = (NODE_P *)malloc(sizeof(NODE_P));
    ini_list();
    int choice;
    pNode head = createList();
    printf("\n\n");
    printf("\t*******************************\n");
    printf("\t*                             *\n");
    printf("\t*      ��ӭ����ͨѶ¼ϵͳ     *\n");
    printf("\t*                             *\n");
    printf("\t*******************************\n");
    printf("\n\n");
    while(1)
    {
        choice = login_menu();//��¼����
        if(1==choice)
        {
            if(login(head))//��¼����
            {
                break;
            }
            system("cls");
        }
        else if(2==choice)
        {
            system("cls");
            registerUser(head);//ע�ắ��
            system("cls");
        }
        else
        {
            return 0;
        }
    }

    int k;
    while (1)
    {
        system("cls");
        menu();//ͨѶ¼���ܲ˵�
        printf("��ѡ��>");
        scanf("%d", &k);
        if (k == 1)
        {
            system("cls");
            display_persons();//��ʾ������
        }
        else if (k == 2)
        {
            system("cls");
            add_people();//����
        }
        else if (k == 3)
        {
            system("cls");
            delete_person();//ɾ��
        }
        else if (k == 4)
        {
            system("cls");
            search_person();//����
        }
        else if(k==5)
        {
            system("cls");
            change_something();//����Ϣ
        }
        else if (k == 6)
        {
            system("cls");
            sorting();//����˵�
        }
        else if(k==7)
        {
            system("cls");
            search_groups_phone();//�绰ǰ��λͳ��
        }
        else if(k==8)
        {
            system("cls");

            search_groups_sex();//�Ա����
        }
        else if(k==9)
        {
            system("cls");
            static_groups_sex();//�Ա�ͳ��
        }
        else if(k==10)
        {
            system("cls");
            static_groups_age();//����ͳ��
        }
        else if (k == 0)
        {
            save_list();//��ϵ�˱���
            writeToFile(head);//�˺ű���
            exit(0);
        }
    }

    system("pause");
    return 0;
}

void search_groups_phone()
{
    int statistics=0;
    char phone_num[3];
    printf("��������λ�������ڲ��ҵ绰����\n");
    printf("����>");
    scanf("%s",phone_num);
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            if(phone_num[0]==ptr->tel_num[0]&&phone_num[1]==ptr->tel_num[1]&&phone_num[2]==ptr->tel_num[2])
            {
                printf("������%s", ptr->name);
                printf("\n�Ա�%s", ptr->sex);
                printf("\t���䣺%s", ptr->age);
                printf("\t�绰��%s", ptr->tel_num);
                printf("\t��ַ��%s", ptr->address);
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("�ֻ�����ǰ��λΪ%s����ϵ��һ����%dλ��\n\n",phone_num,statistics);
    printf("...����'0'���ز˵�...");
    int k = 10;
    while (k != 0)
    {
        scanf("%d", &k);
    }
    return;
}
void static_groups_sex()
{
    int statistics=0;
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp("��",ptr->sex)==0)
            {
                printf("*������%s", ptr->name);
                printf("\t*�Ա�%s", ptr->sex);
                printf("\t*���䣺%s", ptr->age);
                printf("\t*�绰��%s", ptr->tel_num);
                printf("\t*��ַ��%s", ptr->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("�Ա�Ϊ���Ե���ϵ��һ����%dλ��\n\n",statistics);
    statistics=0;
    NODE_P* ptr1 = contact_now->next;
    if (ptr1 == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr1 != NULL)
        {
            if(strcmp("Ů",ptr1->sex)==0)
            {
                printf("*������%s", ptr1->name);
                printf("\t*�Ա�%s", ptr1->sex);
                printf("\t*���䣺%s", ptr1->age);
                printf("\t*�绰��%s", ptr1->tel_num);
                printf("\t*��ַ��%s", ptr1->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr1 = ptr1->next;
        }
    }
    printf("�Ա�ΪŮ�Ե���ϵ��һ����%dλ��\n\n",statistics);
    printf("...����'0'���ز˵�...");
    int k = 10;
    while (k != 0)
    {
        scanf("%d", &k);
    }
    return;
}
void static_groups_age()
{
    int statistics=0;
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp("0",ptr->age)<0&&strcmp("9",ptr->age)>=0&&strlen(ptr->age)==1)
            {
                printf("*������%s", ptr->name);
                printf("\t*�Ա�%s", ptr->sex);
                printf("\t*���䣺%s", ptr->age);
                printf("\t*�绰��%s", ptr->tel_num);
                printf("\t*��ַ��%s", ptr->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("10�����µ���ϵ��һ����%dλ��\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr1 = contact_now->next;
    if (ptr1 == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr1 != NULL)
        {
            if((strcmp("10",ptr1->age)<=0&&strcmp("20",ptr1->age)>=0)&&strlen(ptr1->age)==2)
            {
                printf("*������%s", ptr1->name);
                printf("\t*�Ա�%s", ptr1->sex);
                printf("\t*���䣺%s", ptr1->age);
                printf("\t*�绰��%s", ptr1->tel_num);
                printf("\t*��ַ��%s", ptr1->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr1 = ptr1->next;
        }
    }
    printf("10��20�����ϵ��һ����%dλ��\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr2 = contact_now->next;
    if (ptr2 == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr2 != NULL)
        {
            if((strcmp("20",ptr2->age)<0&&strcmp("40",ptr2->age)>=0)&&strlen(ptr2->age)==2)
            {
                printf("*������%s", ptr2->name);
                printf("\t*�Ա�%s", ptr2->sex);
                printf("\t*���䣺%s", ptr2->age);
                printf("\t*�绰��%s", ptr2->tel_num);
                printf("\t*��ַ��%s", ptr2->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr2 = ptr2->next;
        }
    }
    printf("20��40�����ϵ��һ����%dλ��\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr3 = contact_now->next;
    if (ptr3 == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr3 != NULL)
        {
            if((strcmp("40",ptr3->age)<0&&strcmp("60",ptr3->age)>=0)&&strlen(ptr3->age)==2)
            {
                printf("*������%s", ptr3->name);
                printf("\t*�Ա�%s", ptr3->sex);
                printf("\t*���䣺%s", ptr3->age);
                printf("\t*�绰��%s", ptr3->tel_num);
                printf("\t*��ַ��%s", ptr3->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr3 = ptr3->next;
        }
    }
    printf("40��60�����ϵ��һ����%dλ��\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr4 = contact_now->next;
    if (ptr4 == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr4 != NULL)
        {
            if((strcmp("60",ptr4->age)<0&&strcmp("80",ptr4->age)>=0)&&strlen(ptr4->age)==2)
            {
                printf("*������%s", ptr4->name);
                printf("\t*�Ա�%s", ptr4->sex);
                printf("\t*���䣺%s", ptr4->age);
                printf("\t*�绰��%s", ptr4->tel_num);
                printf("\t*��ַ��%s", ptr4->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr4 = ptr4->next;
        }
    }
    printf("60��80�����ϵ��һ����%dλ��\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr5 = contact_now->next;
    if (ptr5 == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr4 != NULL)
        {
            if(strcmp("80",ptr4->age)<0)
            {
                printf("*������%s", ptr4->name);
                printf("\t*�Ա�%s", ptr4->sex);
                printf("\t*���䣺%s", ptr4->age);
                printf("\t*�绰��%s", ptr4->tel_num);
                printf("\t*��ַ��%s", ptr4->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            if(strlen(ptr4->age)==3)
            {
                printf("*������%s", ptr4->name);
                printf("\t*�Ա�%s", ptr4->sex);
                printf("\t*���䣺%s", ptr4->age);
                printf("\t*�绰��%s", ptr4->tel_num);
                printf("\t*��ַ��%s", ptr4->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr4 = ptr4->next;
        }
    }
    printf("80�����ϵ���ϵ��һ����%dλ��\n\n",statistics);
    printf("===========================\n");
    printf("...����'0'���ز˵�...");
    int k = 10;
    while (k != 0)
    {
        scanf("%d", &k);
    }
    return;
}
void display_number()
{
    list_size=0;
    NODE_P *p;
    p=contact_now->next;
    while(p!=NULL)
    {
        p=p->next;
        list_size++;
    }
}
void sort_people_by_name()
{
    int k;
    display_number();
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=contact_now->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = contact_now->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->name,sort2->name)>0)
            {
                if(j==1)
                {
                    contact_now->next=contact_now->next->next;
                }
                if(j>=2)
                {
                    sort3->next=sort2;
                }
                sort1->next=sort2->next;
                sort2->next=sort1;
                sort2=sort2->next->next;
                continue;
            }
            else
            {
                sort1=sort2;
                sort2=sort2->next;
            }
        }
    }
    printf("����ɹ���\n");
    printf("...����'0'���ز˵�\n");
    scanf("%d", &k);
    if (k == 0)
        return;
}
void sort_people_by_addr()
{
    int k;
    display_number();
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=contact_now->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = contact_now->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->address,sort2->address)>0)
            {
                if(j==1)
                {
                    contact_now->next=contact_now->next->next;
                }
                if(j>=2)
                {
                    sort3->next=sort2;
                }
                sort1->next=sort2->next;
                sort2->next=sort1;
                sort2=sort2->next->next;
                continue;
            }
            else
            {
                sort1=sort2;
                sort2=sort2->next;
            }
        }
    }
    printf("����ɹ���\n");
    printf("...����'0'���ز˵�\n");
    scanf("%d", &k);
    if (k == 0)
        return;
}
void sort_people_by_age()
{
    int k;
    display_number();
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=contact_now->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = contact_now->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->age,sort2->age)>0)
            {
                if(j==1)
                {
                    contact_now->next=contact_now->next->next;
                }
                if(j>=2)
                {
                    sort3->next=sort2;
                }
                sort1->next=sort2->next;
                sort2->next=sort1;
                sort2=sort2->next->next;
                continue;
            }
            else
            {
                sort1=sort2;
                sort2=sort2->next;
            }
        }
    }
    printf("����ɹ���\n");
    printf("...����'0'���ز˵�\n");
    scanf("%d", &k);
    if (k == 0)
        return;
}
void sort_people_by_tel()
{
    int k;
    display_number();
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=contact_now->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = contact_now->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->tel_num,sort2->tel_num)>0)
            {
                if(j==1)
                {
                    contact_now->next=contact_now->next->next;
                }
                if(j>=2)
                {
                    sort3->next=sort2;
                }
                sort1->next=sort2->next;
                sort2->next=sort1;
                sort2=sort2->next->next;
                continue;
            }
            else
            {
                sort1=sort2;
                sort2=sort2->next;
            }
        }
    }
    printf("����ɹ���\n");
    printf("...����'0'���ز˵�\n");
    scanf("%d", &k);
    if (k == 0)
        return;
}
void change_something()
{
    int k = 1;
    while (k == 1)
    {
        printf("*******************�޸���ϵ��********************************\n");
        char search_name[10],q[100],p[100];
        printf("������Ҫ�޸ĵ���ϵ��������");
        scanf("%s", search_name);
        NODE_P* ptr = (NODE_P*)malloc(sizeof(NODE_P));
        ptr=contact_now->next;
        if (ptr == NULL)
            printf("...ͨѶ¼��������ϵ��...\n");
        else
        {
            int count = 0;
            while (ptr != NULL)
            {
                if (strcmp(ptr->name, search_name) == 0)
                {
                    printf("�ɹ��ҵ�%s�ľ�����Ϣ��\n",ptr->name);
                    printf("*������%s", ptr->name);
                    printf("\t*�Ա�%s", ptr->sex);
                    printf("\t*���䣺%s", ptr->age);
                    printf("\t*�绰��%s", ptr->tel_num);
                    printf("\t*��ַ��%s", ptr->address);
                    printf("\n");
                    printf("����Ҫ�޸�%s��ʲô��Ϣ(name, sex, tel_num, age, address)��",search_name);
                    scanf("%s",q);
                    if((strcmp(q,"name"))&(strcmp(q,"sex"))&(strcmp(q,"age"))&(strcmp(q,"tel_num"))&(strcmp(q,"address")))
                    {
                        printf("��������ȷ����Ҫ�޸ĵ���Ϣ��\n");
                        break;
                    }
                    printf("����Ҫ�� %s �� %s �޸ĳɣ�",search_name,q);
                    scanf("%s",p);
                    if(!(strcmp(q,"name")))strcpy(ptr->name, p);
                    if(!(strcmp(q,"sex")))strcpy(ptr->sex, p);
                    if(!(strcmp(q,"tel_num")))strcpy(ptr->tel_num, p);
                    if(!(strcmp(q,"age")))strcpy(ptr->age, p);
                    if(!(strcmp(q,"address")))strcpy(ptr->address, p);
                    printf("�ɹ��� %s �� %s �޸�Ϊ %s!!!\n", search_name,q,p);

                }
                else if(ptr->next==NULL)
                {
                    printf("û���ҵ�%s����Ϣ��",search_name);
                }
                ptr = ptr->next;
            }
        }
        printf("******************************************************\n");
        printf("...����'0'���ز˵�...����'1'�����޸�...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
void sorting()
{
    int choice=0;
    int k;

    while(1)
    {
        system("cls");
        printf("��ѡ��Ҫ����ķ�ʽ\n");
        printf("************************************\n");
        printf("*     1.������      2.������       *\n");
        printf("*     3.����ַ      4.���ֻ���     *\n");
        printf("*     0.�˳�                       *\n");
        printf("************************************\n");
        printf("ѡ��>");
        scanf("%d",&choice);
        if(choice==1)
        {
            sort_people_by_name();
        }
        if(choice==2)
        {
            sort_people_by_age();
        }
        if(choice==3)
        {
            sort_people_by_addr();
        }
        if(choice==4)
        {
            sort_people_by_tel();
        }
        if(choice==0)
        {
            return;
        }
        if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=0)
        {
            printf("�������!����ȷ��������Ҫ������ʽ��\n");
        }
    }
}
void menu()
{
    printf("******************************************************\n");
    printf("\t\t\tͨѶ¼ϵͳ        \n\n");
    printf("\t\t  1.�鿴ͨѶ¼        \n");
    printf("\t\t  2.�����ϵ��        \n");
    printf("\t\t  3.ɾ����ϵ��        \n");
    printf("\t\t  4.��ѯ��ϵ��        \n");
    printf("\t\t  5.�޸���ϵ����Ϣ    \n");
    printf("\t\t  6.��ϵ������      \n");
    printf("\t\t  7.�鿴�ֻ�����ǰ��λ��ͬ����ϵ��\n");
    printf("\t\t  8.��ѯ�������ԣ�Ů�ԣ���ϵ��\n");
    printf("\t\t  9.ͳ����������/Ů����ϵ��\n");
    printf("\t\t 10.ͳ�Ƹ�����ε���ϵ��\n");
    printf("\t\t  0.���沢�˳�\n");
    printf("******************************************************\n");
}
void search_groups_sex()
{
    int statistics=0;
    char sex_people[3];
    printf("�������Ա�\n");
    printf("����/Ů��>");
    scanf("%s",sex_people);
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp(sex_people,ptr->sex)==0)
            {
                printf("*������%s", ptr->name);
                printf("\t*�Ա�%s", ptr->sex);
                printf("\t*���䣺%s", ptr->age);
                printf("\t*�绰��%s", ptr->tel_num);
                printf("\t*��ַ��%s", ptr->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("�Ա�Ϊ%s����ϵ��һ����%dλ��\n\n",sex_people,statistics);
    printf("...����'0'���ز˵�...");
    int k = 10;
    while (k != 0)
    {
        scanf("%d", &k);
    }
    return;
}
void add_people()//�����
{
    int k = 1;

    while (k == 1)
    {
        printf("*******************�½���ϵ��********************************\n");
        printf("\t��ܰ��ʾ��Ϊ��ֹ������������ϸ���Ҫ�������ϵ�ˣ�лл�� \n");
        printf("*************************************************************\n");
        NODE_P* new_person = (NODE_P *)malloc(sizeof(NODE_P));
        printf("��������ϵ������:");
        scanf("%s", new_person->name);
        printf("------------------------------------------------------\n");
        printf("��������ϵ���Ա���/Ů����");
        scanf("%s", new_person->sex);
        printf("------------------------------------------------------\n");
        printf("���������䣺");
        scanf("%s", new_person->age);
        printf("------------------------------------------------------\n");
        printf("��������ϵ�˵绰��15�����ڣ���");
        scanf("%s", new_person->tel_num);
        printf("------------------------------------------------------\n");
        printf("��������ϵ�˵�ַ��20�����ڣ���");
        scanf("%s", new_person->address);
        printf("******************************************************\n");

        NODE_P* ptr = contact_now;
        while (ptr->next != NULL) //ptrָ������contact_nowĩβ���
            ptr = ptr->next;

        ptr->next = new_person;
        new_person->next = NULL;
        printf("...����'0'���ز˵�...����'1'�������...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}

void display_persons()//
{
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            printf("*******************************************************************\n");
            printf("*������%s", ptr->name);
            printf("\t*�Ա�%s\n", ptr->sex);
            printf("*���䣺%s", ptr->age);
            printf("\t*�绰��%s", ptr->tel_num);
            printf("\t*��ַ��%s", ptr->address);
            printf("\n");
            ptr = ptr->next;
        }
    }
    printf("*******************************************************************\n");
    printf("...����'0'���ز˵�...");
    int k = 10;
    while (k != 0)
    {
        scanf("%d", &k);
    }
    return;
}
//����ʱ��ʼ���������ļ���������
void ini_list()
{
    contact_now->next = NULL;

    FILE *fp;
    if ((fp = fopen("list_file.txt", "r")) == NULL)
    {
        printf("...����ϵ���ļ�ʱ����...\n");
        return;
    }

    NODE_P* tail_ptr = contact_now;
    char name[10], tel_num[20], address[20], sex[5],age[3];
    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s%s", name, sex,age, tel_num, address);
        NODE_P* new_node = (NODE_P *)malloc(sizeof(NODE_P));
        strcpy(new_node->name, name);
        strcpy(new_node->sex, sex);
        strcpy(new_node->age, age);
        strcpy(new_node->tel_num, tel_num);
        strcpy(new_node->address, address);
        tail_ptr->next = new_node;
        new_node->next = NULL;
        tail_ptr = new_node;
        getc(fp);
    }
    fclose(fp);
}
//ɾ����
void delete_person()
{
    int k = 1;
    while (k == 1)
    {
        printf("*******************ɾ����ϵ��********************************\n");
        NODE_P* ptr = contact_now->next;
        NODE_P* pre = contact_now;
        if (ptr == NULL)
            printf("...ͨѶ¼��������ϵ��...\n");
        else
        {
            printf("������ɾ����ϵ�˵�������");
            char del_name[10];
            scanf("%s", del_name);
            while (ptr != NULL)
            {
                if (strcmp(ptr->name, del_name) == 0)
                {
                    printf("...ɾ����ϵ����Ŀ...\n");
                    printf("*������%s", ptr->name);
                    printf("\t*�Ա�%s", ptr->sex);
                    printf("\t*���䣺%s", ptr->age);
                    printf("\t*�绰��%s", ptr->tel_num);
                    printf("\t*��ַ��%s", ptr->address);
                    printf("\nȷ��ɾ����  Y/N\n");
                    char input = '0';
                    while (input != 'Y' && input != 'N')
                    {
                        scanf("%c", &input);
                    }
                    if (input == 'N')//�ýڵ㲻ɾ����Ѱ����һ��������������ϵ��
                    {
                        ptr = ptr->next;
                        pre = pre->next;
                        continue;
                    }
                    else if (input == 'Y')//ɾ���ڵ�
                    {
                        pre->next = ptr->next;
                        free(ptr);
                        ptr = pre->next;
                        continue;
                    }
                }
                ptr = ptr->next;
                pre = pre->next;
            }
        }
        printf("******************************************************\n");
        printf("...����'0'���ز˵�...����'1'����ɾ��...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
//�������
void save_list()
{
    if (contact_now->next == NULL)
        return;

    FILE *fp;
    if ((fp = fopen("list_file.txt", "w")) == NULL)
        printf("...����ϵ���ļ�ʱ����...\n");

    NODE_P* ptr = contact_now->next;
    while (ptr != NULL)
    {
        fprintf(fp, "\n%s %s %s %s %s", ptr->name, ptr->sex,ptr->age, ptr->tel_num, ptr->address);//�ļ����
        ptr = ptr->next;
    }
    fclose(fp);
}
//����
void search_person()
{
    int k = 1;
    while (k == 1)
    {
        printf("********************��ѯ��ϵ��********************************\n");
        char search_name[10];
        printf("�������ѯ������");
        scanf("%s", search_name);
        NODE_P* ptr = contact_now->next;
        if (ptr == NULL)
            printf("...ͨѶ¼��������ϵ��...\n");
        else
        {
            int count = 0;
            while (ptr != NULL)
            {
                if (strcmp(ptr->name, search_name) == 0)
                {
                    count++;
                    printf("...��ѯ����ϵ��%dλ...\n", count);
                    printf("*������%s", ptr->name);
                    printf("\t*�Ա�%s", ptr->sex);
                    printf("\t*���䣺%s", ptr->age);
                    printf("\t*�绰��%s", ptr->tel_num);
                    printf("\t*��ַ��%s", ptr->address);
                    printf("\n");
                }
                else if(ptr->next==NULL) printf("û���ҵ�%s����Ϣ��\n",search_name);
                ptr=ptr->next;
            }
        }
        printf("******************************************************\n");
        printf("...����'0'���ز˵�...����'1'������ѯ...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
