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
    printf("请输入三位数字用于查找电话号码\n");
    printf("号码>");
    scanf("%s",phone_num);
    person_node* ptr = L->next;
    if (ptr == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            if(phone_num[0]==ptr->tel_num[0]&&phone_num[1]==ptr->tel_num[1]&&phone_num[2]==ptr->tel_num[2])
            {
                printf("姓名：%s", ptr->name);
                printf("\n性别：%s", ptr->sex);
                printf("\t年龄：%s", ptr->age);
                printf("\t电话：%s", ptr->tel_num);
                printf("\t地址：%s", ptr->address);
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("手机号码前三位为%s的联系人一共有%d位！\n\n",phone_num,statistics);
    printf("...输入'0'返回菜单...");
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
    printf("请输入性别\n");
    printf("（男/女）>");
    scanf("%s",sex_people);
    person_node* ptr = L->next;
    if (ptr == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp(sex_people,ptr->sex)==0)
            {
                printf("姓名：%s", ptr->name);
                printf("\n性别：%s", ptr->sex);
                printf("\t年龄：%s", ptr->age);
                printf("\t电话：%s", ptr->tel_num);
                printf("\t地址：%s", ptr->address);
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("性别为%s的联系人一共有%d位！\n\n",sex_people,statistics);
    printf("...输入'0'返回菜单...");
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
        printf("排序成功！");
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
    printf("排序成功！\n");
    printf("...输入'0'返回菜单\n");
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
        printf("排序成功！");
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
    printf("排序成功！\n");
    printf("...输入'0'返回菜单\n");
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
        printf("排序成功！");
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
    printf("排序成功！\n");
    printf("...输入'0'返回菜单\n");
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
        printf("排序成功！");
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
    printf("排序成功！\n");
    printf("...输入'0'返回菜单\n");
    scanf("%d", &k);
    if (k == 0)
        return;
}
void change_something()
{
    int k = 1;
    while (k == 1)
    {
        printf("-------------------修改联系人--------------------------------\n");
        char search_name[10],q[100],p[100];
        printf("请输入要修改的联系人姓名：");
        scanf("%s", search_name);
        person_node* ptr = (person_node*)malloc(sizeof(person_node));
        ptr=L->next;
        if (ptr == NULL)
            printf("...通讯录中暂无联系人...\n");
        else
        {
            int count = 0;
            while (ptr != NULL)
            {
                if (strcmp(ptr->name, search_name) == 0)
                {
                    printf("成功找到%s的具体信息：\n",ptr->name);
                    printf("姓名：%s", ptr->name);
                    printf("\t性别：%s", ptr->sex);
                    printf("\t年龄：%s", ptr->age);
                    printf("\t电话：%s", ptr->tel_num);
                    printf("\t地址：%s\n", ptr->address);
                    printf("你想要修改%s的什么信息(name, sex, tel_num, age, address)：",search_name);
                    scanf("%s",q);
                    if((strcmp(q,"name"))&(strcmp(q,"sex"))&(strcmp(q,"age"))&(strcmp(q,"tel_num"))&(strcmp(q,"address")))
                    {
                        printf("请输入正确的想要修改的信息！\n");
                        break;
                    }
                    printf("你想要把 %s 的 %s 修改成：",search_name,q);
                    scanf("%s",p);
                    if(!(strcmp(q,"name")))strcpy(ptr->name, p);
                    if(!(strcmp(q,"sex")))strcpy(ptr->sex, p);
                    if(!(strcmp(q,"tel_num")))strcpy(ptr->tel_num, p);
                    if(!(strcmp(q,"age")))strcpy(ptr->age, p);
                    if(!(strcmp(q,"address")))strcpy(ptr->address, p);
                    printf("成功把 %s 的 %s 修改为 %s!!!\n", search_name,q,p);
                    break;
                }
                else if(ptr->next=NULL) printf("没有找到%s的信息！",search_name);
                ptr = ptr->next;
            }
        }
        printf("------------------------------------------------------\n");
        printf("...输入'0'返回菜单...输入'1'继续修改...\n");
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
        printf("请选择要排序的方式\n");
        printf("*----------------------------------*\n");
        printf("|     1.按名字      2.按年龄       |\n");
        printf("|     3.按地址      4.按手机号     |\n");
        printf("|     0.退出                       |\n");
        printf("*----------------------------------*\n");
        printf("选择>");
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
            printf("输入错误!请正确的输入想要的排序方式！\n");
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
    printf("\t\t\t通讯录系统        \n\n");
    printf("\t\t  1.查看通讯录        \n");
    printf("\t\t  2.添加联系人        \n");
    printf("\t\t  3.删除联系人        \n");
    printf("\t\t  4.查询联系人        \n");
    printf("\t\t  5.修改联系人信息    \n");
    printf("\t\t  6.联系人排序      \n");
    printf("\t\t  7.查看手机号码前三位相同的联系人\n");
    printf("\t\t  8.查看所有男性/女性联系人\n");
    printf("\t\t  0.保存并退出\n");
    printf("------------------------------------------------------\n");
}

void addPerson()
{
    int k = 1;

    while (k == 1)
    {
        printf("-------------------新建联系人--------------------------------\n");
        printf("\t温馨提示：为防止程序崩溃，请严格按照要求添加联系人，谢谢！ \n");
        printf("-------------------------------------------------------------\n");
        person_node* new_person = (person_node *)malloc(sizeof(person_node));
        printf("请输入联系人姓名:");
        scanf("%s", new_person->name);
        printf("请输入联系人性别（男/女）：");
        scanf("%s", new_person->sex);
        printf("请输入年龄：");
        scanf("%s", new_person->age);
        printf("请输入联系人电话（15字以内）：");
        scanf("%s", new_person->tel_num);
        printf("请输入联系人地址（20字以内）：");
        scanf("%s", new_person->address);
        printf("------------------------------------------------------\n");

        person_node* ptr = L;
        while (ptr->next != NULL) //ptr指向链表L末尾结点
            ptr = ptr->next;

        ptr->next = new_person;
        new_person->next = NULL;
        printf("...输入'0'返回菜单...输入'1'继续添加...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}

void displayPersons()
{
    person_node* ptr = L->next;
    if (ptr == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            printf("*******************************************************************\n");
            printf("*姓名：%s", ptr->name);
            printf("\t*性别：%s", ptr->sex);
            printf("\t*年龄：%s", ptr->age);
            printf("\t*电话：%s", ptr->tel_num);
            printf("\t*地址：%s", ptr->address);
            printf("\n");
            ptr = ptr->next;
        }
    }
    printf("*******************************************************************\n");
    printf("...输入'0'返回菜单...");
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
        printf("...打开联系人文件时出错...\n");
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
        printf("-------------------删除联系人--------------------------------\n");
        person_node* ptr = L->next;
        person_node* pre = L;
        if (ptr == NULL)
            printf("...通讯录中暂无联系人...\n");
        else
        {
            printf("请输入删除联系人的姓名：");
            char del_name[10];
            scanf("%s", del_name);
            while (ptr != NULL)
            {
                if (strcmp(ptr->name, del_name) == 0)
                {
                    printf("...删除联系人条目...\n");
                    printf("->姓名：%s", ptr->name);
                    printf("\t性别：%s", ptr->sex);
                    printf("\t年龄：%s", ptr->age);
                    printf("\t电话：%s", ptr->tel_num);
                    printf("\t地址：%s<-", ptr->address);

                    printf("\n确认删除吗？y/n\n");
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
        printf("...输入'0'返回菜单...输入'1'继续删除...\n");
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
        printf("...打开联系人文件时出错...\n");

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
        printf("-------------------查询联系人--------------------------------\n");
        char search_name[10];
        printf("请输入查询姓名：");
        scanf("%s", search_name);
        person_node* ptr = L->next;
        if (ptr == NULL)
            printf("...通讯录中暂无联系人...\n");
        else
        {
            int count = 0;
            while (ptr != NULL)
            {
                if (strcmp(ptr->name, search_name) == 0)
                {
                    count++;
                    printf("...查询到联系人%d位...\n", count);
                    printf("->姓名：%s", ptr->name);
                    printf("\t性别：%s", ptr->sex);
                    printf("\t年龄：%s", ptr->age);
                    printf("\t电话：%s", ptr->tel_num);
                    printf("\t地址：%s\n", ptr->address);
                }
                else if(ptr->next==NULL) printf("没有找到%s的信息！\n",search_name);
                ptr=ptr->next;
            }
        }
        printf("------------------------------------------------------\n");
        printf("...输入'0'返回菜单...输入'1'继续查询...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
