#include<iostream>
#include<cctype>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int len = s.length();
		double total = 0;
		double w;
		for(int j=0;j<len;j++){
				switch(s[j]){
					case 'C': w=12.01;break;
					case 'H': w=1.008;break;
					case 'O': w=16.0;break;
					case 'N': w=14.01;break;					
				}			
				if(isdigit(s[j+1])&&(!isdigit(s[j+2]))){
					total += w*(s[j+1]-'0');
					j++;
				}
				else if(isdigit(s[j+1])&&isdigit(s[j+2])){
					total += w*((s[j+1]-'0')*10+(s[j+2]-'0'));
					j+=2;
				}
				else
					total += w;
		}
		printf("%.3lf\n",total);
	}
	return 0;
} 
