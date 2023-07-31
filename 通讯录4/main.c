#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>

void menu();//初始菜单
void ini_list();//文件读取
void add_people();//联系人添加
void display_persons();//联系人输出
void delete_person();//联系人删除
void save_list();//文件输出
void search_person();//联系人查找
void search_groups_phone();//电话分类
void static_groups_sex();//性别分类
void display_number();//链表长获取函数
void sort_people_by_name();//名字排序
void sort_people_by_addr();//地址排序
void sort_people_by_age();//年龄排序
void sort_people_by_tel();//电话排序
void change_something();//联系人修改
void sorting();//排序菜单
void static_people_age();//年龄段分类统计
void search_groups_sex();//性别查找
int login();//登录账户函数
struct A
{
    char name[10];//名字
    char tel_num[20];//电话号码
    char address[20];//地址
    char age[3];//年龄
    char sex[5];//性别
    struct  A *next;
};
typedef struct A NODE_P;
NODE_P *contact_now;

typedef struct LNode
{
    char name[10];//名字
    char pass[10];//密码
    struct LNode *next;
} ;
typedef struct LNode ANode;
typedef struct LNode* pNode;

pNode createList()//创建用户链表
{
    pNode pHead = (pNode)malloc(sizeof(ANode));
    pHead->next=NULL;
    //头结点不存放数据
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

        //检测到录入完毕后将分配的空间清除掉
        if(2!=fscanf(fp,"%s%s",temp->name,temp->pass))
        {
            free(temp);
            break;
        }
        cur->next=temp;
        cur = temp;

        //使最后一个节点指向空，方便以后判断
        cur->next = NULL;
    }
    return pHead;
}


int login(pNode head)//登录函数
{
    if(NULL==head->next)
    {
        printf("未有账号录入\n");
        getch();
        return 0;
    }
    char name[10];
    char pass[10];
    printf("请输入账号:");
    scanf("%s",name);
    printf("请输入密码:");
    scanf("%s",pass);
    pNode temp = head->next;
    while(temp)
    {
        if(0==strcmp(temp->name,name) && 0==strcmp(temp->pass,pass))
        {
            printf("登录成功！请按回车键进入");
            getch();
            return 1;
        }
        temp = temp->next;
    }
    printf("未找到该用户！");
    getch();
    return 0;
}

void writeToFile(pNode head)//写入txt文件，每一行存在一个用户
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



void registerUser(pNode head)//注册用户
{
    pNode temp = head->next;
    //当表中无用户直接在头结点后注册
    if(!temp)
    {
        temp = (pNode)malloc(sizeof(ANode));
        head->next = temp;
    }
    else
    {
        //表中有用户则在最后一个节点后生成新节点
        while(temp->next)
        {
            temp = temp->next;
        }
        pNode last = (pNode)malloc(sizeof(ANode));
        temp->next = last;
        temp = last;
    }
    printf("请输入账号:");
    scanf("%s",temp->name);
    printf("请输入密码:");
    scanf("%s",temp->pass);
    temp->next=NULL;
}

int login_menu()
{
    int choice;
    printf("\t1.登录\n");
    printf("\t2.注册\n");
    printf("\t#.退出\n");
    printf("请选择:");
    scanf("%d",&choice);
    printf("\t*******************************\n");
    return choice;
}
int list_size;
int main()
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 16);//界面色彩设定
    contact_now  = (NODE_P *)malloc(sizeof(NODE_P));
    ini_list();
    int choice;
    pNode head = createList();
    printf("\n\n");
    printf("\t*******************************\n");
    printf("\t*                             *\n");
    printf("\t*      欢迎来到通讯录系统     *\n");
    printf("\t*                             *\n");
    printf("\t*******************************\n");
    printf("\n\n");
    while(1)
    {
        choice = login_menu();//登录界面
        if(1==choice)
        {
            if(login(head))//登录函数
            {
                break;
            }
            system("cls");
        }
        else if(2==choice)
        {
            system("cls");
            registerUser(head);//注册函数
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
        menu();//通讯录功能菜单
        printf("请选择>");
        scanf("%d", &k);
        if (k == 1)
        {
            system("cls");
            display_persons();//显示所有人
        }
        else if (k == 2)
        {
            system("cls");
            add_people();//加人
        }
        else if (k == 3)
        {
            system("cls");
            delete_person();//删人
        }
        else if (k == 4)
        {
            system("cls");
            search_person();//找人
        }
        else if(k==5)
        {
            system("cls");
            change_something();//改信息
        }
        else if (k == 6)
        {
            system("cls");
            sorting();//排序菜单
        }
        else if(k==7)
        {
            system("cls");
            search_groups_phone();//电话前三位统计
        }
        else if(k==8)
        {
            system("cls");

            search_groups_sex();//性别查找
        }
        else if(k==9)
        {
            system("cls");
            static_groups_sex();//性别统计
        }
        else if(k==10)
        {
            system("cls");
            static_groups_age();//年龄统计
        }
        else if (k == 0)
        {
            save_list();//联系人保存
            writeToFile(head);//账号保存
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
    printf("请输入三位数字用于查找电话号码\n");
    printf("号码>");
    scanf("%s",phone_num);
    NODE_P* ptr = contact_now->next;
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
void static_groups_sex()
{
    int statistics=0;
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp("男",ptr->sex)==0)
            {
                printf("*姓名：%s", ptr->name);
                printf("\t*性别：%s", ptr->sex);
                printf("\t*年龄：%s", ptr->age);
                printf("\t*电话：%s", ptr->tel_num);
                printf("\t*地址：%s", ptr->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("性别为男性的联系人一共有%d位！\n\n",statistics);
    statistics=0;
    NODE_P* ptr1 = contact_now->next;
    if (ptr1 == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr1 != NULL)
        {
            if(strcmp("女",ptr1->sex)==0)
            {
                printf("*姓名：%s", ptr1->name);
                printf("\t*性别：%s", ptr1->sex);
                printf("\t*年龄：%s", ptr1->age);
                printf("\t*电话：%s", ptr1->tel_num);
                printf("\t*地址：%s", ptr1->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr1 = ptr1->next;
        }
    }
    printf("性别为女性的联系人一共有%d位！\n\n",statistics);
    printf("...输入'0'返回菜单...");
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
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp("0",ptr->age)<0&&strcmp("9",ptr->age)>=0&&strlen(ptr->age)==1)
            {
                printf("*姓名：%s", ptr->name);
                printf("\t*性别：%s", ptr->sex);
                printf("\t*年龄：%s", ptr->age);
                printf("\t*电话：%s", ptr->tel_num);
                printf("\t*地址：%s", ptr->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
    printf("10岁以下的联系人一共有%d位！\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr1 = contact_now->next;
    if (ptr1 == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr1 != NULL)
        {
            if((strcmp("10",ptr1->age)<=0&&strcmp("20",ptr1->age)>=0)&&strlen(ptr1->age)==2)
            {
                printf("*姓名：%s", ptr1->name);
                printf("\t*性别：%s", ptr1->sex);
                printf("\t*年龄：%s", ptr1->age);
                printf("\t*电话：%s", ptr1->tel_num);
                printf("\t*地址：%s", ptr1->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr1 = ptr1->next;
        }
    }
    printf("10至20岁的联系人一共有%d位！\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr2 = contact_now->next;
    if (ptr2 == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr2 != NULL)
        {
            if((strcmp("20",ptr2->age)<0&&strcmp("40",ptr2->age)>=0)&&strlen(ptr2->age)==2)
            {
                printf("*姓名：%s", ptr2->name);
                printf("\t*性别：%s", ptr2->sex);
                printf("\t*年龄：%s", ptr2->age);
                printf("\t*电话：%s", ptr2->tel_num);
                printf("\t*地址：%s", ptr2->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr2 = ptr2->next;
        }
    }
    printf("20至40岁的联系人一共有%d位！\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr3 = contact_now->next;
    if (ptr3 == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr3 != NULL)
        {
            if((strcmp("40",ptr3->age)<0&&strcmp("60",ptr3->age)>=0)&&strlen(ptr3->age)==2)
            {
                printf("*姓名：%s", ptr3->name);
                printf("\t*性别：%s", ptr3->sex);
                printf("\t*年龄：%s", ptr3->age);
                printf("\t*电话：%s", ptr3->tel_num);
                printf("\t*地址：%s", ptr3->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr3 = ptr3->next;
        }
    }
    printf("40至60岁的联系人一共有%d位！\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr4 = contact_now->next;
    if (ptr4 == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr4 != NULL)
        {
            if((strcmp("60",ptr4->age)<0&&strcmp("80",ptr4->age)>=0)&&strlen(ptr4->age)==2)
            {
                printf("*姓名：%s", ptr4->name);
                printf("\t*性别：%s", ptr4->sex);
                printf("\t*年龄：%s", ptr4->age);
                printf("\t*电话：%s", ptr4->tel_num);
                printf("\t*地址：%s", ptr4->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr4 = ptr4->next;
        }
    }
    printf("60至80岁的联系人一共有%d位！\n\n",statistics);
    printf("===========================\n");
    statistics=0;
    NODE_P* ptr5 = contact_now->next;
    if (ptr5 == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr4 != NULL)
        {
            if(strcmp("80",ptr4->age)<0)
            {
                printf("*姓名：%s", ptr4->name);
                printf("\t*性别：%s", ptr4->sex);
                printf("\t*年龄：%s", ptr4->age);
                printf("\t*电话：%s", ptr4->tel_num);
                printf("\t*地址：%s", ptr4->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            if(strlen(ptr4->age)==3)
            {
                printf("*姓名：%s", ptr4->name);
                printf("\t*性别：%s", ptr4->sex);
                printf("\t*年龄：%s", ptr4->age);
                printf("\t*电话：%s", ptr4->tel_num);
                printf("\t*地址：%s", ptr4->address);
                printf("\n");
                statistics++;
                printf("\n");
            }
            ptr4 = ptr4->next;
        }
    }
    printf("80岁以上的联系人一共有%d位！\n\n",statistics);
    printf("===========================\n");
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
        printf("排序成功！");
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
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("排序成功！");
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
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("排序成功！");
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
    NODE_P *sort1=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort2=(NODE_P *)malloc(sizeof(NODE_P));
    NODE_P *sort3=(NODE_P *)malloc(sizeof(NODE_P));
    int i,j;
    system("cls");
    if(contact_now->next==NULL||contact_now->next->next==NULL)
    {
        printf("排序成功！");
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
        printf("*******************修改联系人********************************\n");
        char search_name[10],q[100],p[100];
        printf("请输入要修改的联系人姓名：");
        scanf("%s", search_name);
        NODE_P* ptr = (NODE_P*)malloc(sizeof(NODE_P));
        ptr=contact_now->next;
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
                    printf("*姓名：%s", ptr->name);
                    printf("\t*性别：%s", ptr->sex);
                    printf("\t*年龄：%s", ptr->age);
                    printf("\t*电话：%s", ptr->tel_num);
                    printf("\t*地址：%s", ptr->address);
                    printf("\n");
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

                }
                else if(ptr->next==NULL)
                {
                    printf("没有找到%s的信息！",search_name);
                }
                ptr = ptr->next;
            }
        }
        printf("******************************************************\n");
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
        printf("************************************\n");
        printf("*     1.按名字      2.按年龄       *\n");
        printf("*     3.按地址      4.按手机号     *\n");
        printf("*     0.退出                       *\n");
        printf("************************************\n");
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
void menu()
{
    printf("******************************************************\n");
    printf("\t\t\t通讯录系统        \n\n");
    printf("\t\t  1.查看通讯录        \n");
    printf("\t\t  2.添加联系人        \n");
    printf("\t\t  3.删除联系人        \n");
    printf("\t\t  4.查询联系人        \n");
    printf("\t\t  5.修改联系人信息    \n");
    printf("\t\t  6.联系人排序      \n");
    printf("\t\t  7.查看手机号码前三位相同的联系人\n");
    printf("\t\t  8.查询所有男性（女性）联系人\n");
    printf("\t\t  9.统计所有男性/女性联系人\n");
    printf("\t\t 10.统计各年龄段的联系人\n");
    printf("\t\t  0.保存并退出\n");
    printf("******************************************************\n");
}
void search_groups_sex()
{
    int statistics=0;
    char sex_people[3];
    printf("请输入性别\n");
    printf("（男/女）>");
    scanf("%s",sex_people);
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            if(strcmp(sex_people,ptr->sex)==0)
            {
                printf("*姓名：%s", ptr->name);
                printf("\t*性别：%s", ptr->sex);
                printf("\t*年龄：%s", ptr->age);
                printf("\t*电话：%s", ptr->tel_num);
                printf("\t*地址：%s", ptr->address);
                printf("\n");
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
void add_people()//添加人
{
    int k = 1;

    while (k == 1)
    {
        printf("*******************新建联系人********************************\n");
        printf("\t温馨提示：为防止程序崩溃，请严格按照要求添加联系人，谢谢！ \n");
        printf("*************************************************************\n");
        NODE_P* new_person = (NODE_P *)malloc(sizeof(NODE_P));
        printf("请输入联系人姓名:");
        scanf("%s", new_person->name);
        printf("------------------------------------------------------\n");
        printf("请输入联系人性别（男/女）：");
        scanf("%s", new_person->sex);
        printf("------------------------------------------------------\n");
        printf("请输入年龄：");
        scanf("%s", new_person->age);
        printf("------------------------------------------------------\n");
        printf("请输入联系人电话（15字以内）：");
        scanf("%s", new_person->tel_num);
        printf("------------------------------------------------------\n");
        printf("请输入联系人地址（20字以内）：");
        scanf("%s", new_person->address);
        printf("******************************************************\n");

        NODE_P* ptr = contact_now;
        while (ptr->next != NULL) //ptr指向链表contact_now末尾结点
            ptr = ptr->next;

        ptr->next = new_person;
        new_person->next = NULL;
        printf("...输入'0'返回菜单...输入'1'继续添加...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}

void display_persons()//
{
    NODE_P* ptr = contact_now->next;
    if (ptr == NULL)
        printf("...暂未添加任何联系人...\n");
    else
    {
        while (ptr != NULL)
        {
            printf("*******************************************************************\n");
            printf("*姓名：%s", ptr->name);
            printf("\t*性别：%s\n", ptr->sex);
            printf("*年龄：%s", ptr->age);
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
//运行时初始化链表，将文件内容载入
void ini_list()
{
    contact_now->next = NULL;

    FILE *fp;
    if ((fp = fopen("list_file.txt", "r")) == NULL)
    {
        printf("...打开联系人文件时出错...\n");
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
//删除人
void delete_person()
{
    int k = 1;
    while (k == 1)
    {
        printf("*******************删除联系人********************************\n");
        NODE_P* ptr = contact_now->next;
        NODE_P* pre = contact_now;
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
                    printf("*姓名：%s", ptr->name);
                    printf("\t*性别：%s", ptr->sex);
                    printf("\t*年龄：%s", ptr->age);
                    printf("\t*电话：%s", ptr->tel_num);
                    printf("\t*地址：%s", ptr->address);
                    printf("\n确认删除吗？  Y/N\n");
                    char input = '0';
                    while (input != 'Y' && input != 'N')
                    {
                        scanf("%c", &input);
                    }
                    if (input == 'N')//该节点不删除，寻找下一个符合条件的联系人
                    {
                        ptr = ptr->next;
                        pre = pre->next;
                        continue;
                    }
                    else if (input == 'Y')//删除节点
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
        printf("...输入'0'返回菜单...输入'1'继续删除...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
//输出内容
void save_list()
{
    if (contact_now->next == NULL)
        return;

    FILE *fp;
    if ((fp = fopen("list_file.txt", "w")) == NULL)
        printf("...打开联系人文件时出错...\n");

    NODE_P* ptr = contact_now->next;
    while (ptr != NULL)
    {
        fprintf(fp, "\n%s %s %s %s %s", ptr->name, ptr->sex,ptr->age, ptr->tel_num, ptr->address);//文件输出
        ptr = ptr->next;
    }
    fclose(fp);
}
//找人
void search_person()
{
    int k = 1;
    while (k == 1)
    {
        printf("********************查询联系人********************************\n");
        char search_name[10];
        printf("请输入查询姓名：");
        scanf("%s", search_name);
        NODE_P* ptr = contact_now->next;
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
                    printf("*姓名：%s", ptr->name);
                    printf("\t*性别：%s", ptr->sex);
                    printf("\t*年龄：%s", ptr->age);
                    printf("\t*电话：%s", ptr->tel_num);
                    printf("\t*地址：%s", ptr->address);
                    printf("\n");
                }
                else if(ptr->next==NULL) printf("没有找到%s的信息！\n",search_name);
                ptr=ptr->next;
            }
        }
        printf("******************************************************\n");
        printf("...输入'0'返回菜单...输入'1'继续查询...\n");
        scanf("%d", &k);
        if (k == 0)
            return;
    }
}
