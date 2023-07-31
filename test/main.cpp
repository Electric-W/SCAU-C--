#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

bool check(int a,int n)
{
    return a>=(2*n)&&a<=(7*n);
}
int main()
{
    int num[10]={6,2,5,5,4,5,6,3,7,6};
    int a;
    int n;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>n;
        if(!check(a,n))
        {
            cout<<-1<<endl;
            continue;
        }
        while(n)
        {
            for(int i=9;i>=0;i--)
            {
                if(check(a-num[i],n-1))
                {
                    cout<<i;
                    a-=num[i];
                    n--;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}//main
