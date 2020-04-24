#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int H[15][15];
int V[15][15];
int m,n;
int cnt[15];
bool check(int ii,int jj,int kk){
	for(int i=0;i<kk;i++){
		if(!V[ii+i][jj]||!V[ii+i][jj+kk])
			return false;
		if(!H[ii][jj+i]||!H[ii+kk][jj+i])
			return false;
	}
	cout<<" ("<<i<<","<<j<<")";return true;
}
int main(){
//	freopen("data.out","w",stdout);
	char c;
	int tmp1,tmp2;
	int number = 1;
	while(cin>>n>>m){
		memset(cnt,0,sizeof(cnt));
		memset(H,0,sizeof(H));
		memset(V,0,sizeof(V));
		for(int i=0;i<m;i++){
			cin>>c>>tmp1>>tmp2;
			if(c=='H'){
				H[tmp1][tmp2] = 1;
			}
			else{
				V[tmp2][tmp1] = 1;
			}		
		}
		for(int i=1;i<=n-1;i++)
			for(int j=1;j<=n-1;j++){
				int minn = n-max(i,j);
				for(int k=1;k<=minn;k++){
					if(check(i,j,k))
						cnt[k]++;
				}	
			}	
		if(number!=1)
			cout<<endl<<"**********************************"<<endl<<endl;
		cout<<"Problem #"<<number<<endl<<endl;
		int flag = 0;
		for(int i=1;i<=n;i++){
			if(cnt[i]){	
				flag = 1;	
				cout<<cnt[i]<<" square (s) of size "<<i<<endl; 
			}
		}
		if(!flag)
			cout<<"No completed squares can be found."<<endl;
		number++;
	}
	return 0;
}
