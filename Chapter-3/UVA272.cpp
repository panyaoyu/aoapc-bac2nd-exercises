#include<iostream>
using namespace std;
int main(){
	int flag = 1;
	char c;
	while((c = getchar())!=EOF){
		if(c=='"'){
			if(flag){
				cout<<"``";
				flag = !flag;
			}
			else{
				cout<<"''";
				flag = !flag;
			}
		}
		else
			cout<<c;
	}
	return 0;
} 
