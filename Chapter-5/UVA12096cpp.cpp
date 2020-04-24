#include<iostream>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
typedef set<int> Set;
int n,m;
stack<int> s;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x){
	if(IDcache.count(x))
		return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = IDcache[x] = Setcache.size()-1;
}

int main(){
	cin>>n;
	string op;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>op;
			if(op[0]=='P')
				s.push(ID(Set()));
			else if(op[0]=='D')
				s.push(s.top());
			else{
				Set x1 = Setcache[s.top()];s.pop();
				Set x2 = Setcache[s.top()];s.pop();
				Set x;
				if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='A'){
					x = x2;
					x.insert(ID(x1));
				}
				s.push(ID(x));
			} 
			cout<<Setcache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl; 
	}
	return 0;
} 
