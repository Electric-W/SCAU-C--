#include <iostream>

using namespace std;
long long minn(long long a,long long b,long long c)
{
    long long t=min(a,b);
    return min(t,c);
}
int main()
{
    long long  T,n;
    long long  flag2=0,flag3=0,flag5=0;
    int i=1;
    long long ugly[3005]={1};
    while(i<=3000)
    {
        ugly[i]=minn(2*ugly[flag2],3*ugly[flag3],5*ugly[flag5]);
        if(ugly[i]==2*ugly[flag2])
            flag2++;
        if(ugly[i]==3*ugly[flag3])
            flag3++;
        if(ugly[i]==5*ugly[flag5])
            flag5++;
        i++;
    }
    cin>>T;
    while(T--)
    {
        cin>>n;
        int count_=0;
        int j=1;
        while(count_<n)
        {
            count_+=ugly[j+1]-ugly[j]-1;
            j++;
        }
        j--;
        count_-=ugly[j+1]-ugly[j]-1;
        cout<<ugly[j]+(n-count_)<<endl;
    }
    return 0;
}
