#include<iostream>
#include<string>
using namespace std;
int conv(string s) {
	int sum=0,a;
	for(int i=0; i<s.size(); i++) {
		a=s[i]-48;
		sum=sum*10+a;
	}
	return sum;
}
int main() {
//	freopen("1.txt","r",stdin);
	int n;
	string s,s1,s2;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>s;
		s1=s.substr(0,s.size()/2);
		s2=s.substr(s.size()/2,s.size()/2);
		int a,b,c;
		if(conv(s1)*conv(s2)==0){
			cout<<"No"<<endl;
			continue;
		}
		if(conv(s)%(conv(s1)*conv(s2))==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
