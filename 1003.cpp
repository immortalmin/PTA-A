#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int count[510];//保存每个城市救援队的数量 
int map[510][510];//保存地图
int book[510];//标记 
int m,n,startc,endc,sum=0,sum1,mint=999999;
struct Info{
	int aa;//当前位置
	int bb;//时间 
	int cc;//救援队数量 
}info;
vector<Info>v;
void dfs(int nowc,int nowt,int nows){//当前城市，当前时间，当前救援队数量 
	if(nowt>mint) return ;
	if(nowc==endc&&nowt<=mint){
		if(nowt<mint){
			mint=nowt;
			sum=nows;
			sum1=1;
		}else{
			if(nows>sum) sum=nows;
			sum1++;
		}
		return ;
	}
	for(int i=0;i<m;i++){
		if(book[i]==0&&map[nowc][i]!=0){
			book[i]=1;
			dfs(i,nowt+map[nowc][i],nows+count[i]);
			book[i]=0;
		}
	}
	return ;
}
int main(){
//	freopen("1.txt","r",stdin);
	while(cin>>m>>n>>startc>>endc){
		mint=999999,sum=0,sum1=0;
		memset(count,0,sizeof(count));
		memset(book,0,sizeof(book));
		for(int i=0;i<510;i++){
			memset(map[i],0,sizeof(map[i]));
		}
		v.clear();
		for(int i=0;i<m;i++){//保存每个城市救援队的数量 
			cin>>count[i];
		}
		int a,b,c;
		for(int i=0;i<n;i++){//输入地图 
			cin>>a>>b>>c;
			map[a][b]=c;
			map[b][a]=c;
		}
		dfs(startc,0,count[startc]);
		cout<<sum1<<" "<<sum<<endl; 
	}
	return 0;
}
