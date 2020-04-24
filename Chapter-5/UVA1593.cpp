#include<iostream>
#include<sstream>
#include<algorithm>
//#include<vector>
//#include<string>
using namespace std;
vector<string> a[1005];
int maxn = 0;
int maxlen[200]={0};
int cnt;
void print(const string&s,int maxlen){
	cout<<s;
	int n = maxlen-s.length()+1;
	cout<<string(n,' ');
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	string s;
	string tmp;
	int lines = 0;
	while(getline(cin,s)){
		stringstream ss(s);
		cnt = 0;
		while(ss>>tmp){
			int len = tmp.length();
			maxlen[cnt] = max(maxlen[cnt],len);
			cnt++;
			a[lines].push_back(tmp);
		}
		lines++;
	}
	for(int i=0;i<lines;i++){
		int size = a[i].size();
		for(int j=0;j<size;j++){
			if(j!=size-1)
				print(a[i][j],maxlen[j]);
			else
				cout<<a[i][j]<<endl;
		}
	}
	return 0;
} 
