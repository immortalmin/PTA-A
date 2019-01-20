#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map<string,int>mm,m2;
int prime[10010];//0:素数，1:非素数 
void primes(){
	prime[1]=1;
	for(int i=2;i<10010;i++){
		if(prime[i]==0){
			for(int j=i+i;j<10010;j+=i){
				prime[j]=1;
			}
		}
	}
}
int main(){
//	freopen("1.txt","r",stdin);
	memset(prime,0,sizeof(prime));
	mm.clear();
	m2.clear();
	primes();
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		mm[s]=i;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		cout<<s<<": ";
		if(m2[s]==0){
			m2[s]=1;
		}else if(mm[s]!=0){
			cout<<"Checked"<<endl;
			continue;
		}
		if(mm[s]==0) cout<<"Are you kidding?"<<endl;
		else if(mm[s]==1) cout<<"Mystery Award"<<endl;
		else if(prime[mm[s]]==0) cout<<"Minion"<<endl;
		else cout<<"Chocolate"<<endl;
	}
	return 0;
}
