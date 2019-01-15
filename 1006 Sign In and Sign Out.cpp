#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Info{
	string name;
	int inh;
	int inm;
	int ins;
	int outh;
	int outm;
	int outs;	
}info;
vector<Info>v;
bool mysort(const Info&a,const Info&b){
	if(a.inh!=b.inh) return a.inh<b.inh;
	else if(a.inm!=b.inm) return a.inm<b.inm;
	else return a.ins<b.ins;
}
bool mysort2(const Info&a,const Info&b){
	if(a.outh!=b.outh) return a.outh>b.outh;
	else if(a.outm!=b.outm) return a.outm>b.outm;
	else return a.outs>b.outs;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	while(cin>>n){
		v.clear();
		string name;
		int aa,bb,cc,dd,ee,ff;
		for(int i=0;i<n;i++){
			cin>>info.name;
			scanf("%d:%d:%d %d:%d:%d",&info.inh,&info.inm,&info.ins,&info.outh,&info.outm,&info.outs);
			v.push_back(info);
		}
		sort(v.begin(),v.end(),mysort);
		cout<<v[0].name<<" ";
		sort(v.begin(),v.end(),mysort2);
		cout<<v[0].name<<endl;
	}
	return 0;
} 
