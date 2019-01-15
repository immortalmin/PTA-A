#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int book[1010];
//double aa[1010];
struct Info{
	int aa;//指数
	double bb;//系数 
}info;
vector<Info>v1,v2;
vector<double>v3;
map<double,double>mm;
bool mysort(const double&a,const double&b){
	return a>b;
}
int main(){
//	freopen("1.txt","r",stdin);
	memset(book,0,sizeof(book));
	mm.clear();
	int n,m,a;
	double b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>info.aa>>info.bb;
		v1.push_back(info);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>info.aa>>info.bb;
		v2.push_back(info);
	}
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v2.size();j++){
			a=v1[i].aa+v2[j].aa;
			b=v1[i].bb*v2[j].bb;
			if(mm[a]==0){
				mm[a]=b;
				v3.push_back(a);
			}
			else mm[a]+=b;
		}
	}
	if(v3.size()==0){
		cout<<0<<endl;
		return 0;
	}
	sort(v3.begin(),v3.end(),mysort);
	int sum=v3.size();
	if(v3[v3.size()-1]==0) sum--; 
	cout<<sum;
	for(int i=0;i<v3.size();i++){
		if(mm[v3[i]]!=0){
			cout<<" "<<v3[i];
			printf(" %.1lf",mm[v3[i]]);
		}
	}
	cout<<endl;
	return 0;
}
