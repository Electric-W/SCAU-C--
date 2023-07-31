#include<stdio.h>
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
struct point
{
    int x;
    int y;
    int step;
};
queue<point> r;
int a[100][100],v[100][100];
int main()
{
 int n,m,start_x,start_y,p,q;
 scanf("%d%d",&n,&m);
 for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
 scanf("%d",&a[i][j]);
 scanf("%d%d%d%d",&start_x,&start_y,&p,&q);
    //BFS
    point start;
    start.x=start_x;
    start.y=start_y;
    start.step=0;
}
