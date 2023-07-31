#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
double x1,x2,x3,x4,y1,y2,y3,y4,k1,k2,b1,b2,x,y;
int main()
{

            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
            if(x1!=x2&&x3!=x4)
            {
                k1=(y1-y2)/(x1-x2);//直线A->B的斜率
                k2=(y3-y4)/(x3-x4);//直线C->D的斜率
                b1=y1-(k1*x1);//直线A->B的b
                b2=y3-(k2*x3);//直线C->D的b
                if(k1==k2)//如果相等，表明不是平行就是重合
                {
                    if((x3*k1+b1)==y3)//如果直线C->D上点在直线A->B上表明两条直线重合了
                        cout<<"NO"<<endl;
                    else//否则平行
                        cout<<"YES"<<endl;
                }
                if(k1!=k2)//如果斜率不相等，表明斜率一定存在
                {
                    printf("NO");
                }
            }
            if(x1==x2||x3==x4)//考虑两条直线的斜率都不存在的情况
            {
                if(x1==x2&&x3==x4)//如果直线A->B和C->D的两个点横坐标相等
                {
                    if(x1==x3)//如果四个点都在同一条直线上
                        cout<<"NO"<<endl;
                    else//否则就平行
                        cout<<"YES"<<endl;
                }
                if(x1==x2&&x3!=x4)//下面两种情况是如果有一条直线斜率不存在而另一条直线存在
                {
                    printf("NO");
                }
                if(x1!=x2&&x3==x4)
                {
                    printf("NO");
                }
            }



    return 0;
}
