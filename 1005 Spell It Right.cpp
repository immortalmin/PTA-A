#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>v;
int main(){
//	freopen("1.txt","r",stdin);
	string s;
	string eng[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	while(cin>>s){
		v.clear();
		int sum=0;
		for(int i=0;i<s.size();i++){
			int a=s[i]-48;
			sum+=a;
		}
		int b;
		char c;
		if(sum==0){
			cout<<"zero"<<endl;
			continue;
		}
		while(sum>0){
			b=sum%10;
			v.push_back(eng[b]);
			sum/=10;
		}
		for(int i=v.size()-1;i>=0;i--){
			if(i!=v.size()-1) cout<<" ";
			cout<<v[i];
		}
		cout<<endl;
	}
	return 0;
}
