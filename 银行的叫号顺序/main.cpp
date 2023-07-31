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
	int ret = 99999, realtime = 0;//ret 区分同时到达的同级客户，按照输入顺序输出（否则会倒过来）
	int time, lev;
	string name;
	int n;
	cin >> n;
	while(n--){
		cin >> time >> lev >> name;
//		here:
		while(1){
			if(time <= realtime){ //职员没空，都去排队
				q.push(make_pair(lev*100000 + ret, name));
				ret--;
				break;
			}
            //开始模拟
			if(!q.empty()){ //接待客户
				cout << q.top().second << '\n';
				q.pop();
			}
			realtime += 5;//接完客户或喝完咖啡
		}
//		goto here;
	}
	while(!q.empty()){ //时间不再流动，全部出队即可
		cout << q.top().second << '\n';
		q.pop();
	}
	return 0;
}
