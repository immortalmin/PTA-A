#include<iostream>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	while(cin>>n){
		int sum=0;
		int k1=0,k2;
		for(int i=0;i<n;i++){
			cin>>k2;
			if(k2>k1){
				sum+=(k2-k1)*6;
			}else{
				sum+=(k1-k2)*4;
			}
			sum+=5;
			k1=k2;
		}
		cout<<sum<<endl;
	}
	return 0;
}
