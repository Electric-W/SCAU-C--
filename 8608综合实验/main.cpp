#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
typedef struct tree_node
{
    int data;
    struct tree_node *lchild;
    struct tree_node *rchild;
} tree,*binar_tree;
//递归插入节点
void Insert_node(binar_tree &T,int e)
{
    if(!T)
    {
        T = new tree;
        T->data=e;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    else if(e>T->data)
        Insert_node(T->rchild,e);
    else
        Insert_node(T->lchild,e);
}
//初始化二叉树
void Create(binar_tree &T,int n)
{
    int e,i;
    T=NULL;
    for(i=1; i<=n; i++)
    {
        cin>>e;
        Insert_node(T,e);
    }
}
//线序遍历
void PreOrderTraverse(binar_tree &T)
{
    if(T)
    {
        cout<<T->data<<' ';
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//中序遍历
void InOrderTraverse(binar_tree &T)
{
    if(T)
    {

        InOrderTraverse(T->lchild);
        cout<<T->data<<' ';
        InOrderTraverse(T->rchild);
    }
}
//后序遍历
void LastOrderTraverse(binar_tree &T)
{
    if(T)
    {
        LastOrderTraverse(T->lchild);
        LastOrderTraverse(T->rchild);
        cout<<T->data<<' ';
    }
}
//非递归中序遍历
void InOrderTraverse_without_recursion(binar_tree &T)//·ÇµÝ¹é
{
    if(!T) return;
    stack <binar_tree> s;//采用栈的数据结构
    binar_tree q;
    q=T;
    while(!s.empty()||q)
    {
        while(q)
        {
            s.push(q);
            q=q->lchild;
        }
        if(!s.empty())
        {
            q=s.top();
            s.pop();
            cout<<q->data<<' ';
            q=q->rchild;
        }
    }
}
//层序遍历
void levelOrder(binar_tree &T)
{
    binar_tree Q[1000];
    int f=0,r=0;
    if(T)
        Q[r++]=T;
    while(f!=r)
    {
        binar_tree temp=Q[f++];
        cout<<temp->data<<' ';
        if(temp->lchild)
            Q[r++]=temp->lchild;
        if(temp->rchild)
            Q[r++]=temp->rchild;
    }
}
//递归查找
int flag=0;
void search_data(binar_tree &T,int key)
{
    if(!T)
    {
        flag=0;
        return;
    }
    if(T->data==key)
    {
        flag=1;
        return;
    }
    else if(key<T->data)
        search_data(T->lchild,key);
    else
        search_data(T->rchild,key);
}
//左右子树交换
void exchange_l_r_child(binar_tree &T)
{
    if(!T)
        return;
    swap(T->lchild,T->rchild);
    exchange_l_r_child(T->lchild);
    exchange_l_r_child(T->rchild);
}
//叶子节点数目统计
int getnum(binar_tree &T)
{
    if(!T)
        return 0;
    if(!T->lchild&&!T->rchild)
        return 1;
    return getnum(T->lchild)+getnum(T->rchild);
}
//树的深度
int gethigh(binar_tree &T)
{
    if(!T) return 0;
    return max(gethigh(T->lchild),gethigh(T->rchild))+1;
}

int main()
{
    int n;
    binar_tree T;
    cin>>n;
    Create(T,n);
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    cout<<endl;
    LastOrderTraverse(T);
    cout<<endl;

    int key1,key2;
    cin>>key1>>key2;
    search_data(T,key1);
    cout<<flag<<endl;
    flag=0;
    search_data(T,key2);
    cout<<flag<<endl;

    int e;
    cin>>e;
    Insert_node(T,e);
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    cout<<endl;
    LastOrderTraverse(T);
    cout<<endl;
    InOrderTraverse_without_recursion(T);
    cout<<endl;
    levelOrder(T);
    cout<<endl;
    exchange_l_r_child(T);
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    cout<<endl;
    LastOrderTraverse(T);
    cout<<endl;
    exchange_l_r_child(T);
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    cout<<endl;
    LastOrderTraverse(T);
    cout<<endl;
    cout<<gethigh(T)<<endl;
    cout<<getnum(T)<<endl;
}//main
