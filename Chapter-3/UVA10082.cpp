#include<iostream>
#include<string>
using namespace std;
int main(){
	string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	while((c = getchar())!=EOF){
		if(s.find(c)!=s.npos)
			cout<<s[s.find(c)-1];
		else
			cout<<c; 
	}
	return 0;
}
