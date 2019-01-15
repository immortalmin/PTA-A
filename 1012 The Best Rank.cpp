#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
struct Info{
	int id;
	string name;
	int c;
	int m;
	int e;
	double a;
	int cc;
	int mm;
	int ee;
	int aa;
}info;
vector<Info>v,vv;
map<string,int>ma;//从1开始 
bool mysort1(const Info&a,const Info&b){//根据c语言成绩排名 
	return a.c>b.c; 
}
bool mysort2(const Info&a,const Info&b){//根据数学成绩排名 
	return a.m>b.m; 
}
bool mysort3(const Info&a,const Info&b){//根据英语成绩排名 
	return a.e>b.e; 
}
bool mysort4(const Info&a,const Info&b){//根据平均成绩排名 
	return a.a>b.a; 
}
bool mysort5(const Info&a,const Info&b){//根据平均成绩排名 
	return a.id<b.id; 
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	ma.clear();
	v.clear();
	for(int i=0;i<n;i++){
		cin>>info.name>>info.c>>info.m>>info.e;
		info.id=i;
		info.a=(info.c+info.m+info.e)/3.0;
		v.push_back(info);
		ma[info.name]=v.size();
	}
	sort(v.begin(),v.end(),mysort1);
	v[0].cc=1;
	int sk=1;
	int sk2=1;
	for(int i=1;i<v.size();i++){
		if(v[i].c==v[i-1].c){
			v[i].cc=sk;
			sk2++;
		}
		else{
			sk+=sk2;
			v[i].cc=sk;
			sk2=1;
		}
	}
	sort(v.begin(),v.end(),mysort2);
	v[0].mm=1;
	sk=1;
	sk2=1;
	for(int i=1;i<v.size();i++){
		if(v[i].m==v[i-1].m){
			v[i].mm=sk;
			sk2++;
		}
		else{
			sk+=sk2;
			v[i].mm=sk;
			sk2=1;
		}
	}
	sort(v.begin(),v.end(),mysort3);
	v[0].ee=1;
	sk=1;
	sk2=1;
	for(int i=1;i<v.size();i++){
		if(v[i].e==v[i-1].e){
			v[i].ee=sk;
			sk2++;
		}
		else{
			sk+=sk2;
			v[i].ee=sk;
			sk2=1;
		}
	}
	sort(v.begin(),v.end(),mysort4);
	v[0].aa=1;
	sk=1;
	sk2=1;
	for(int i=1;i<v.size();i++){
		if(v[i].a==v[i-1].a){
			v[i].aa=sk;
			sk2++;
		}
		else{
			sk+=sk2;
			v[i].aa=sk;
			sk2=1;
		}
	}
	sort(v.begin(),v.end(),mysort5);
	string s;
	for(int i=0;i<m;i++){
		int k=v.size()+1;
		cin>>s;
		if(ma[s]==0){
			cout<<"N/A"<<endl;
			continue;
		}
		int ind=ma[s]-1;
		char c;
		if(v[ind].aa<k){
			k=v[ind].aa;
			c='A';
		}
		if(v[ind].cc<k){
			k=v[ind].cc;
			c='C';
		}
		if(v[ind].mm<k){
			k=v[ind].mm;
			c='M';
		}
		if(v[ind].ee<k){
			k=v[ind].ee;
			c='E';
		}
		cout<<k<<" "<<c<<endl;
	}
	return 0;
} 
