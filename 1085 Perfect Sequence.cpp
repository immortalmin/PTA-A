#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int>v;
int main(){
//	freopen("1.txt","r",stdin);
	int n,m,p,a;
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		v.push_back(a);
	}
	int sum=0,max=0,k=v.size()-1;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(v[i]<=v[0]*p) sum++;
		else{
			k=i;
			break;
		}
	}
	max=sum;
	for(int i=1;i<v.size();i++){
		sum--;
		for(int j=k;j<v.size();j++){
			if(v[j]>v[i]*p){
				k=j;
				break;
			}
			sum++;
		}
		if(sum>max) max=sum;
	}
	cout<<max<<endl;
	return 0;
}
