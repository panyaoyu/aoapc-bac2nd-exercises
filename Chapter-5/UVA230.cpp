#include<iostream>
#include<set>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct book{
	string title;
	string author;
	book(string s1,string s2):title(s1),author(s2){}
	bool operator < (const book& b){
		return author<b.author||(author==b.author&&title<b.title);
	}
};
map<string,int> Map;
set<int> books,ret;
vector<book> library; 
int main(){
//	freopen("data.out","w",stdout);
	string s;
	while(getline(cin,s)&&s[0]!='E'){
		int p = s.find("by");
		string title = s.substr(1,p-3);
		string author = s.substr(p+3);
		library.push_back(book(title,author));
	}
	sort(library.begin(),library.end());
	int len = library.size();
	for(int i=0;i<len;i++){
		Map[library[i].title] = i;
		books.insert(i);
	}
	while(getline(cin,s)&&s[0]!='E'){
		if(s[0]=='S'){		
			for(int it1 : ret){
				set<int>::iterator it2 = books.find(it1);
				if(it2 == books.begin()){
					printf("Put \"%s\" first\n",library[it1].title.c_str());
				}
				else{
					printf("Put \"%s\" after \"%s\"\n",library[it1].title.c_str(),library[*--it2].title.c_str());
				}
			}
			cout<<"END"<<endl;
			ret.clear();
		}
		else{
			string title = s.substr(8, s.size()-8-1);
			if(s[0]=='B')
				books.erase(Map[title]);
			else{
				books.insert(Map[title]);
				ret.insert(Map[title]);
			}
		}
	}
	return 0;
}
