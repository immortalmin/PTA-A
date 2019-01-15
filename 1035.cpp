#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Info{
	string user;
	string pwd;
}info;
vector<Info>v;
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	string s1,s2;
	for(int z=0;z<n;z++){
		cin>>s1>>s2;
		int flag=0;
		for(int i=0;i<s2.size();i++){
			if(s2[i]=='1'||s2[i]=='0'||s2[i]=='l'||s2[i]=='O') flag=1;
			if(s2[i]=='1') s2[i]='@';
			if(s2[i]=='0') s2[i]='%';
			if(s2[i]=='l') s2[i]='L';
			if(s2[i]=='O') s2[i]='o';
		}
		if(flag==1){
			info.user=s1;
			info.pwd=s2;
			v.push_back(info);
		}
	}
	if(v.size()==0){
		if(n==1){
			cout<<"There is 1 account and no account is modified"<<endl;
		}else{
			cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		}
	}else{
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v[i].user<<" "<<v[i].pwd<<endl;
		}
	}
	return 0;
}
