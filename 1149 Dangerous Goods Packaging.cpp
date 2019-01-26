#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
map<int,int>mm;
vector<int>v[10010],v2;
int main(){
//	freopen("1.txt","r",stdin);
	int n,m,a,b,k,kk=1;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(mm[a]==0) mm[a]=kk++;
		v[mm[a]].push_back(b);
		if(mm[b]==0) mm[b]=kk++;
		v[mm[b]].push_back(a);
	}
	for(int ii=0;ii<m;ii++){
		scanf("%d",&k);
		v2.clear();
		int flag=0;
		for(int jj=0;jj<k;jj++){
			scanf("%d",&a);
			if(flag==1) continue;
			if(mm[a]==0) continue;
			for(int i=0;i<v2.size();i++){
				for(int j=0;j<v[mm[a]].size();j++){
					if(v2[i]==v[mm[a]][j]){
						flag=1;
						break;
					}
				}
				if(flag==1) break;
			}
			v2.push_back(a);
		}
		if(flag==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
