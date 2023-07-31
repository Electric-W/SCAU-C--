#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int dp[51][2001];
int losspow[51];
int gethappy[51];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>gethappy[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>losspow[i];
    }
    for(int i=1; i<=n; i++)
    {
        dp[i][0]=0;
    }
    for(int j=1; j<=2000; j++)
    {
        if(j>=losspow[n])
        {
            dp[n][j]=gethappy[n];
        }
        else
        {
            dp[n][j]=0;
        }
    }
    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; j<=2000; j++)
        {
            if(j<losspow[i])
            {
                dp[i][j]=dp[i+1][j];
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-losspow[i]]+gethappy[i]);
            }
        }
    }
    cout<<dp[1][2000]+1;
    return 0;
}
