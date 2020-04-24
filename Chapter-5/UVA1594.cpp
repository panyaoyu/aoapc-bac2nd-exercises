#include<iostream>
#include<vector>
#include<set>
using namespace std;
int m,n;
typedef set< vector<int> > Set;
Set setcache;
int main(){
//	freopen("data.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++){
		setcache.clear();
		vector<int> a;
		cin>>n;
		for(int j=0;j<n;j++){
			int tmp;
			cin>>tmp;
			a.push_back(tmp);
		}
		int flag = 0;
		for(int j=0;j<1001;j++){
			if(setcache.count(a)){
				cout<<"LOOP"<<endl;
				break;
			}	
			int flag = 0;
			for(int k=0;k<n;k++){
				if(a[k]){
					flag = 1;	
					break;		
				}
			}	
			if(!flag){
				cout<<"ZERO"<<endl;
				break;	
			}	
			setcache.insert(a);
			int tmp = a[0];
			for(int k=0;k<n;k++){
				a[k] = k!=n-1?abs(a[k+1]-a[k]):abs(a[k]-tmp);
			}
		}			
	}
	return 0;
}
