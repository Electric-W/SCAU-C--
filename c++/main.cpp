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
                k1=(y1-y2)/(x1-x2);//ֱ��A->B��б��
                k2=(y3-y4)/(x3-x4);//ֱ��C->D��б��
                b1=y1-(k1*x1);//ֱ��A->B��b
                b2=y3-(k2*x3);//ֱ��C->D��b
                if(k1==k2)//�����ȣ���������ƽ�о����غ�
                {
                    if((x3*k1+b1)==y3)//���ֱ��C->D�ϵ���ֱ��A->B�ϱ�������ֱ���غ���
                        cout<<"NO"<<endl;
                    else//����ƽ��
                        cout<<"YES"<<endl;
                }
                if(k1!=k2)//���б�ʲ���ȣ�����б��һ������
                {
                    printf("NO");
                }
            }
            if(x1==x2||x3==x4)//��������ֱ�ߵ�б�ʶ������ڵ����
            {
                if(x1==x2&&x3==x4)//���ֱ��A->B��C->D����������������
                {
                    if(x1==x3)//����ĸ��㶼��ͬһ��ֱ����
                        cout<<"NO"<<endl;
                    else//�����ƽ��
                        cout<<"YES"<<endl;
                }
                if(x1==x2&&x3!=x4)//������������������һ��ֱ��б�ʲ����ڶ���һ��ֱ�ߴ���
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
