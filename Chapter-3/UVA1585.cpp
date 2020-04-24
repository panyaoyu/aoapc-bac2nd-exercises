#include<iostream>
using namespace std;
int main(){
	string s;
	int n;
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>s;
		int len = s.length();
		int flag = 0;
		int score = 0;
		for(int i=0;i<len;i++){
			if(s[i]=='X')
				flag = 0;
			else
				flag++;
			score += flag;
		}
		cout<<score<<endl;
	}
	return 0;
} 
