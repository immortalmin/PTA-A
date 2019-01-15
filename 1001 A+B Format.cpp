#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string zhuan(int n){
	if(n==0) return "0";
	string s="";
	int a;
	char c;
	while(n>0){
		a=n%10;
		c=a+48;
		s=c+s;
		n/=10;
	}
	return s;
}
string add(string s){
	string ss="";
	int k=0;
	for(int i=s.size()-1;i>0;i--){
		ss=s[i]+ss;
		if(++k==3){
			ss=','+ss;
			k=0;
		}
	}
	ss=s[0]+ss; 
	return ss;
}
int main(){
//	freopen("1.txt","r",stdin);
	int a,b;
	while(cin>>a>>b){
		int flag=1;
		int c=a+b;
		if(c<0){
			flag=-1;
			c=-c;
		}
		string s=add(zhuan(c));
		if(flag==-1) s='-'+s;
		cout<<s<<endl;
	}
	return 0;
}
