#include<iostream>
#include<string>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	string s="#";
	int a,b1,b2;
	char mars[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	for(int i=0;i<3;i++){
		cin>>a;
		b1=a/13;
		b2=a%13;
		s=s+mars[b1]+mars[b2];
	}
	cout<<s<<endl;
	return 0;
} 
