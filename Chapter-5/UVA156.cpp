#include<iostream>
#include<map>
#include<cctype>
#include<algorithm>
#include<vector> 
using namespace std;
string s;
map<string,int> dict;
vector<string> tmp;
vector<string> ans;
string repr(const string& s){
	string res = s;
	int len = res.length();
	for(int i=0;i<len;i++){
		res[i] = tolower(res[i]);
	}
	sort(res.begin(),res.end());
	return res;
}
int main(){
	while(cin>>s){
		if(s=="#")
			break;
		tmp.push_back(s);
		if(!dict[repr(s)])
			dict[repr(s)] = 0;
		dict[repr(s)]++;
	}
	for(int i=0;i<tmp.size();i++){
		if(dict[repr(tmp[i])]==1)
			ans.push_back(tmp[i]);
	}
	sort(ans.begin(),ans.end());
	for(vector<string>::iterator it=ans.begin();it<ans.end();it++)
		cout<<*it<<endl;
	return 0; 
} 
