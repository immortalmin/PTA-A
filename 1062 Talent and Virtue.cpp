#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Info{
	string id;
	int talent;
	int virtue;
	int total;
}info;
vector<Info>v1,v2,v3,v4;
bool mysort(const Info&a,const Info&b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.virtue!=b.virtue) return a.virtue>b.virtue;
	else return a.id<b.id;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,l,h;
	cin>>n>>l>>h;
	char c[10];
	for(int i=0;i<n;i++){
		//用cin会超时，所以用scanf 
		scanf("%s %d %d",c,&info.virtue,&info.talent);
		info.id=c;
//		cin>>info.id>>info.virtue>>info.talent;
		info.total=info.talent+info.virtue;
		if(info.talent<l||info.virtue<l) continue;
		if(info.talent>=h&&info.virtue>=h) v1.push_back(info);
		else if(info.talent<h&&info.virtue>=h) v2.push_back(info);
		else if(info.talent<h&&info.virtue<h&&info.virtue>=info.talent) v3.push_back(info);
		else v4.push_back(info);
	}
	sort(v1.begin(),v1.end(),mysort);
	sort(v2.begin(),v2.end(),mysort);
	sort(v3.begin(),v3.end(),mysort);
	sort(v4.begin(),v4.end(),mysort);
	cout<<v1.size()+v2.size()+v3.size()+v4.size()<<endl;
	for(int i=0;i<v1.size();i++){
		cout<<v1[i].id<<" "<<v1[i].virtue<<" "<<v1[i].talent<<endl;
	}
	for(int i=0;i<v2.size();i++){
		cout<<v2[i].id<<" "<<v2[i].virtue<<" "<<v2[i].talent<<endl;
	}
	for(int i=0;i<v3.size();i++){
		cout<<v3[i].id<<" "<<v3[i].virtue<<" "<<v3[i].talent<<endl;
	}
	for(int i=0;i<v4.size();i++){
		cout<<v4[i].id<<" "<<v4[i].virtue<<" "<<v4[i].talent<<endl;
	}
	return 0;
}
