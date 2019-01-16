#include<iostream>
#include<string>
using namespace std;
string proc(string s){
	int k=1,a,b;
	char c=s[0],cc;
	string ss="",sss;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]) k++;
		else{
			ss+=c;
			sss="";
			c=k+48;
			ss+=c;
			c=s[i];
			k=1;
		}
	}
	ss+=c;
	sss="";
	c=k+48;
	ss+=c;
	return ss;
}
int main(){
//	freopen("1.txt","r",stdin);
	string s;
	int n;
	cin>>s>>n;
	for(int i=1;i<n;i++){
		s=proc(s);
	}
	cout<<s<<endl;
}
