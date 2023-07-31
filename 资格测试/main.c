#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
char N[100][23333];char xx[100][23333];char yy[100][23333];
void revolve(char A[][23333])
{
    int i,j[100];
    char temp;

    for(i=0;i<100;i++)
    {
        j[i]=strlen(N[i]);
        for(int k=0;k<j[i]/2;k++)
        {
            temp=A[i][k];
            A[i][k]=A[i][j[i]-k-1];
            A[i][j[i]-k-1]=temp;
        }
    }
}
int main()
{
    char ch2[23333];
    char len[100];
    int k=0,j=0;
    gets(ch2);
    int len_ch2;
    len_ch2=strlen(ch2);
    for(int i=0; i<len_ch2; i++)
    {
        if(ch2[i]!=' ')
        {
            N[k][j++]=ch2[i];
        }
        else
        {
            k++;
            j=0;
        }
    }
    int i,M[100];
    char temp;

    for(i=0;i<100;i++)
    {
        M[i]=strlen(N[i]);
        for(int k=0;k<M[i]/2;k++)
        {
            temp=N[i][k];
            N[i][k]=N[i][M[i]-k-1];
            N[i][M[i]-k-1]=temp;
        }
    }
    int nn,ii,J,K,mm,oo;
for(int l=0;l<=(k/2);l++)
{
    strcpy(xx,N[l]);
    strcpy(yy,N[k-l-1]);
printf("xx[%d]=%s\n",l,xx);
        printf("yy[%d]=%s\n",l,yy);
    ii=strlen(xx);
    J=strlen(yy);
    for(K=0,mm=0; ii>0&&J>0; ii--,J--)
    {
        mm+=xx[ii-1]-'0'+yy[J-1]-'0';
        zz[K++]=mm%10+'0';
        mm/=10;
    }
    for(; ii>0; ii--)

    {
        mm+=xx[ii-1]-']0';
        zz[K++]=mm%10+'0';
        mm/=10;
    }
    for(; J>0; J--)
    {
        mm+=yy[J-1]-'0';
        zz[K++]=mm%10+'0';
        mm/=10;
    }
    if(mm>0)
        zz[K++]=mm%10+'0';

memset(xx,'\0',sizeof(xx));
memset(yy,'\0',sizeof(yy));
}
    for(int i=0; i<=k; i++)
    {
        printf("N[%d]=%s\n",i,N[i]);
    }
    return 0;
}
