#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
vector<int>v;
bool mysort(int a,int b){
	return a>b;
}
int N,n,m,a;
int arr[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int map[10010][10010];
int book[10010][10010];
bool judge(int x,int y){
	if(x<1||y<1||x>m||y>n||book[x][y]==1) return false;
	return true;
}
int main() {
//	freopen("1.txt","r",stdin);
	fill(book[0],book[0]+10010+10010,0);
	fill(map[0],map[0]+10010+10010,0);
	cin>>N;
	for(int i=sqrt(N); i>=1; i--) {
		n=i;
		if(N%n==0) {
			m=N/n;
			break;
		}
	}
	for(int i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),mysort);
	int x=1,y=0,ak=0,newx,newy;
	for(int i=0;i<v.size();i++){
		newx=x+arr[ak][0];
		newy=y+arr[ak][1];
		if(!judge(newx,newy)){
			ak++;
			if(ak==4) ak=0;
			newx=x+arr[ak][0];
			newy=y+arr[ak][1];
		}
		map[newx][newy]=v[i];
		book[newx][newy]=1;
		x=newx,y=newy;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j!=1) cout<<" ";
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}
