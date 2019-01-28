#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
bool mysort(int a,int b){
	return a>b;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),mysort);
	int k=v.size();
	for(int i=0;i<v.size();i++){
		if(i+1>=v[i]){
			k=i;
			break;
		}
	}
	cout<<k<<endl;
	return 0;
}
