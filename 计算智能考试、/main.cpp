#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
int k;
typedef char  ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ��
}
BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)    // �㷨6.4
{
    // �������������������н���ֵ��һ���ַ�������#���ַ���ʾ������
    // ������������ʾ�Ķ�����T��
    char ch;
    scanf("%c",&ch);
    if (ch=='#') T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        T->data=ch; // ���ɸ����
        CreateBiTree(T->lchild);   // ����������
        CreateBiTree(T->rchild);  // ����������
    }
    return OK;
} // CreateBiTree
int solve(BiTree T,int counts)
{
    if(T==NULL) return 0;
    else if(counts==k)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
            return 1;
        else
            return 0;
    }
    return solve(T->lchild,counts+1)+solve(T->rchild,counts+1);
}
//ABC###D##
//2


int main()   //������
{
    BiTree T;
    CreateBiTree(T);
    cin>>k;
    cout<<solve(T,1);
}//main

