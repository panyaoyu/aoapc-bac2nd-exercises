#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int> PII;
int m,n;
int main(){
//	freopen("data.out","w",stdout);
	while(cin>>m&&m){
		map<PII,int> Map;
		int a,b;
		while(m--){
			scanf("%d%d",&a,&b);
			PII tmp1 = make_pair(a,b);
			PII tmp2 = make_pair(b,a);
			if(Map.count(tmp2)){
				if(Map[tmp2]==1)
					Map.erase(tmp2);
				else
					Map[tmp2]--;			
			}
			else if(Map.count(tmp1)){
				Map[tmp1]++;
			}
			else{
				Map[tmp1] = 1;
			}
		}
		if(Map.empty())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
