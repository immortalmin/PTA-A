#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
vector<string>v;//保存最终路径 
map<string,int>m1;//城市名转数值 
map<int,string>m2;//数值转城市名 
int n,m;
int a[210];//保存路径 
int b[210];//保存happy
int book[210];//标记已经经过的城市
int map2[210][210];//保存路线 
string beginn;
int mincost=pow(2,31)-1,maxhappy=0,count=1;
double average=0;
void dfs(int step,int now,int cost,int happy){
	if(cost>mincost) return ;
	if(m2[now]=="ROM"){
		if(cost==mincost) count++;
		if(cost<mincost){
			count=1;
			mincost=cost;
			maxhappy=happy;
			average=double(maxhappy)/double(step-1);
			v.clear();
			for(int i=0;i<step;i++){
				v.push_back(m2[a[i]]);
			}
		}else if(cost==mincost&&maxhappy<happy){
			maxhappy=happy;
			average=double(maxhappy)/double(step-1);
			v.clear();
			for(int i=0;i<step;i++){
				v.push_back(m2[a[i]]);
			}
		}else if(cost==mincost&&maxhappy==happy&&average<double(happy)/double(step-1)){
			average=double(happy)/double(step-1);
			v.clear();
			for(int i=0;i<step;i++){
				v.push_back(m2[a[i]]);
			}
		}
		return ;
	}
	for(int i=1;i<n;i++){
		if(book[i]==0&&map2[now][i]!=0){
			book[i]=1;
			a[step]=i;
			dfs(step+1,i,cost+map2[now][i],happy+b[i]);
			book[i]=0;
		}
	}
	return ;
}
int main(){
//	freopen("1.txt","r",stdin);
	memset(b,0,sizeof(b));
	memset(book,0,sizeof(book));
	for(int i=0;i<210;i++){
		memset(map2[i],0,sizeof(map2[i]));
	}
	m1.clear();
	m2.clear();
	cin>>n>>m>>beginn;
	m1[beginn]=n;
	m2[n]=beginn;
	string s;
	int cost,k1=0;
	for(int i=1;i<n;i++){
		cin>>s;
		k1++;
		m1[s]=k1;
		m2[k1]=s;
		cin>>b[k1];
	}
	string s1,s2;
	for(int i=0;i<m;i++){
		cin>>s1>>s2;
		cin>>map2[m1[s1]][m1[s2]];
		map2[m1[s2]][m1[s1]]=map2[m1[s1]][m1[s2]];
	}
	a[0]=n;
	book[n]=1;
	dfs(1,m1[beginn],0,0);
	cout<<count<<" "<<mincost<<" "<<maxhappy<<" "<<int(average)<<endl;
	for(int i=0;i<v.size();i++){
		if(i!=0) cout<<"->";
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}
