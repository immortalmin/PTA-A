#include<iostream>
#include<cstring>
using namespace std;
int mm[100010];
int main(){
//	freopen("1.txt","r",stdin);
	memset(mm,0,sizeof(mm));
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>0&&a<=100000){
			mm[a]=1;
		}
	}
	for(int i=1;i<100010;i++){
		if(mm[i]==0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
