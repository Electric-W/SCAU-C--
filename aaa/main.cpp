#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

#define NAME_MAX 20
#define TELE_MAX 12
#define SEX_MAX  5
#define ADDR_MAX 50

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char address[ADDR_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int size;
	int capacity;
}Contact;

//初始化通讯录
void InitContact(Contact* pc);
//增加联系人
void AddContact(Contact* pc);
//删除联系人
void DelContact(Contact* pc);
//查找联系人
void SearchContact(Contact* pc);
//更改联系人信息
void ModifyContact(Contact* pc);
//显示联系人
void ShowContact(Contact* pc);
//对通讯录进行排序
void paixu(Contact* pc);
//保存通讯录
void SaveContact(Contact* pc);
//销毁通讯录
void DestoryContact(Contact* pc);
void CheckCapacity(Contact* pc);
//加载数据
void LoadContact(Contact* pc)
{
	PeoInfo tmp;
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(pc);
		pc->data[pc->size] = tmp;
		pc->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	//开辟三个大小的空间
	pc->data = (PeoInfo*)malloc(sizeof(PeoInfo)* 3);
	if (pc->data==NULL)
	{
		printf("%s", strerror(errno));
		exit(-1);
	}

	pc->size = 0;
	pc->capacity = 3;
	//加载数据到通讯录上
	LoadContact(pc);
}

void CheckCapacity(Contact* pc)
{
	if (pc->capacity == pc->size)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo)*(pc->capacity * 2));
		if (tmp == NULL)
		{
			printf("%s", strerror(errno));
			exit(-1);
		}
		pc->data = tmp;
		pc->capacity *= 2;
		printf("扩容成功\n");
	}
}

//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	//检查容量
	CheckCapacity(pc);
	printf("请输入你要添加人的姓名:>");
	scanf("%s", pc->data[pc->size].name);
	printf("请输入你要添加人的性别:>");
	scanf("%s", pc->data[pc->size].sex);
	printf("请输入你要添加人的年龄:>");
	scanf("%d", &(pc->data[pc->size].age));
	printf("请输入你要添加人的电话号码:>");
	scanf("%s", pc->data[pc->size].tele);
	printf("请输入你要添加人的家庭住址:>");
	scanf("%s", pc->data[pc->size].address);

	pc->size++;
	printf("增加成功\n");
	system("pause");
}

int FindPeopleByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("通讯录为空\n");
		system("pause");
		return;
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入你要删除联系人的姓名:>");
		scanf("%s", name);
		//查找联系人
		int pos = FindPeopleByName(pc,name);
		if (pos == -1)
		{
			printf("该联系人不存在\n");
			printf("删除失败\n");
			system("pause");
		}
		else
		{
			//删除
			int i = 0;
			for (i = pos; i < pc->size - 1; i++)
			{
				pc->data[i] = pc->data[i + 1];
			}

			pc->size--;
			printf("删除成功\n");
			system("pause");
		}
	}
}

//查找联系人
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("通讯录为空\n");
		system("pause");
		return;
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入你要查找联系人的姓名:>");
		scanf("%s", name);
		//查找联系人
		int pos = FindPeopleByName(pc, name);
		if (pos == -1)
		{
			printf("该联系人不存在\n");
			printf("查找失败\n");
			system("pause");
		}
		else
		{
			printf("查找成功\n");
			//打印
			int j = 0;
			for (j = 0; j < 21; j++)
			{
				printf("——");
			}
			printf("\n");
			//打印标题
			printf("|%-15s|%-5s|%-5s|%-12s|%-42s\b|\n", "姓名", "性别", "年龄", "电话", "家庭住址");
			for (j = 0; j < 21; j++)
			{
				printf("——");
			}
			printf("\n");
			printf("|%-15s|%-5s|%-5d|%-12s|%-42s\b|\n",
				pc->data[pos].name,
				pc->data[pos].sex,
				pc->data[pos].age,
				pc->data[pos].tele,
				pc->data[pos].address);
			for (j = 0; j < 21; j++)
			{
				printf("——");
			}
			printf("\n");
			system("pause");
		}
	}
}

void ModifyMenu()
{
	printf("---------------------------\n");
	printf("-----1.姓名     2.性别-----\n");
	printf("-----3.年龄     4.电话-----\n");
	printf("-----5.家庭住址 0.退出-----\n");
	printf("---------------------------\n");
}

//更改联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("通讯录为空\n");
		system("pause");
		return;
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入你要更改的联系人的姓名:>");
		scanf("%s", name);
		//查找联系人
		int pos = FindPeopleByName(pc, name);
		if (pos == -1)
		{
			printf("该联系人不存在\n");
			printf("更改信息失败\n");
			system("pause");
		}
		else
		{
			int input = 0;

			do
			{
				system("cls");
				ModifyMenu();
				printf("请选择:>");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					printf("请输入修改后的姓名:>");
					scanf("%s", pc->data[pos].name);
					printf("修改成功\n");
					system("pause");
					break;
				case 2:
					printf("请输入修改后的性别:>");
					scanf("%s", pc->data[pos].sex);
					printf("修改成功\n");
					system("pause");
					break;
				case 3:
					printf("请输入修改后的年龄:>");
					scanf("%d", &(pc->data[pos].age));
					printf("修改成功\n");
					system("pause");
					break;
				case 4:
					printf("请输入修改后的电话:>");
					scanf("%s", pc->data[pos].tele);
					printf("修改成功\n");
					system("pause");
					break;
				case 5:
					printf("请输入修改后的家庭住址:>");
					scanf("%s", pc->data[pos].address);
					printf("修改成功\n");
					system("pause");
					break;
				case 0:
					printf("退出修改\n");
					system("pause");
					break;
				default:
					printf("选择错误\n");
					system("pause");
					break;
				}
			} while (input);
		}
	}
}

//显示联系人
void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("通讯录为空\n");
		system("pause");
		return;
	}
	//打印横线
	int j = 0;
	for (j = 0; j < 21; j++)
	{
		printf("——");
	}
	printf("\n");
	printf("|%42s\t\t\t\t\t\t\b\b\b\b\b|\n", "通讯录");
	for (j = 0; j < 21; j++)
	{
		printf("——");
	}
	printf("\n");
	//打印标题
	printf("|%-15s|%-5s|%-5s|%-12s|%-42s\b|\n", "姓名", "性别", "年龄", "电话", "家庭住址");
	//打印信息
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		for (j = 0; j < 21; j++)
		{
			printf("——");
		}
		printf("\n");
		printf("|%-15s|%-5s|%-5d|%-12s|%-42s\b|\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].address);
	}
	for (j = 0; j < 21; j++)
	{
		printf("——");
	}
	printf("\n");
	system("pause");
}

void SortMenu()
{
	printf("-------------------------\n");
	printf("-----1.姓名   2.年龄-----\n");
	printf("-------------------------\n");
}

//对通讯录进行排序
void paixu(Contact* pc)
{
	if (pc->size == 0)
	{
		printf("通讯录为空,无法进行排序\n");
		return;
	}
	else
	{
		int input = 0;
        PeoInfo e1,e2;
		do
		{
			SortMenu();
			printf("请选择你要用什么信息进行排序:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				qsort(pc->data, pc->size, sizeof(PeoInfo), (strcmp(e1->name, e2->name)));
				break;
			case 2:
				qsort(pc->data, pc->size, sizeof(PeoInfo), (e1->age - e2->age));
				break;
			default:
				printf("选择错误\n");
				break;
			}
		} while (input != 1 && input != 2);
	}
	printf("排序成功\n");
}

//保存通讯录
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		printf("error");
		exit(-1);
	}

	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		fwrite(&(pc->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功\n");
}

//销毁通讯录
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}
void menu()
{
	printf("--------------------------------------\n");
	printf("------------通讯录  ------------\n");
	printf("------------1.添加联系人--------------\n");
	printf("------------2.删除联系人--------------\n");
	printf("------------3.查找联系人--------------\n");
	printf("------------4.更改联系人信息----------\n");
	printf("------------5.显示通讯录--------------\n");
	printf("------------6.对联系人进行排序--------\n");
	printf("------------7.保存通讯录--------------\n");
	printf("------------0.退出通讯录--------------\n");
	printf("--------------------------------------\n");
}

int main()
{
	//创建一个通讯录
	Contact TXL;
	//初始化通讯录
	InitContact(&TXL);

	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&TXL);
			break;
		case 2:
			DelContact(&TXL);
			break;
		case 3:
			SearchContact(&TXL);
			break;
		case 4:
			ModifyContact(&TXL);
			break;
		case 5:
			ShowContact(&TXL);
			break;
		case 6:
			paixu(&TXL);
			break;
		case 7:
			SaveContact(&TXL);
			break;
		case 0:
			SaveContact(&TXL);
			DestoryContact(&TXL);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}
