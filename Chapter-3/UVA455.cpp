#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		int len = s.length();
		for(int i=1;i<=len;i++){
			if(len%i)
				continue;
			string substr = s.substr(0,i);
			int j;
			for(j=i;j<=len-1;j+=i){
				if(substr!=s.substr(j,i))
					break;
			}
			if(j>len-1){
				cout<<i<<endl;
				break;
			}
		} 
		if(n) cout << endl; 
	}
	return 0;
}
