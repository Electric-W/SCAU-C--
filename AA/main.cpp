#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nums[6];
    for(int i=0;i<6;i++){
        cin>>nums[i];
    }
    int ans=0;
    int sums=0;
    for(int i=0; i<6; i++)
    {
        for(int j=i;; j++)
        {
            if(nums[j]>nums[j+1]&&j!=5)
            {
                sums=0;
                            cout<<"sums=!!!"<<sums<<endl;
                break;
            }
            sums+=nums[j];
            ans=max(sums,ans);
            cout<<"sums="<<sums<<endl;
        }

        cout<<"ans="<<ans<<endl;
    }

}
