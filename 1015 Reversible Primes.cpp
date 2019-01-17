#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
bool prime[1000000];
int conv(int n,int m){
	string s="";
	int a,b;
	char c;
	while(n>0){
		a=n%m;
		c=a+48;
		s+=c;
		n/=m;
	}
	int k=0,sum=0;
	for(int i=s.size()-1;i>=0;i--){
		a=s[i]-48;
		sum+=pow(m,k)*a;
		k++;
	}
	return sum;
}
int main(){
//	freopen("1.txt","r",stdin);
	for(int i=1;i<1000000;i+=2) prime[i]=true;
	prime[1]=false;
	for(int i=2;i<1000000;i+=2) prime[i]=false;
	prime[2]=true;
	for(int i=3;i<sqrt(1000000);i++){
		if(prime[i]){
			for(int j=i+i;j<1000000;j+=i) prime[j]=false;
		}
	}
	int n,m;
	while(cin>>n){
		if(n<0) break;
		cin>>m;
		if(prime[n]&&prime[conv(n,m)]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
