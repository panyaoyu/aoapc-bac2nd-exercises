#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int> PII;
int a[10005][15];
int row,col;
int cnt;
map<string, int> id;

int ID(const string& s){
	if(!id.count(s))
		id[s] = ++cnt;
	return id[s];
}

void find(){
	for(int i=0;i<col;i++)
		for(int j=i+1;j<col;j++){
			map<PII,int> d;
			for(int k=0;k<row;k++){			
				PII p = make_pair(a[k][i], a[k][j]);
				if(d.count(p)){
					printf("NO\n");
					printf("%d %d\n",d[p]+1,k+1);
					printf("%d %d\n",i+1,j+1);
					return;
				}
			d[p] = k;
			}
		}
	printf("YES\n");
	return;
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	string s;
	char c;
	while(cin>>row>>col){
		getchar();
		cnt = 0;
		id.clear();
		for(int i=0;i<row;i++){
			getline(cin,s);
			int lastpos = -1;
			for(int j=0;j<col;j++){
				int pos = s.find(',',lastpos+1);
				if(pos == string::npos)
					pos = s.length();
				a[i][j] = ID(s.substr(lastpos+1,pos-lastpos-1));
				lastpos = pos;
			}
		}
		find();		
	}
	return 0;
} 
