
#include <iostream>
using namespace std;

int main() {
    long xb;
        long xc;
        long yc;
        int T;
        cin>>T;
        for(int i=0;i<T;i++)
        {
            cin>>xb>>xc>>yc;
            long S = xb*yc;
            int flag=0;
            cout<<"S="<<S<<endl;
            for(int x0=0;x0<=xb;x0++)
            {
                long temp=0;
                if(x0<=xc)
                {
                    temp = x0*x0*yc*2/xc;
                }
                else if(x0>xc&&x0<=xb)
                {
                    temp = (xb-x0)*(xb-x0)*yc*2/(xb-xc);
                }
                cout<<"x0="<<x0<<"temp="<<temp  <<endl;
                if(S==temp)
                {
                    cout<<"YES"<<endl;
                    flag=1;
                    break;
                }

            }
            if(!flag)
                cout<<"NO"<<endl;

        }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
