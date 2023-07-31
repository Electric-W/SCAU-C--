#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

void work()
{
    int a,i,j;
    scanf("%d",&a);
    for(i=5000;i>a;i--)
    {
        j=sqrt((i*i)-(a*a));
        if((i*i)==((a*a)+(j*j)))
            printf("%d,%d\n",i,j);
    }
    for(i=a-1;i>0;i--)
    {
        j=sqrt((a*a)-(i*i));
        if((a*a)==((i*i)+(j*j))&&i>j)
            printf("%d,%d\n",i,j);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        work();
        if(n)
           printf("\n");
    }
    return 0;
}
