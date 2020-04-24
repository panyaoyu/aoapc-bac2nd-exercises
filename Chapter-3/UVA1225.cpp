#include<iostream>
#include<cstring> 
using namespace std;
int main(){
	int number[10]={0};
	int n;
	int tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		memset(number,0,sizeof(number));
		for(int j=1;j<=tmp;j++){
			int temp = j;
			while(temp){
				number[temp%10]++;
				temp /= 10;
			}
		}
		for(int i=0;i<10;i++){
			if(i<9)
				cout<<number[i]<<" ";
			else
				cout<<number[i]<<endl;
		}
	}	
	return 0;
}
