#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>v,v2;
void mins(string s){
	string ss;
	for(int i=0;i<s.size();i++){
		ss=s.substr(i,s.size()-i);
		v.push_back(ss);
	}
}
int main(){
//	freopen("1.txt","r",stdin);
	string s[101],ss;
	int n,flag2=0;
	cin>>n;
	getline(cin,s[0]);
	getline(cin,s[0]);
	ss=s[0];
	for(int i=1;i<n;i++){
		getline(cin,s[i]);
		if(s[i].size()<ss.size()) ss=s[i];
	}
	mins(ss);
	for(int i=0;i<v.size();i++){
		int flag=0;
		for(int j=0;j<n;j++){
			int res=s[j].find(v[i]);
			if(res!=s[j].size()-v[i].size()){
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<v[i]<<endl;
			flag2=1;
			break;
		}
	}
	if(flag2==0) cout<<"nai"<<endl;
	return 0;
}
