#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int count[510];//����ÿ�����о�Ԯ�ӵ����� 
int map[510][510];//�����ͼ
int book[510];//��� 
int m,n,startc,endc,sum=0,sum1,mint=999999;
struct Info{
	int aa;//��ǰλ��
	int bb;//ʱ�� 
	int cc;//��Ԯ������ 
}info;
vector<Info>v;
void dfs(int nowc,int nowt,int nows){//��ǰ���У���ǰʱ�䣬��ǰ��Ԯ������ 
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
		for(int i=0;i<m;i++){//����ÿ�����о�Ԯ�ӵ����� 
			cin>>count[i];
		}
		int a,b,c;
		for(int i=0;i<n;i++){//�����ͼ 
			cin>>a>>b>>c;
			map[a][b]=c;
			map[b][a]=c;
		}
		dfs(startc,0,count[startc]);
		cout<<sum1<<" "<<sum<<endl; 
	}
	return 0;
}
