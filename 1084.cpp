#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
vector<char>v;
map<char,int>mm;
int main(){
//	freopen("1.txt","r",stdin);
	v.clear();
	mm.clear();
	string s1,s2;
	cin>>s1>>s2;
	char c;
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='a'&&s2[i]<='z') c=s2[i]-32;
		else c=s2[i];
		mm[c]=1;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='a'&&s1[i]<='z') c=s1[i]-32;
		else c=s1[i];
		if(mm[c]==0){
			v.push_back(c);
			mm[c]=2;
		}
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}
