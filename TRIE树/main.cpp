#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define Max 260
#define TRUE 1
#define FALSE 0
using namespace std;

typedef struct trie_tree_node
{
    struct trie_tree_node *next[Max];
    int if_end;
    int child_count;
    char word;
} TrieNode,*TrieTree,*TrieTreeNode;
void trie_insert(TrieTree root,char *word);
int searchTrie(TrieTree root,char *word);
TrieTree Trie_delect(TrieTree root,char *word,int locate);

void interface(){
  TrieTreeNode root;
  int choice;
  while(1)
 {

     printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~\n");
     printf("\t\t\t\t\t||��ӭ����Trie��||\n");
     printf("\t\t\t\t\t===================\n");
     printf("\t\t\t\t\t||1.Trie����ʼ��  |\n ");
     printf("\t\t\t\t\t||2.����Ԫ��      |\n ");
     printf("\t\t\t\t\t||3.ɾ��Ԫ��      |\n ");
     printf("\t\t\t\t\t||4.����Ԫ��      |\n");
     printf("\t\t\t\t\t||0.�˳�����      |\n ");
     printf("\t\t\t\t\t===================\n");

     printf("���������Ĳ�����");
     scanf("%d",&choice);
     while((getchar())!='\n');
     switch (choice)
     {
     case 1: {root = (TrieTreeNode)calloc(1, sizeof(TrieTreeNode));
               if (root==NULL) printf("��ʼ��ʧ�ܣ�\n");
               else printf("��ʼ���ɹ���\n");
               break;}

     case 2: {
                printf("������Ҫ¼���Ԫ�ظ�����");
                int num;
                scanf("%d",&num);
                while((getchar())!='\n');//��ջس������ĸ���
                char word[26];//һ��Ԫ�ص���󳤶���26
                for(int i=1;i<=num;i++){
                   printf("�������%d��Ԫ�أ�",i);
                   gets(word);
                   trie_insert(root,word);
                   printf("��%d��Ԫ��(%s)¼��ɹ���\n",i,word);
                }printf("ȫ��¼����ϣ�\n\n");
                break;
             }

     case 3: {
                printf("��������Ҫɾ����Ԫ�أ�");
                char word[26];
                gets(word);//gets��������ո�scanf����
                if (root==NULL){printf("����δ��ʼ��!\n");break;}
                printf("ɾǰһ�飺");
                int d=searchTrie(root,word);
                if(d==0) break;
                Trie_delect(root,word,0);
                printf("Ϊ����ѯ�����");
                searchTrie(root,word);
                break;
     }

     case 4: {
                char word[26];
                printf("��������Ҫ���ҵ�Ԫ�أ�");
                gets(word);
                searchTrie(root,word);
                printf("\n�������(~_~)\n\n");
                break;
             }
     case 0: printf("��ӭ�ٴ�ʹ�ó���\n");
             return ;

     default : printf("�����ڹ��ܣ���������\n\n");
                break;
    }
 }
}
void trie_insert(TrieTree root,char *word)
{
    TrieTreeNode temp;
    temp=root;
    int i=0;
    while(*(word+i)!='\0')
    {
        int ascii=*(word+i);
        if(temp->next[abs(ascii)]==NULL)
        {
            temp->next[abs(ascii)]=new TrieNode;
            temp->next[abs(ascii)]->word=*(word+i);
            temp->child_count++;
        }
        temp=temp->next[abs(ascii)];
        i++;
    }
    temp->if_end=TRUE;
}
int searchTrie(TrieTree root,char *word) {
    if(root==NULL) {
        printf("��Trie��δ��ʼ����\n");
        return 0 ;
    }
    TrieTree tmp=root;
    int i=0;
    while(word[i]!='\0') {
        int Ascll=abs(word[i]);
        if(tmp->next[Ascll]==NULL){printf("û�и�Ԫ��(����ɾ��)!\n");return 0 ;}
        else tmp=tmp->next[Ascll];
        i++;
    }
    if (tmp->if_end == TRUE){
        printf("���ڸ�Ԫ�أ�\n");
        return 1;
    }
    else {
        printf("�����ڸ�Ԫ�أ�(����ɾ��)\n");
        return 0;
    }
}
TrieTree Trie_delect(TrieTree root,char *word,int locate) {
    if(*(word+locate)!='\0') {
        TrieTree tmp;
        int Ascll=*(word+locate);
        tmp=root->next[abs(Ascll)];
        tmp=Trie_delect(tmp,word,locate+1);//�ݹ鵽Ԫ�����һ���ַ�
        /*�����ǿ�ʼ���ݺ���еĲ���*/
        if(tmp==NULL) {//NULL��ʾ�����Ҫ��ɾ��
            delete( root->next[abs(Ascll)]);
            root->next[abs(Ascll)]=NULL;//��ʾ����tmp����Ľ��(���ôεݹ����һ�����)��ɾ��
            if(root->child_count!=0) {
                root->child_count--;
            }//����ý��������Ԫ�ص��ӽڵ㣬��next����һ�ͺ�
            if(root->if_end==TRUE) {
                return root;
            }//����ý��������Ԫ�ص����һ���ַ��ڵ㣬ֱ�ӷ��طǿյ�ַ
            else if (root->if_end==FALSE&&root->child_count==0) {
                return NULL;
            }//��ɾ��㣬ֱ�ӷ���NULL
        }
        else {//���δ��ɾ��
            return root;
        }

    }
    else {//�����˱�ɾ��Ԫ�ص����һ���ַ����
        if(root->child_count==0) {//���Ǳ�ɾ��Ԫ�ص�ĩ��㣬�Һ����ӽڵ�
            root=NULL;
        }
        else {//��������Ԫ�ص��ӽڵ�
            root->if_end=FALSE;
        }
        return root;
    }
}

int main()
{
    interface();
    return 0;
}
