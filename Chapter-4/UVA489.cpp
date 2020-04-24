#include<iostream>
#include<cstring>
using namespace std;
int cnt[27];
int main(){
	int n;
	string s1,s2;
	while(cin>>n){
		if(n==-1)
			exit(0);
		memset(cnt,0,sizeof(cnt));
		cin>>s1>>s2;
		for(int i=0;i<s1.length();i++)
			cnt[s1[i]-'a']++;
		int res = 7;
		for(int i=0;i<s2.length();i++){
			if(cnt[s2[i]-'a'])
				cnt[s2[i]-'a'] = 0;
			else
				res--;
			if(!res)
				break;
		}
		cout<<"Round "<<n<<endl;
		int k = 0;
		for(;k<26;k++){
			if(cnt[k]&&res){
				cout<<"You chickened out."<<endl;
				break;
			}				
			if(cnt[k]&&!res){
				cout<<"You lose."<<endl;
				break;
			}

		}
		if(k==26)
			cout<<"You win."<<endl;
	} 
	return 0;
}
