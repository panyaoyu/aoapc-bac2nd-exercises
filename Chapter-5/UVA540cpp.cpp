#include<iostream>
#include<queue>
#include<map>
#define maxn 1010
using namespace std;
int n,m,tmp;
int main(){
	int i = 1;
//	freopen("data.out","w",stdout);
	while(cin>>n&&n){
		printf("Scenario #%d\n",i++);
		map<int,int> team;
		for(int i=0;i<n;i++){
			cin>>m;
			for(int j=1;j<=m;j++){
				cin>>tmp;
				team[tmp] = i;
			}
		}
		string op;
		queue<int> q,q2[maxn];
		while(cin>>op&&op[0]!='S'){
			if(op[0]=='E'){
				cin>>tmp;
				int t = team[tmp];
				if(q2[t].empty()){
					q.push(t);
				}
				q2[t].push(tmp);
			}
			else{
				int t = q.front();
				cout<<q2[t].front()<<endl;
				q2[t].pop();
				if(q2[t].empty())
					q.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}
