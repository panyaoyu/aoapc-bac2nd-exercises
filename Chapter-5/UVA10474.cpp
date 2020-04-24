#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
int a[10000];
int main(){
//	freopen("data.out","w",stdout);
	int tmp;
	int tt = 1;
	while(cin>>m>>n){
		if(m==0)
			break;
		printf("CASE# %d:\n",tt++);
		for(int i=0;i<m;i++)
			cin>>a[i];
		sort(a,a+m);
		for(int i=0;i<n;i++){	
			cin>>tmp;
			int temp = lower_bound(a,a+m,tmp)-a;
			if(temp<m&&a[temp]==tmp)
				printf("%d found at %d\n",tmp,temp+1);
			else
				printf("%d not found\n",tmp);
		}
	}
	return 0;
} 
