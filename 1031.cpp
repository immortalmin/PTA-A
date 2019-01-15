#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
char a[100][100];
int main(){
//	freopen("1.txt","r",stdin);
	while(cin>>s){
		for(int i=0;i<100;i++){
			memset(a[i],' ',sizeof(a[i]));
		}
		int N,n1,n2,n3,k,kk=0;
		N=s.size();
		k=(N+2)/3;
		n1=k;
		n3=k;
		n2=N+2-2*k;
		for(int i=1;i<=n1;i++){
			a[i][1]=s[kk++];
		}
		for(int j=2;j<=n2;j++){
			a[n1][j]=s[kk++];
		}
		for(int i=n3-1;i>=1;i--){
			a[i][n2]=s[kk++];
		}
		for(int i=1;i<=n1;i++){
			for(int j=1;j<=n2;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
