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
     printf("\t\t\t\t\t||欢迎来到Trie树||\n");
     printf("\t\t\t\t\t===================\n");
     printf("\t\t\t\t\t||1.Trie树初始化  |\n ");
     printf("\t\t\t\t\t||2.插入元素      |\n ");
     printf("\t\t\t\t\t||3.删除元素      |\n ");
     printf("\t\t\t\t\t||4.查找元素      |\n");
     printf("\t\t\t\t\t||0.退出程序      |\n ");
     printf("\t\t\t\t\t===================\n");

     printf("请输入您的操作：");
     scanf("%d",&choice);
     while((getchar())!='\n');
     switch (choice)
     {
     case 1: {root = (TrieTreeNode)calloc(1, sizeof(TrieTreeNode));
               if (root==NULL) printf("初始化失败！\n");
               else printf("初始化成功！\n");
               break;}

     case 2: {
                printf("请输入要录入的元素个数：");
                int num;
                scanf("%d",&num);
                while((getchar())!='\n');//清空回车带来的干扰
                char word[26];//一个元素的最大长度事26
                for(int i=1;i<=num;i++){
                   printf("请输入第%d个元素：",i);
                   gets(word);
                   trie_insert(root,word);
                   printf("第%d个元素(%s)录入成功！\n",i,word);
                }printf("全部录入完毕！\n\n");
                break;
             }

     case 3: {
                printf("请输入你要删除的元素：");
                char word[26];
                gets(word);//gets可以输入空格，scanf不行
                if (root==NULL){printf("该树未初始化!\n");break;}
                printf("删前一查：");
                int d=searchTrie(root,word);
                if(d==0) break;
                Trie_delect(root,word,0);
                printf("为您查询结果：");
                searchTrie(root,word);
                break;
     }

     case 4: {
                char word[26];
                printf("请输入你要查找的元素：");
                gets(word);
                searchTrie(root,word);
                printf("\n查找完毕(~_~)\n\n");
                break;
             }
     case 0: printf("欢迎再次使用程序\n");
             return ;

     default : printf("不存在功能，请检查输入\n\n");
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
        printf("该Trie树未初始化！\n");
        return 0 ;
    }
    TrieTree tmp=root;
    int i=0;
    while(word[i]!='\0') {
        int Ascll=abs(word[i]);
        if(tmp->next[Ascll]==NULL){printf("没有该元素(或已删除)!\n");return 0 ;}
        else tmp=tmp->next[Ascll];
        i++;
    }
    if (tmp->if_end == TRUE){
        printf("存在该元素！\n");
        return 1;
    }
    else {
        printf("不存在该元素！(或已删除)\n");
        return 0;
    }
}
TrieTree Trie_delect(TrieTree root,char *word,int locate) {
    if(*(word+locate)!='\0') {
        TrieTree tmp;
        int Ascll=*(word+locate);
        tmp=root->next[abs(Ascll)];
        tmp=Trie_delect(tmp,word,locate+1);//递归到元素最后一个字符
        /*下面是开始回溯后进行的操作*/
        if(tmp==NULL) {//NULL表示结点需要被删除
            delete( root->next[abs(Ascll)]);
            root->next[abs(Ascll)]=NULL;//表示的是tmp代表的结点(即该次递归的下一个结点)被删除
            if(root->child_count!=0) {
                root->child_count--;
            }//如果该结点是其它元素的子节点，子next数减一就好
            if(root->if_end==TRUE) {
                return root;
            }//如果该结点是其它元素的最后一个字符节点，直接返回非空地址
            else if (root->if_end==FALSE&&root->child_count==0) {
                return NULL;
            }//可删结点，直接返回NULL
        }
        else {//结点未被删除
            return root;
        }

    }
    else {//到达了被删除元素的最后一个字符结点
        if(root->child_count==0) {//这是被删除元素的末结点，且后无子节点
            root=NULL;
        }
        else {//这是其它元素的子节点
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
