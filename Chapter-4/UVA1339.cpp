#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s1[105];
char s2[105];
int cnt1[27];
int cnt2[27];
int main(){
	while(scanf("%s",s1)!=EOF){
		scanf("%s",s2);
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
			cnt1[s1[i]-'A']++;
			cnt2[s2[i]-'A']++;
		}
		sort(cnt1,cnt1+26);
		sort(cnt2,cnt2+26);
		int i=0;
		for(;i<26;i++){
			if(cnt1[i]!=cnt2[i])
				break;
		} 
		if(i==26)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}	
}
