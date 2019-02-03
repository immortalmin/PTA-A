#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
vector<int>v,vv,v3;
int book[50000];
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	while(cin>>n){
		memset(book,0,sizeof(book));
		v.clear();
		vv.clear();
		v3.clear();
		int maxnum=0,sum=1;
		if(n>1000){//耍了个小聪明 
			for(int i=2;i<=sqrt(n);i++){
				if(n%i==0){
					v.push_back(i);
				}
			}
		}else{
			for(int i=2;i<=n/2;i++){
				if(n%i==0){
					v.push_back(i);
				}
			}
		}
		v.push_back(n);
		for(int i=0;i<v.size();i++){
			vv.push_back(v[i]);
			sum=v[i];
			if(v.size()==1){
				v3.push_back(v[0]);
			}
			for(int j=i+1;j<v.size();j++){
				if(v[j]==v[j-1]+1){
					sum*=v[j];
					if(n%sum==0) vv.push_back(v[j]);
					else{
						if(vv.size()>maxnum){
							maxnum=vv.size();
							v3=vv;
						}
						vv.clear();
					}
				}
				else{
					if(vv.size()>maxnum){
						maxnum=vv.size();
						v3=vv;
					}
					vv.clear();
				}
			}
		}
		cout<<v3.size()<<endl;
		for(int i=0;i<v3.size();i++){
			if(i!=0) cout<<"*";
			cout<<v3[i];
		}
		cout<<endl;
	}
	return 0;
}
