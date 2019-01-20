#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v1,v2;
bool mysort(const int&a,const int&b){
	return a>b;
}
int main(){
//	freopen("1.txt","r",stdin);
	v1.clear();
	v2.clear();
	int n,m,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a;
		v2.push_back(a);
	}
	sort(v1.begin(),v1.end(),mysort);
	sort(v2.begin(),v2.end(),mysort);
	int i1=0,i2=0,sum=0;
	while(v1[i1]>0&&v2[i2]>0){
		sum=sum+v1[i1]*v2[i2];
		i1++;
		i2++;
	}
	i1=v1.size()-1,i2=v2.size()-1;
	while(v1[i1]<0&&v2[i2]<0){
		sum=sum+v1[i1]*v2[i2];
		i1--;
		i2--;
	}
	cout<<sum<<endl;
	return 0;
}
