#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct Info{
	string r_number;
	int f_rank;
	int l_number;
	int l_rank;
	int score;
}info;
vector<Info>v,vv;
bool mysort1(const Info&a,const Info&b){
	return a.score>b.score;
}
bool mysort2(const Info&a,const Info&b){
	if(a.score!=b.score) return a.score>b.score;
	else return a.r_number<b.r_number;
}
int main(){
//	freopen("1.txt","r",stdin);
	int T,n,score,k1,k2=1,kk1,kk2=1;
	string r_number;
	cin>>T;
	for(int z=1;z<=T;z++){
		v.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r_number>>score;
			info.r_number=r_number;
			info.l_number=z;
			info.score=score;
			v.push_back(info);
		}
		sort(v.begin(),v.end(),mysort1);
		v[0].l_rank=1;
		vv.push_back(v[0]);
		k1=1,kk1=1;
		for(int i=1;i<v.size();i++){
			kk1++;
			if(v[i].score==v[i-1].score){
				v[i].l_rank=k1;
			}else{
				k1=kk1;
				v[i].l_rank=k1;
			}
			vv.push_back(v[i]);
		}
	}
	sort(vv.begin(),vv.end(),mysort2);
	cout<<vv.size()<<endl;
	cout<<vv[0].r_number<<" "<<1<<" "<<vv[0].l_number<<" "<<vv[0].l_rank<<endl;
	for(int i=1;i<vv.size();i++){
		kk2++;
		if(vv[i].score==vv[i-1].score){
			cout<<vv[i].r_number<<" "<<k2<<" "<<vv[i].l_number<<" "<<vv[i].l_rank<<endl;
		}else{
			k2=kk2;
			cout<<vv[i].r_number<<" "<<k2<<" "<<vv[i].l_number<<" "<<vv[i].l_rank<<endl;
		}
	} 
	return 0;
}
