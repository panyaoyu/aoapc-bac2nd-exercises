#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> > q;
set<ll> s;
int a[3] = {2,3,5};
int main(){
	q.push(1);
	s.insert(1);
	for(int i=1;;i++){
		ll tmp = q.top();
		q.pop();
		if(i==1500){
			cout<<"The 1500'th ugly number is "<<tmp<<"."<<endl;
			exit(0);
		}
		for(int j=0;j<3;j++){
			ll t = tmp*a[j];
			if(!s.count(t)){
				s.insert(t);
				q.push(t);
			}
		}
	}
	return 0;
}
