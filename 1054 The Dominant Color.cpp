#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Info{
	string color;
	int count;
}info;
vector<Info>v;
map<string,int>mm;
bool mysort(const Info&a,const Info&b){
	return a.count>b.count;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	v.clear();
	mm.clear();
	string a;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a;
			if(mm[a]==0){
				info.color=a;
				info.count=1;
				v.push_back(info);
				mm[a]=v.size();
			}else{
				v[mm[a]-1].count++;
			}
		}
	}
	sort(v.begin(),v.end(),mysort);
	cout<<v[0].color<<endl;
	return 0;
} 
