#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int aa[100];
int sum(string s){
	int sum=0,a;
	for(int i=0;i<s.size();i++){
		a=s[i]-48;
		sum+=a;
	}
	return sum;
}
vector<int>v;
int main(){
//	freopen("1.txt","r",stdin);
	memset(aa,0,sizeof(aa));
	int n,m;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		m=sum(s);
		if(aa[m]==0){
			aa[m]=1;
			v.push_back(m);
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		if(i!=0) cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}
