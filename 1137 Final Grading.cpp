#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct Info{
	string id;
	int online;
	int mid;
	int final;
	int total;
}info;
vector<Info>v;
map<string,int>mm;
bool mysort(const Info&a,const Info&b){
	if(a.total!=b.total) return a.total>b.total;
	else return a.id<b.id;
}
int main(){
//	freopen("1.txt","r",stdin);
	int p,m,n;
	mm.clear();
	v.clear();
	string s;
	int score;
	cin>>p>>m>>n;
	for(int i=0;i<p;i++){
		cin>>s>>score;
		info.id=s;
		info.online=score;
		info.mid=-1;
		info.final=-1;
		v.push_back(info);
		mm[s]=v.size();
	}
	for(int i=0;i<m;i++){
		cin>>s>>score;
		if(mm[s]==0){
			info.id=s;
			info.online=-1;
			info.mid=score;
			info.final=-1;
			v.push_back(info);
			mm[s]=v.size();
		}else{
			v[mm[s]-1].mid=score;
		}
	}
	for(int i=0;i<n;i++){
		cin>>s>>score;
		if(mm[s]==0){
			info.id=s;
			info.online=-1;
			info.mid=-1;
			info.final=score;
			v.push_back(info);
			mm[s]=v.size();
		}else{
			v[mm[s]-1].final=score;
		}
	}
	for(int i=0;i<v.size();i++){
		if(v[i].mid>v[i].final){
			v[i].total=v[i].mid*0.4+v[i].final*0.6-int(v[i].mid*0.4+v[i].final*0.6)>=0.5?int(v[i].mid*0.4+v[i].final*0.6)+1:int(v[i].mid*0.4+v[i].final*0.6);
		}
		else v[i].total=v[i].final;
	}
	sort(v.begin(),v.end(),mysort);
	for(int i=0;i<v.size();i++){
		if(v[i].online<200||v[i].total<60) continue;
		cout<<v[i].id<<" "<<v[i].online<<" "<<v[i].mid<<" "<<v[i].final<<" "<<v[i].total<<endl;
	}
	return 0;
}
