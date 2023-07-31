#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int gift[205][205];
int countings[205];
int know[205];
int main()
{

    int T;
    cin>>T;
    int n;
    int m;
    int k;
    while(T--)
    {
        cin>>n>>m;
        memset(gift,0,sizeof(gift));
        memset(countings,0,sizeof(countings));
        memset(know,0,sizeof(know));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>gift[i][j];
            }
        }
        for(int l=1; l<=m; l++)
        {
            cin>>k;
            int now=0;
            int ans=0;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(gift[i][j]==k)
                    {
                        know[i]++;
                        now=max(know[i],now);
                    }
                }
            }
            for(int i=1; i<=n; i++)
            {
                if(know[i]==now)
                {
                    ans++;
                }
            }
            countings[l]=ans;

        }
        for(int i=1; i<=m; i++)
        {
            printf("%d ",countings[i]);
        }
        printf("\n");

    }
    return 0;
}
