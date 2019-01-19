#include<iostream>
#include<string>
using namespace std;
string doub(string s){
	string ss="";
	int a,b,k=0;
	char c;
	for(int i=s.size()-1;i>=0;i--){
		a=s[i]-48;
		b=(a*2+k)%10;
		k=(a*2+k)/10;
		c=b+48;
		ss=c+ss;
	}
	if(k!=0){
		c=k+48;
		ss=c+ss;
	}
	return ss;
}
int main(){
//	freopen("1.txt","r",stdin);
	string s,ss,s2;
	while(cin>>s){
		ss=doub(s),s2=doub(s);
		if(ss.size()>s.size()){
			cout<<"No"<<endl;
			cout<<s2<<endl;
			continue;
		}
		int flag=0,flag2=0;
		for(int i=0;i<s.size();i++){
			flag=0;
			for(int j=0;j<ss.size();j++){
				if(s[i]==ss[j]){
					s[i]=' ';
					ss[j]=' ';
					flag=1;
					break;
				}
			}
			if(flag==0){
				flag2=1;
				cout<<"No"<<endl;
				cout<<s2<<endl;
				break;
			}
		}
		if(flag2==0){
			cout<<"Yes"<<endl;
			cout<<s2<<endl;
		}
	}
	return 0;
}
