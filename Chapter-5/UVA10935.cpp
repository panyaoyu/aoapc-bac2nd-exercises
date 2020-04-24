#include<iostream>
#include<queue>
using namespace std;
int n;
int main(){
//	freopen("data.out","w",stdout);
	while(cin>>n&&n){
		queue<int> q;
		cout<<"Discarded cards:";
		if(n==1){
			cout<<endl<<"Remaining card: 1"<<endl;
		}
		else{		
			for(int i = 1;i<=n;i++)
				q.push(i);
			while(q.size()>2){
				cout<<" "<<q.front()<<",";
				q.pop();
				int tmp = q.front();
				q.pop();
				q.push(tmp);
			}
			cout<<" "<<q.front()<<endl;
			q.pop();
			printf("Remaining card: %d\n",q.front());
		}
	}
	return 0;
}
