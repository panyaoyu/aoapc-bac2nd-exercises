#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
int m,n;
int main(){
//	freopen("data.out","w",stdout);
	int tmp1,tmp2;
	cin>>m;
	while(m--){
		int maxn = -10001;
		int minn = 10001;
		map<PII,int> Map;
		vector<PII> dots;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d%d",&tmp1,&tmp2);
			minn = min(tmp1,minn);
			maxn = max(tmp1,maxn);
			PII tmp = make_pair(2*tmp1,2*tmp2);
			Map[tmp] = 1;
			dots.push_back(tmp);
		}
		int axis = (maxn+minn);
		int flag = 0;
		for(int i=0;i<n;i++){
			if(Map.count(dots[i])){
				if(dots[i].first==axis)
					continue;
				PII tmp = make_pair(2*axis-dots[i].first,dots[i].second);
				if(Map.count(tmp)){
					Map.erase(dots[i]);
					Map.erase(tmp);
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
