#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int m,n,pos,tmp;
int main(){
//	freopen("data.out","w",stdout);
	cin>>m;
	while(m--){
		queue<int> q;
		priority_queue<int> pq;
		cin>>n>>pos;
		for(int i=0;i<n;i++){
			cin>>tmp;
			q.push(tmp);
			pq.push(tmp);
		}
		int time = 0;
		int cur = 0;
		for(;;){
			while(q.front()!=pq.top()){
				int f = q.front();
				q.pop();
				q.push(f);
				pos = pos==0?q.size()-1:pos-1;
			}
			if(!pos){
				cout<<n-q.size()+1<<endl;
				break;
			}
			q.pop();
			pq.pop();
			pos--;
		}
	}
	return 0;
}
