#include <stdio.h>
#include <stdlib.h>
char xx[2333333],yy[2333333],zz[2333333];
int main()
{

int nn,ii,J,K,mm,oo;

ii=strlen(xx);
J=strlen(yy);
for(K=0,mm=0;ii>0&&J>0;ii--,J--)
{
mm+=xx[ii-1]-'0'+yy[J-1]-'0';
zz[K++]=mm%10+'0';
mm/=10;
}
for(;ii>0;ii--)
{
mm+=xx[ii-1]-']0';
zz[K++]=mm%10+'0';
mm/=10;
}
for(;J>0;J--)
{
mm+=yy[J-1]-'0';
zz[K++]=mm%10+'0';
mm/=10;
}
if(mm>0)
zz[K++]=mm%10+'0';


    return 0;
}
