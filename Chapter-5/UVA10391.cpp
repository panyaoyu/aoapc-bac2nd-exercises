#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
map<string ,int> Map;
vector<string> dict;
set<string> res;
int main(){
	string s;
	while(cin>>s){
		dict.push_back(s); 
		Map[s] = 1;
	}
	int size = dict.size(); 
	for(int i=0;i<size;i++){
		int len = dict[i].length();
		for(int j=1;j<len-1;j++){
			if(Map.count(dict[i].substr(0,j))&&Map.count(dict[i].substr(j)))
				res.insert(dict[i]);
		}
	}
	for(set<string>::iterator it = res.begin();it!=res.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}
