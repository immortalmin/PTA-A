#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n,m;
int a[200][200],b[200],c[200];
void dfs(int now,int gener){
	for(int i=0;i<c[now];i++){
		b[a[now][i]]=gener+1;
		dfs(a[now][i],gener+1);
	}
	return ;
}
int main(){
//	freopen("1.txt","r",stdin);
	for(int i=0;i<200;i++) memset(a[i],0,sizeof(a[i]));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n>>m;
	int a2,n2,a3;
	for(int i=0;i<m;i++){
		cin>>a2>>n2;
		c[a2]=n2;
		for(int j=0;j<n2;j++){
			cin>>a[a2][j];
		}
	}
	b[1]=1;
	dfs(1,1);
	int sum,max=1,k=1;
	for(int i=2;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(b[j]==i) sum++;
		}
		if(sum>max){
			max=sum;
			k=i;
		}
	}
	cout<<max<<" "<<k<<endl;
	return 0;
} 
