#include <stdio.h>
#include <string.h>
#include <Windows.h>

void showMenu();
void initL();
void addPerson();
void displayPersons();
void deletePerson();
void saveList();
void searchPerson();

struct A
{
    char name[10];
    char tel_num[20];
    char address[20];
    char age[3];
    char sex[5];
    struct  A *next;
};
typedef struct A person_node;
person_node *L;
int list_size;
void search_groups_phone()
{
    int statistics=0;
    char phone_num[3];
    printf("��������λ�������ڲ��ҵ绰����\n");
    printf("����>");
    scanf("%s",phone_num);
    person_node* ptr = L->next;
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
void search_groups_sex()
{
    int statistics=0;
    char sex_people[3];
    printf("�������Ա�\n");
    printf("����/Ů��>");
    scanf("%s",sex_people);
    person_node* ptr = L->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp(sex_people,ptr->sex)==0)
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
    printf("�Ա�Ϊ%s����ϵ��һ����%dλ��\n\n",sex_people,statistics);
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
    person_node *p;
    p=L->next;
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
    person_node *sort1=(person_node *)malloc(sizeof(person_node));
    person_node *sort2=(person_node *)malloc(sizeof(person_node));
    person_node *sort3=(person_node *)malloc(sizeof(person_node));
    int i,j;
    system("cls");
    if(L->next==NULL||L->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=L->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = L->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->name,sort2->name)>0)
            {
                if(j==1)
                {
                    L->next=L->next->next;
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
    person_node *sort1=(person_node *)malloc(sizeof(person_node));
    person_node *sort2=(person_node *)malloc(sizeof(person_node));
    person_node *sort3=(person_node *)malloc(sizeof(person_node));
    int i,j;
    system("cls");
    if(L->next==NULL||L->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=L->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = L->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->address,sort2->address)>0)
            {
                if(j==1)
                {
                    L->next=L->next->next;
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
    person_node *sort1=(person_node *)malloc(sizeof(person_node));
    person_node *sort2=(person_node *)malloc(sizeof(person_node));
    person_node *sort3=(person_node *)malloc(sizeof(person_node));
    int i,j;
    system("cls");
    if(L->next==NULL||L->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=L->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = L->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->age,sort2->age)>0)
            {
                if(j==1)
                {
                    L->next=L->next->next;
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
    person_node *sort1=(person_node *)malloc(sizeof(person_node));
    person_node *sort2=(person_node *)malloc(sizeof(person_node));
    person_node *sort3=(person_node *)malloc(sizeof(person_node));
    int i,j;
    system("cls");
    if(L->next==NULL||L->next->next==NULL)
    {
        printf("����ɹ���");
        return;
    }
    for(i=1; i<=(list_size-1); i++)
    {
        sort1=L->next;
        sort2=sort1->next;
        for(j=1; j<=list_size-i; j++)
        {
            if(j==2)
            {
                sort3 = L->next;
            }
            if(j>2)
            {
                sort3=sort3->next;
            }
            if(strcmp(sort1->tel_num,sort2->tel_num)>0)
            {
                if(j==1)
                {
                    L->next=L->next->next;
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
        printf("-------------------�޸���ϵ��--------------------------------\n");
        char search_name[10],q[100],p[100];
        printf("������Ҫ�޸ĵ���ϵ��������");
        scanf("%s", search_name);
        person_node* ptr = (person_node*)malloc(sizeof(person_node));
        ptr=L->next;
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
                    printf("������%s", ptr->name);
                    printf("\t�Ա�%s", ptr->sex);
                    printf("\t���䣺%s", ptr->age);
                    printf("\t�绰��%s", ptr->tel_num);
                    printf("\t��ַ��%s\n", ptr->address);
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
                    break;
                }
                else if(ptr->next=NULL) printf("û���ҵ�%s����Ϣ��",search_name);
                ptr = ptr->next;
            }
        }
        printf("------------------------------------------------------\n");
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
        printf("*----------------------------------*\n");
        printf("|     1.������      2.������       |\n");
        printf("|     3.����ַ      4.���ֻ���     |\n");
        printf("|     0.�˳�                       |\n");
        printf("*----------------------------------*\n");
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
int main()
{
    L  = (person_node *)malloc(sizeof(person_node));
    initL();
    int k;
    while (1)
    {
        system("cls");
        showMenu();
        scanf("%d", &k);
        if (k == 1)
        {
            system("cls");
            displayPersons();
        }
        else if (k == 2)
        {
            system("cls");
            addPerson();
        }
        else if (k == 3)
        {
            system("cls");
            deletePerson();
        }
        else if (k == 4)
        {
            system("cls");
            searchPerson();
        }
        else if(k==5)
        {
            system("cls");
            change_something();
        }
        else if (k == 6)
        {
            system("cls");
            sorting();
        }
        else if(k==7)
        {
            system("cls");
            search_groups_phone();
        }
        else if(k==8)
        {
            system("cls");
            search_groups_sex();
        }
        else if (k == 0)
        {
            saveList();
            exit(0);
        }
    }

    system("pause");
    return 0;
}

void showMenu()
{
    printf("------------------------------------------------------\n");
    printf("\t\t\tͨѶ¼ϵͳ        \n\n");
    printf("\t\t  1.�鿴ͨѶ¼        \n");
    printf("\t\t  2.�����ϵ��        \n");
    printf("\t\t  3.ɾ����ϵ��        \n");
    printf("\t\t  4.��ѯ��ϵ��        \n");
    printf("\t\t  5.�޸���ϵ����Ϣ    \n");
    printf("\t\t  6.��ϵ������      \n");
    printf("\t\t  7.�鿴�ֻ�����ǰ��λ��ͬ����ϵ��\n");
    printf("\t\t  8.�鿴��������/Ů����ϵ��\n");
    printf("\t\t  0.���沢�˳�\n");
    printf("------------------------------------------------------\n");
}

void addPerson()
{
    int k = 1;

    while (k == 1)
    {
        printf("-------------------�½���ϵ��--------------------------------\n");
        printf("\t��ܰ��ʾ��Ϊ��ֹ������������ϸ���Ҫ�������ϵ�ˣ�лл�� \n");
        printf("-------------------------------------------------------------\n");
        person_node* new_person = (person_node *)malloc(sizeof(person_node));
        printf("��������ϵ������:");
        scanf("%s", new_person->name);
        printf("��������ϵ���Ա���/Ů����");
        scanf("%s", new_person->sex);
        printf("���������䣺");
        scanf("%s", new_person->age);
        printf("��������ϵ�˵绰��15�����ڣ���");
        scanf("%s", new_person->tel_num);
        printf("��������ϵ�˵�ַ��20�����ڣ���");
        scanf("%s", new_person->address);
        printf("------------------------------------------------------\n");

        person_node* ptr = L;
        while (ptr->next != NULL) //ptrָ������Lĩβ���
            ptr = ptr->next;

        ptr->next = new_person;
        new_person->next = NULL;
        printf("...����'0'���ز˵�...����'1'�������...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}

void displayPersons()
{
    person_node* ptr = L->next;
    if (ptr == NULL)
        printf("...��δ����κ���ϵ��...\n");
    else
    {
        while (ptr != NULL)
        {
            printf("*******************************************************************\n");
            printf("*������%s", ptr->name);
            printf("\t*�Ա�%s", ptr->sex);
            printf("\t*���䣺%s", ptr->age);
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

void initL()
{
    L->next = NULL;

    FILE *fp;
    if ((fp = fopen("list_file.txt", "r")) == NULL)
    {
        printf("...����ϵ���ļ�ʱ����...\n");
        return;
    }

    person_node* tail_ptr = L;
    char name[10], tel_num[20], address[20], sex[5],age[3];
    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s%s", name, sex,age, tel_num, address);
        person_node* new_node = (person_node *)malloc(sizeof(person_node));
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

void deletePerson()
{
    int k = 1;
    while (k == 1)
    {
        printf("-------------------ɾ����ϵ��--------------------------------\n");
        person_node* ptr = L->next;
        person_node* pre = L;
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
                    printf("->������%s", ptr->name);
                    printf("\t�Ա�%s", ptr->sex);
                    printf("\t���䣺%s", ptr->age);
                    printf("\t�绰��%s", ptr->tel_num);
                    printf("\t��ַ��%s<-", ptr->address);

                    printf("\nȷ��ɾ����y/n\n");
                    char input = '0';
                    while (input != 'y' && input != 'n')
                    {
                        scanf("%c", &input);
                    }
                    if (input == 'n')
                    {
                        ptr = ptr->next;
                        pre = pre->next;
                        continue;
                    }
                    else if (input == 'y')
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
        printf("------------------------------------------------------\n");
        printf("...����'0'���ز˵�...����'1'����ɾ��...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}

void saveList()
{
    if (L->next == NULL)
        return;

    FILE *fp;
    if ((fp = fopen("list_file.txt", "w")) == NULL)
        printf("...����ϵ���ļ�ʱ����...\n");

    person_node* ptr = L->next;
    while (ptr != NULL)
    {
        fprintf(fp, "\n%s %s %s %s %s", ptr->name, ptr->sex,ptr->age, ptr->tel_num, ptr->address);
        ptr = ptr->next;
    }
    fclose(fp);
}

void searchPerson()
{
    int k = 1;
    while (k == 1)
    {
        printf("-------------------��ѯ��ϵ��--------------------------------\n");
        char search_name[10];
        printf("�������ѯ������");
        scanf("%s", search_name);
        person_node* ptr = L->next;
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
                    printf("->������%s", ptr->name);
                    printf("\t�Ա�%s", ptr->sex);
                    printf("\t���䣺%s", ptr->age);
                    printf("\t�绰��%s", ptr->tel_num);
                    printf("\t��ַ��%s\n", ptr->address);
                }
                else if(ptr->next==NULL) printf("û���ҵ�%s����Ϣ��\n",search_name);
                ptr=ptr->next;
            }
        }
        printf("------------------------------------------------------\n");
        printf("...����'0'���ز˵�...����'1'������ѯ...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
