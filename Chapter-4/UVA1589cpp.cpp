#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int xx,yy;
int n;
int state[11][11];
int gi;

struct qizi{
	char t;
	int x;
	int y;
	qizi(char tt,int xxx,int yyy):t(tt),x(xxx),y(yyy){}
};

vector<qizi> a;

bool check();
bool checkqizi(int x,int y);
bool judge(qizi q);

bool check(){
	if(a[gi].y==yy){
		int cnt = 0;
		for(int i=xx+1;i<a[gi].x;i++)
			if(state[i][yy])
				cnt++;
		if(!cnt)
			return false;
	}
	if(!checkqizi(xx+1,yy))
		return false;
	if(!checkqizi(xx-1,yy))
		return false;
	if(!checkqizi(xx,yy+1))
		return false;
	if(!checkqizi(xx,yy-1))
		return false;
	return true;
}
bool checkqizi(int x,int y){
	if(y>6||y<4||x<1||x>3){	
		return true;
	}
	int temp1 = xx;
	int temp2 = yy;
	xx = x;
	yy = y;
	int len = a.size();
	for(int i=0;i<len;i++){
		bool j = judge(a[i]);
		if(judge(a[i])){
			xx = temp1;
			yy = temp2;
			return true;
		}
	}	
	xx = temp1;
	yy = temp2;
	return false;	
}
bool judge(qizi q){
	if(q.y==yy&&q.x==xx)
		return false;
	switch(q.t){
		case 'G':
			if(q.y==yy){
				int cnt = 0;
				for(int i=xx+1;i<a[gi].x;i++)
					if(state[i][yy])
						cnt++;
				if(cnt==0)
					return true;
				else
					return false;
			}
			return false;
		case 'R':
			if(q.x==xx){
				int maxn = max(q.y,yy);
				int minn = min(q.y,yy);
				int cnt = 0;
				for(int i=minn+1;i<maxn;i++){
					if(state[xx][i]==1)
						cnt++;					
				}
				if(cnt==0)
					return true;
				return false;				
			}
			if(q.y==yy){
				int maxn = max(q.x,xx);
				int minn = min(q.x,xx);
				int cnt = 0;
				for(int i=minn+1;i<maxn;i++){
					if(state[i][yy]==1)
						cnt++;					
				}
				if(cnt==0)
					return true;
				return false;
			}
			return false;
		case 'C':
			if(q.x==xx){
				int maxn = max(q.y,yy);
				int minn = min(q.y,yy);
				int cnt = 0;
				for(int i=minn+1;i<maxn;i++){
					if(state[xx][i]==1)
						cnt++;					
				}
				if(cnt==1)
					return true;
				return false;
			}
			if(q.y==yy){
				int maxn = max(q.x,xx);
				int minn = min(q.x,xx);
				int cnt = 0;
				for(int i=minn+1;i<maxn;i++){
					if(state[i][yy]==1)
						cnt++;					
				}
				if(cnt==1)
					return true;
				return false;
			}
			return false;
		case 'H':
			if((abs(q.x-xx)==1&&abs(q.y-yy)==2)&&state[q.x][(q.y+yy)/2]==0){		
				return true;
			}
			if((abs(q.x-xx)==2&&abs(q.y-yy)==1)&&state[(q.x+xx)/2][q.y]==0){		
				return true;
			}					
			return false;
		default:
			break;
	}
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	while(cin>>n>>xx>>yy){
		if(xx==0&&yy==0&&n==0)
			exit(0);
		a.clear();
		memset(state,0,sizeof(state));
		char c;
		int x_,y_;
		for(int i=0;i<n;i++){
			cin>>c>>x_>>y_;
			a.push_back(qizi(c,x_,y_));
			state[x_][y_] = 1;
			if(c=='G')
				gi = i;
		}
		if(check())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
} 

/*
1.������(�������������ע�⵽)
2.һ��ʼ������ʱ��˧���ܶ��� 
3.Ҫע�������п��ܱ��Է������Ե� 
*/
