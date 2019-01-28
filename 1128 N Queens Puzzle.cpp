#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<int,int>mm;
int booky[1010];
int main(){
//	freopen("1.txt","r",stdin);
	int k,n,a,x,y;
	cin>>k;
	for(int ii=0;ii<k;ii++){
		mm.clear();
		memset(booky,0,sizeof(booky));
		int flag=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>y;
			x=i;
			if(booky[y]==1) flag=1;
			else booky[y]=1;
			a=x-y;
			if(mm[a]==1) flag=1;
			else mm[a]=1;
		}
		if(flag==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
