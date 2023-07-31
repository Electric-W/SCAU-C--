#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ugly(int x)
{
    if(x<7)
    {
        return x;
    }
    int in_2=0,in_3=0,in_5=0;
    int t2=0,t3=0,t5=0;
    vector<int> dp(x);
    dp[0]=1;
    for(int i=1;i<x;i++)
    {
        t2=dp[in_2]*2;
        t3=dp[in_3]*3;
        t5=dp[in_5]*5;
        dp[i]=min(t2,min(t3,t5));
        if(dp[i]==t2) in_2++;
        if(dp[i]==t3) in_3++;
        if(dp[i]==t5) in_5++;
    }
    return dp[x-1];
}
int main()
{
    int T;
    cin>>T;
    int n;
    while(T--)
    {
        cin>>n;
        cout<<ugly(n)<<endl;
    }
    return 0;
}
