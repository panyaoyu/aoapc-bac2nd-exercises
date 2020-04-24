#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
string s[110] ;
int n;
void print(const string &s,int maxlen,char c){
	cout<<s;
	int len = s.length();
	for(int i=len;i<maxlen;i++)
		cout<<c;
}
int main(){
//	freopen("data.out","w",stdout);
	while(cin>>n){
		print("",60,'-');
		cout<<endl;
		int maxlen = 0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			int len = s[i].length();
			maxlen = max(maxlen,len);
		}
		sort(s,s+n);
		int col = (60-maxlen)/(maxlen+2)+1;
		int row = (n-1)/col+1;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				int tmp = j*row+i;
				if(tmp<n)
					print(s[tmp],j!=col-1?maxlen+2:maxlen,' ');
			}
			cout<<endl;
		}
	}
	return 0;
} 
