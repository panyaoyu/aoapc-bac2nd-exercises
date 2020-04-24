#include<iostream>
#include<vector>
using namespace std;

vector<int> pile[30];
int n;
int o1,o2;
string s1,s2;
int posa,posb,ha,hb;

void clear_above(int pos,int h){
	for(int i=h+1;i<pile[pos].size();i++){
		int tmp = pile[pos][i];
		pile[tmp].push_back(tmp);
	}
	pile[pos].resize(h+1);
} 
void pile_onto(int posa,int ha,int posb){
	for(int i=ha;i<pile[posa].size();i++){
		pile[posb].push_back(pile[posa][i]);
	}
	pile[posa].resize(ha);
}
void find_pos(int obj1,int obj2){
	for(int i=0;i<n;i++)
		for(int j=0;j<pile[i].size();j++){
			if(pile[i][j]==obj1){
				posa = i;
				ha = j;
			}
			if(pile[i][j]==obj2){
				posb = i;
				hb = j;
			}
		}
}
void print(){
	for(int i=0;i<n;i++){
		cout<<i<<":";
		for(int j=0;j<pile[i].size();j++){
			cout<<" "<<pile[i][j];
		}
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		pile[i].push_back(i);
	}
	while(cin>>s1&&s1!="quit"&&cin>>o1>>s2>>o2){
		find_pos(o1,o2);
		if(posa==posb)
			continue;
		if(s2=="onto")
			clear_above(posb,hb);
		if(s1=="move")
			clear_above(posa,ha);
		pile_onto(posa,ha,posb);
//		print();
	}
	print();
	return 0;
} 
