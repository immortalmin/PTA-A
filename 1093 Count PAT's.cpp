#include<iostream>
#include<string>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	int a[100010][2];
	string s;
	cin>>s;
	int k1,k2=1,k3;
	int sum1=0,sum2=0;
	long long int sum3=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A') a[k2++][0]=sum1;
		else if(s[i]=='P') sum1++;
	}
	k1=k2-1;
	k3=k1;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='A') a[k3--][1]=sum2;
		else if(s[i]=='T') sum2++;
	}
	for(int i=1;i<=k1;i++){
		sum3=sum3+(a[i][0]*a[i][1]);
	}
	cout<<sum3%1000000007<<endl;
	return 0;
}
