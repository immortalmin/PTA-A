#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main(){
//	freopen("1.txt","r",stdin);
	int n,b;
	while(cin>>n>>b){
		v.clear();
		int a,aa;
		while(n>0){
			a=n%b;
			v.push_back(a);
			n/=b;
		}
		int flag=0;
		for(int i=0;i<v.size();i++){
			if(v[i]!=v[v.size()-1-i]){
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(i!=0) cout<<" ";
			cout<<v[i];
		}
		cout<<endl;
	}
	return 0;
}
