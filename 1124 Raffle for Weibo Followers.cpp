#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int>mm;
int main(){
//	freopen("1.txt","r",stdin);
	mm.clear();
	int m,n,s,flag=0;
	string name;
	int k;
	cin>>m>>s>>n;
	k=s-1;
	for(int i=1;i<=m;i++){
		cin>>name;
		if(i>=n) k++;
		if(k==s){
			if(mm[name]==0){
				cout<<name<<endl;
				flag=1;
				k=0;
				mm[name]=1;
			}else{
				k--;
			}
		}
	}
	if(flag==0) cout<<"Keep going..."<<endl;
	return 0;
} 
