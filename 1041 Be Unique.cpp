#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int judge[100010];
vector<int>v;
int main(){
//	freopen("1.txt","r",stdin);
	int n,a;
	cin>>n;
	memset(judge,0,sizeof(judge));
	for(int i=0;i<n;i++){
		cin>>a;
		if(judge[a]==0){
			v.push_back(a);
			judge[a]=1;
		}else{
			judge[a]=2;
		}
	}
	int flag=0;
	for(int i=0;i<v.size();i++){
		if(judge[v[i]]==1){
			cout<<v[i]<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0) cout<<"None"<<endl;
	return 0;
}
