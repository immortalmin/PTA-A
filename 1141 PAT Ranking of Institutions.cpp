#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct Info{
	string school;
	double tws;
	int ns;
}info;
vector<Info>v;
map<string,int>mm;
string lower(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
	}
	return s;
}
bool mysort(const Info&a,const Info&b){
	if(int(a.tws)!=int(b.tws)) return a.tws>b.tws;
	else if(a.ns!=b.ns) return a.ns<b.ns;
	else return a.school<b.school;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	string id,school;
	double score;
	mm.clear();
	v.clear();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>id>>score>>school;
		school=lower(school);
		if(id[0]=='B') score/=1.5;
		else if(id[0]=='T') score*=1.5;
		if(mm[school]==0){
			info.school=school;
			info.tws=score;
			info.ns=1;
			v.push_back(info);
			mm[school]=v.size();
		}else{
			v[mm[school]-1].tws+=score;
			v[mm[school]-1].ns++;
		}
	}
	sort(v.begin(),v.end(),mysort);
	cout<<v.size()<<endl;
	int k1=1,k2=1;
	cout<<k1<<" "<<v[0].school<<" "<<int(v[0].tws)<<" "<<v[0].ns<<endl;
	for(int i=1;i<v.size();i++){
		k2++;
		if(int(v[i].tws)!=int(v[i-1].tws)){
			k1=k2;
		}
		cout<<k1<<" "<<v[i].school<<" "<<int(v[i].tws)<<" "<<v[i].ns<<endl;
	}
	return 0;
} 
