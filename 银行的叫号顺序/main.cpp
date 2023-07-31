#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
using namespace std;

typedef pair<int, string> man;//<lev, name>

priority_queue <man> q;
int main()
{
//	freopen("case.txt","r",stdin);
	int ret = 99999, realtime = 0;//ret ����ͬʱ�����ͬ���ͻ�����������˳�����������ᵹ������
	int time, lev;
	string name;
	int n;
	cin >> n;
	while(n--){
		cin >> time >> lev >> name;
//		here:
		while(1){
			if(time <= realtime){ //ְԱû�գ���ȥ�Ŷ�
				q.push(make_pair(lev*100000 + ret, name));
				ret--;
				break;
			}
            //��ʼģ��
			if(!q.empty()){ //�Ӵ��ͻ�
				cout << q.top().second << '\n';
				q.pop();
			}
			realtime += 5;//����ͻ�����꿧��
		}
//		goto here;
	}
	while(!q.empty()){ //ʱ�䲻��������ȫ�����Ӽ���
		cout << q.top().second << '\n';
		q.pop();
	}
	return 0;
}
