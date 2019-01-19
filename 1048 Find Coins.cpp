#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main(){
//	freopen("1.txt","r",stdin);
	int n,m,a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int l=0,r=v.size()-1,flag=0;;
	while(l<r){
		if(v[l]+v[r]==m){
			cout<<v[l]<<" "<<v[r]<<endl;
			flag=1;
			break;
		}
		if(v[l]+v[r]<m) l++;
		else if(v[l]+v[r]>m) r--;
	}
	if(flag==0) cout<<"No Solution"<<endl;
	return 0;
}
