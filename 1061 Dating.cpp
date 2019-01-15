#include<iostream>
#include<string>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	string s[4];
	for(int i=0;i<4;i++) cin>>s[i];
	char a,b;
	int c,flag=0;
	for(int i=0;i<s[0].size();i++){
		if(s[0][i]==s[1][i]&&s[0][i]>='A'&&s[0][i]<='G'&&flag==0){
			a=s[0][i];
			flag=1;
		}else if(s[0][i]==s[1][i]&&(s[0][i]>='A'&&s[0][i]<='N'||s[0][i]>='0'&&s[0][i]<='9')&&flag==1){
			b=s[0][i];
			break;
		}
	}
	for(int i=0;i<s[2].size();i++){
		if(s[2][i]==s[3][i]&&(s[2][i]>='A'&&s[2][i]<='Z'||s[2][i]>='a'&&s[2][i]<='z')){
			c=i;
		}
	}
	int aa=a-64; 
	cout<<week[aa-1]<<" ";
	int bb;
	if(b>='A'&&b<='N'){
		bb=b-64;
		cout<<bb+9<<":";
	}
	else{
		bb=b-48;
		cout<<"0"<<bb<<":";
	}
	if(c<10) cout<<"0"<<c<<endl;
	else cout<<c<<endl;
	return 0;
}
