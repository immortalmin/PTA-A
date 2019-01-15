#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
struct Info{
	double aa;//指数
	double bb;//系数 
}info;
vector<Info>v;
map<double,int>mm;
bool mysort(const Info&a,const Info&b){
	return a.aa>b.aa;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	while(cin>>n){
		mm.clear();
		v.clear();
		double a,b;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			if(mm[a]==0){
				info.aa=a;
				info.bb=b;
				v.push_back(info);
				mm[a]=v.size();
			}else{
				v[mm[a]-1].bb+=b;
			}
		}
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			if(mm[a]==0){
				info.aa=a;
				info.bb=b;
				v.push_back(info);
				mm[a]=v.size();
			}else{
				v[mm[a]-1].bb+=b;
			}
		}
		sort(v.begin(),v.end(),mysort);
		int sum=0;
		for(int i=0;i<v.size();i++){
			if(v[i].bb!=0.0) sum++;
		}
		cout<<sum;
		for(int i=0;i<v.size();i++){
			if(v[i].bb==0.0) continue;
			printf(" %.0f %.1f",v[i].aa,v[i].bb);
		}
		cout<<endl;
	}
	return 0;
}
