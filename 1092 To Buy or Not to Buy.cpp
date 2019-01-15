#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int book[1010];
int main(){
//	freopen("1.txt","r",stdin);
	memset(book,0,sizeof(book));
	string s1,s2;
	cin>>s1>>s2;
	int sum1=0,sum2=0,flag=0;
	for(int i=0;i<s2.size();i++){
		if(s1.find(s2[i])>s1.size()-1||s1.find(s2[i])<0){
			sum1++;
			flag=-1;
		}else if(book[s1.find(s2[i])]==0){
			book[s1.find(s2[i])]=1;
			s1[s1.find(s2[i])]='#';
		}else{
			sum1++;
			flag=-1;
		}
	}
	if(flag==-1){
		cout<<"No "<<sum1<<endl;
	}else{
		cout<<"Yes "<<s1.size()-s2.size()<<endl;
	}
	return 0;
}
