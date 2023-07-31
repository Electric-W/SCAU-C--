#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int gethappy[51];
int losspow[51];
int dp[51][2001];
int main()
{
    long long x,y,z,k;
    while(cin>>k&&k)
    {
        for(z=k+1; z<=3*k; z++)
        {
            y=k*z/(z-k);
            if((k*z)%(z-k)==0&&y>=z)
                printf("1/%lld=1/%lld+1/%lld\n",k,y,z);
            long long p=k*z/(z-k);
            for(y=p+1; y<=2*p+1; y++)
            {
                x=k*y*z/(y*z-k*z-k*y);
                if((k*y*z)%(y*z-k*z-k*y)==0&&x>=y&&y>=z)
                    printf("1/%lld=1/%lld+1/%lld+1/%lld\n",k,x,y,z);
            }
        }
        printf("\n");
    }

    return 0;
}
