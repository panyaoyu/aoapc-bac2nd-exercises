/*
This is the code i write,but presentation error and i don't know why.
If you want to be accepted,copy the code which is commented at the bottem of the file.
*/
#include<iostream>
#include<cctype>
using namespace std;
char p[5][5];
int x,y;
bool check(char c){
	switch (c){
		case 'A': return (x-1>=0);break;
		case 'B': return (x+1<=4);break;
		case 'L': return (y-1>=0);break;
		case 'R': return (y+1<=4);break;
	}
}
void swapspace(char c){
	int tmp;
	switch (c){
		case 'A': tmp=p[x][y];p[x][y]=p[x-1][y];p[x-1][y]=tmp;x--;break;
		case 'B': tmp=p[x][y];p[x][y]=p[x+1][y];p[x+1][y]=tmp;x++;break;
		case 'L': tmp=p[x][y];p[x][y]=p[x][y-1];p[x][y-1]=tmp;y--;break;
		case 'R': tmp=p[x][y];p[x][y]=p[x][y+1];p[x][y+1]=tmp;y++;break;
	}
}
int main(){
	freopen("data.out","w",stdout);
	char s[6];
	string ss;
	int n = 0;
	char c;
	int cnt = 1;
	int ff;
	while(true){
		int flag = 0;
		if(n<5){
			cin.getline(s,6);
			if(s[0]=='Z')
				exit(0);
//			cout<<endl;
			for(int i=0;i<5;i++){
				if(s[i]=='\n'){
					s[i] = ' ';
					x = n;
					y = i;
				}
				if(!(isalpha(s[i]))){
					x = n;
					y = i;
				}
				p[n][i]=s[i];
			}
		}	
		else{
			while(cin>>c&&c!='0'){
				if(check(c)){				
					swapspace(c);
				}
				else{
					flag = 1;
				}
			}
			getchar();
		}
		if(n==5){
			if(cnt!=1)
				cout<<endl;
			if(flag)
				cout<<"Puzzle #"<<cnt<<":"<<endl<<
							"This puzzle has no final configuration."<<endl;
			else{
				cout<<"Puzzle #"<<cnt<<":"<<endl;
				for(int ii=0;ii<5;ii++){
					for(int jj=0;jj<5;jj++){
//						if(jj!=4)	
							cout<<p[ii][jj]<<" ";
//						else
//							cout<<p[ii][jj];
					}
					cout<<endl;
				}
			}
			cnt++;
			n = -1;
		}
		n++;
	}
	return 0;
}
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//
//char puzzle[10][10];
//
//void printPuzzle()
//{
//    for (int i = 0; i < 5; ++i)
//    {
//        for (int j = 0; j < 4; ++j)
//            cout << puzzle[i][j] << ' ';
//        cout << puzzle[i][4] << endl;
//    }
//}
//
//int main()
//{
//	freopen("data1.out","w",stdout);
//    int kase = 0;
//    while (fgets(puzzle[0], 7, stdin)) //����7-1=6���ַ�����ÿ�е�5���ַ��ӻ���
//    {
//        if (puzzle[0][0] == 'Z') break;
//        for (int i = 1; i < 5; ++i)
//            fgets(puzzle[i], 7, stdin);
//        //cout << "Read Finished" << endl;
//        //printPuzzle(); //���Զ������
//        int ei = 0, ej = 0; //�ҳ��յ��Ǹ�����
//        for (int i = 0; i < 5; ++i)
//            for(int j = 0; j < 5; ++j)
//                if(puzzle[i][j] == ' ')
//                {
//                    ei = i, ej = j;
//                    break;
//                }
//        bool valid = true; //��־�Ƿ�ָ����ֹ�
//        char moves[101];
//        int cnt = 0;
//        char c;
//        while (cin >> c && c != '0') //���Ǹ��ж���
//            moves[cnt++] = c;
//        int ni = ei, nj = ej;
//        for (int i = 0; i<cnt; ++i)
//        {
//            switch(moves[i])
//            {
//                case 'A': ni = ei-1; nj = ej; break;
//                case 'B': ni = ei+1; nj = ej; break;
//                case 'L': nj = ej-1; ni = ei; break;
//                case 'R': nj = ej+1; ni = ei; break;
//                default: break;
//            }
//            //�Ƿ����:
//            if (ni < 0 || ni > 4 || nj < 0 || nj > 4)
//            {
//                valid = false;
//                break;
//            }
//            else
//            {
//                swap(puzzle[ei][ej], puzzle[ni][nj]);
//                ei = ni, ej = nj; //���¿ո�λ��
//            }
//        }
//        getchar(); //�ǳ���Ҫ���̵�ָ�������0����Ļس���
//        if (kase++) cout << endl; //���׸�����ǰ�������
//        cout << "Puzzle #" << kase << ":\n"; 
//        if (valid == false)
//            cout << "This puzzle has no final configuration." << endl;
//        else
//            printPuzzle();
//    }
//    return 0;
//}
