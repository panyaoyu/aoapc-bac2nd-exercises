#include<iostream>
#include<cstring>
using namespace std;

char color;
char board[10][10];
int n;
char s;
int cnt;
int cnt_b;
int cnt_w;

void printboard();
void solve();
void mov(int x,int y);
bool check(int i,int j);

void printboard(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++)
			cout<<board[i][j];
		cout<<endl;
	}		
}

void solve(){
	int ff = 0;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(board[i][j]=='-'){
				if(check(i,j)){
					cout<<(ff?" (":"(")<<i<<","<<j<<")";
					if(!ff){
						ff = 1;
					}
				}
			}
		}
	}
	if(!ff){
		cout<<"No legal move.";
		color = (color=='W'?'B':'W');
	}
	cout<<endl;
}

void mov(int i,int j){
	int temp1,temp2,flag;
	temp1 = i;
	temp2 = j;
	while(temp1--){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp1!=i){
				temp1++;
				board[temp1][temp2] = color;
			}
			break;			
		}
		
	}
	temp1 = i;
	temp2 = j;
	while(temp1++){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp1!=i){
				temp1--;
				board[temp1][temp2] = color;
			}
			break;			
		}
	}
	temp1 = i;
	temp2 = j;
	while(temp2++){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp2!=j){
				temp2--;
				board[temp1][temp2] = color;
			}	
			break;		
		}
	}
	temp1 = i;
	temp2 = j;
	while(temp2--){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp2!=j){
				temp2++;
				board[temp1][temp2] = color;
			}
			break;			
		}
	}
	temp1 = i;
	temp2 = j;
	for(;;){
		temp1++;temp2++;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp1!=i&&temp2!=j){
				temp1--;temp2--;
				board[temp1][temp2] = color;
			}
			break;			
		}
	}
	temp1 = i;
	temp2 = j;
	for(;;){
		temp1++;temp2--;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp1!=i&&temp2!=j){
				temp1--;temp2++;
				board[temp1][temp2] = color;
			}
			break;			
		}
	}
	temp1 = i;
	temp2 = j;
	for(;;){
		temp1--;temp2++;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp1!=i&&temp2!=j){
				temp1++;temp2--;
				board[temp1][temp2] = color;
			}
			break;			
		}
	}
	temp1 = i;
	temp2 = j;	
	for(;;){
		temp1--;temp2--;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			while(temp1!=i&&temp2!=j){
				temp1++;temp2++;
				board[temp1][temp2] = color;
			}
			break;			
		}
	}			
	cnt_b = 0; cnt_w = 0;
	for(int ii=1;ii<=8;ii++)
		for(int jj=1;jj<=8;jj++){
			if(board[ii][jj]=='W')
				cnt_w++;
			if(board[ii][jj]=='B')
				cnt_b++;
		}
	printf("Black - %2d White - %2d\n",cnt_b,cnt_w);
	color = (color=='W'?'B':'W');
}

bool check(int i,int j){
	int temp1,temp2,flag;
	temp1 = i;
	temp2 = j;
	flag = 0;
	while(temp1--){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	while(temp1++){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	while(temp2--){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	while(temp2++&&temp2<=8){
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	for(;;){
		temp1++;temp2++;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	for(;;){
		temp1--;temp2++;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	for(;;){
		temp1++;temp2--;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	temp1 = i;
	temp2 = j;
	flag = 0;
	for(;;){
		temp1--;temp2--;
		if(temp1<1||temp1>8||temp2<1||temp2>8||board[temp1][temp2]=='-')
			break;
		if(board[temp1][temp2]==color){
			if(flag)
				return true;
			else
				break;
		}
		else
			flag = 1;
	}
	return false;	
}
int main(){
//	freopen("data.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cnt = 0;
		int cnt_b = 0;
		int cnt_w = 0;
		memset(board,0,sizeof(board));
		for(int j=1;j<=8;j++)
			for(int k=1;k<=8;k++)
				cin>>board[j][k];
		while(cin>>s){
			if(s=='Q'){
				printboard();
				break;
			}
			switch(s){
				case 'B':
				case 'W':
					color = s;
					break;
				case 'L':
					solve();
					break;
				case 'M':
					char s1,s2;
					cin>>s1>>s2;
					mov(s1-'0',s2-'0');
					break;
				default:
					break;
			}
		}
		if(i!=n-1)
		cout<<endl;
	}
	return 0;
}
