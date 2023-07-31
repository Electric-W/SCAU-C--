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

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//������ϵ��
void AddContact(Contact* pc);
//ɾ����ϵ��
void DelContact(Contact* pc);
//������ϵ��
void SearchContact(Contact* pc);
//������ϵ����Ϣ
void ModifyContact(Contact* pc);
//��ʾ��ϵ��
void ShowContact(Contact* pc);
//��ͨѶ¼��������
void paixu(Contact* pc);
//����ͨѶ¼
void SaveContact(Contact* pc);
//����ͨѶ¼
void DestoryContact(Contact* pc);
void CheckCapacity(Contact* pc);
//��������
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

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	assert(pc);
	//����������С�Ŀռ�
	pc->data = (PeoInfo*)malloc(sizeof(PeoInfo)* 3);
	if (pc->data==NULL)
	{
		printf("%s", strerror(errno));
		exit(-1);
	}

	pc->size = 0;
	pc->capacity = 3;
	//�������ݵ�ͨѶ¼��
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
		printf("���ݳɹ�\n");
	}
}

//������ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	//�������
	CheckCapacity(pc);
	printf("��������Ҫ����˵�����:>");
	scanf("%s", pc->data[pc->size].name);
	printf("��������Ҫ����˵��Ա�:>");
	scanf("%s", pc->data[pc->size].sex);
	printf("��������Ҫ����˵�����:>");
	scanf("%d", &(pc->data[pc->size].age));
	printf("��������Ҫ����˵ĵ绰����:>");
	scanf("%s", pc->data[pc->size].tele);
	printf("��������Ҫ����˵ļ�ͥסַ:>");
	scanf("%s", pc->data[pc->size].address);

	pc->size++;
	printf("���ӳɹ�\n");
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

//ɾ����ϵ��
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		system("pause");
		return;
	}
	else
	{
		char name[NAME_MAX];
		printf("��������Ҫɾ����ϵ�˵�����:>");
		scanf("%s", name);
		//������ϵ��
		int pos = FindPeopleByName(pc,name);
		if (pos == -1)
		{
			printf("����ϵ�˲�����\n");
			printf("ɾ��ʧ��\n");
			system("pause");
		}
		else
		{
			//ɾ��
			int i = 0;
			for (i = pos; i < pc->size - 1; i++)
			{
				pc->data[i] = pc->data[i + 1];
			}

			pc->size--;
			printf("ɾ���ɹ�\n");
			system("pause");
		}
	}
}

//������ϵ��
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		system("pause");
		return;
	}
	else
	{
		char name[NAME_MAX];
		printf("��������Ҫ������ϵ�˵�����:>");
		scanf("%s", name);
		//������ϵ��
		int pos = FindPeopleByName(pc, name);
		if (pos == -1)
		{
			printf("����ϵ�˲�����\n");
			printf("����ʧ��\n");
			system("pause");
		}
		else
		{
			printf("���ҳɹ�\n");
			//��ӡ
			int j = 0;
			for (j = 0; j < 21; j++)
			{
				printf("����");
			}
			printf("\n");
			//��ӡ����
			printf("|%-15s|%-5s|%-5s|%-12s|%-42s\b|\n", "����", "�Ա�", "����", "�绰", "��ͥסַ");
			for (j = 0; j < 21; j++)
			{
				printf("����");
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
				printf("����");
			}
			printf("\n");
			system("pause");
		}
	}
}

void ModifyMenu()
{
	printf("---------------------------\n");
	printf("-----1.����     2.�Ա�-----\n");
	printf("-----3.����     4.�绰-----\n");
	printf("-----5.��ͥסַ 0.�˳�-----\n");
	printf("---------------------------\n");
}

//������ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		system("pause");
		return;
	}
	else
	{
		char name[NAME_MAX];
		printf("��������Ҫ���ĵ���ϵ�˵�����:>");
		scanf("%s", name);
		//������ϵ��
		int pos = FindPeopleByName(pc, name);
		if (pos == -1)
		{
			printf("����ϵ�˲�����\n");
			printf("������Ϣʧ��\n");
			system("pause");
		}
		else
		{
			int input = 0;

			do
			{
				system("cls");
				ModifyMenu();
				printf("��ѡ��:>");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					printf("�������޸ĺ������:>");
					scanf("%s", pc->data[pos].name);
					printf("�޸ĳɹ�\n");
					system("pause");
					break;
				case 2:
					printf("�������޸ĺ���Ա�:>");
					scanf("%s", pc->data[pos].sex);
					printf("�޸ĳɹ�\n");
					system("pause");
					break;
				case 3:
					printf("�������޸ĺ������:>");
					scanf("%d", &(pc->data[pos].age));
					printf("�޸ĳɹ�\n");
					system("pause");
					break;
				case 4:
					printf("�������޸ĺ�ĵ绰:>");
					scanf("%s", pc->data[pos].tele);
					printf("�޸ĳɹ�\n");
					system("pause");
					break;
				case 5:
					printf("�������޸ĺ�ļ�ͥסַ:>");
					scanf("%s", pc->data[pos].address);
					printf("�޸ĳɹ�\n");
					system("pause");
					break;
				case 0:
					printf("�˳��޸�\n");
					system("pause");
					break;
				default:
					printf("ѡ�����\n");
					system("pause");
					break;
				}
			} while (input);
		}
	}
}

//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		system("pause");
		return;
	}
	//��ӡ����
	int j = 0;
	for (j = 0; j < 21; j++)
	{
		printf("����");
	}
	printf("\n");
	printf("|%42s\t\t\t\t\t\t\b\b\b\b\b|\n", "ͨѶ¼");
	for (j = 0; j < 21; j++)
	{
		printf("����");
	}
	printf("\n");
	//��ӡ����
	printf("|%-15s|%-5s|%-5s|%-12s|%-42s\b|\n", "����", "�Ա�", "����", "�绰", "��ͥסַ");
	//��ӡ��Ϣ
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		for (j = 0; j < 21; j++)
		{
			printf("����");
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
		printf("����");
	}
	printf("\n");
	system("pause");
}

void SortMenu()
{
	printf("-------------------------\n");
	printf("-----1.����   2.����-----\n");
	printf("-------------------------\n");
}

//��ͨѶ¼��������
void paixu(Contact* pc)
{
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷���������\n");
		return;
	}
	else
	{
		int input = 0;
        PeoInfo e1,e2;
		do
		{
			SortMenu();
			printf("��ѡ����Ҫ��ʲô��Ϣ��������:>");
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
				printf("ѡ�����\n");
				break;
			}
		} while (input != 1 && input != 2);
	}
	printf("����ɹ�\n");
}

//����ͨѶ¼
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
	printf("����ɹ�\n");
}

//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}
void menu()
{
	printf("--------------------------------------\n");
	printf("------------ͨѶ¼  ------------\n");
	printf("------------1.�����ϵ��--------------\n");
	printf("------------2.ɾ����ϵ��--------------\n");
	printf("------------3.������ϵ��--------------\n");
	printf("------------4.������ϵ����Ϣ----------\n");
	printf("------------5.��ʾͨѶ¼--------------\n");
	printf("------------6.����ϵ�˽�������--------\n");
	printf("------------7.����ͨѶ¼--------------\n");
	printf("------------0.�˳�ͨѶ¼--------------\n");
	printf("--------------------------------------\n");
}

int main()
{
	//����һ��ͨѶ¼
	Contact TXL;
	//��ʼ��ͨѶ¼
	InitContact(&TXL);

	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

	return 0;
}
