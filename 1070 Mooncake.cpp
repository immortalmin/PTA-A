#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio> 
using namespace std;
struct Info{
	double aa;
	double bb;
}info;
vector<Info>v;
bool mysort(const Info&a,const Info&b){
	return (a.aa/a.bb)<(b.aa/b.bb);
}
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	double sum1,sum2=0;
	cin>>n>>sum1;
	for(int i=0;i<n;i++){
		cin>>info.aa;
		v.push_back(info);
	}
	for(int i=0;i<v.size();i++){
		cin>>v[i].bb;
	}
	sort(v.begin(),v.end(),mysort);
	for(int i=0;i<v.size();i++){
		if(v[i].aa>sum1){
			sum2=sum2+(sum1*v[i].bb/v[i].aa);
			sum1=0;
			break;
		}else{
			sum2+=v[i].bb;
			sum1-=v[i].aa;
		}
	}
	printf("%.2lf\n",sum2);
	return 0;
} 
