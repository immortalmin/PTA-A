#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int>mm;
int main(){
//	freopen("1.txt","r",stdin);
	mm.clear();
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.size();i++){
		mm[s2[i]]=1;
	}
	string ss="";
	for(int i=0;i<s1.size();i++){
		if(mm[s1[i]]==1) continue;
		ss+=s1[i];
	}
	cout<<ss<<endl;
	return 0;
}
