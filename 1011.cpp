#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	double a[3];//保存最大值
	int bb[3];
	char c[3]={'W','T','L'}; 
	double b;
	memset(a,0,sizeof(a));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>b;
			if(b>a[i]){
				a[i]=b;
				bb[i]=j;
			}
		}
	}
	for(int i=0;i<3;i++){
		cout<<c[bb[i]]<<" ";
	}
	double sum=(a[0]*a[1]*a[2]*0.65-1)*2;
	printf("%.2lf\n",sum);
	return 0;
} 
