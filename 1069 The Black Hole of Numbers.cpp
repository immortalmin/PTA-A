#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string redu(string b,string a){
	string s="";
	int k=0,aa,bb;
	char c;
	for(int i=0;i<4;i++){
		aa=a[i]-48,bb=b[i]-48;
		if(aa-bb-k>=0){
			c=(aa-bb-k)+48;
			s=c+s;
			k=0;
		}else{
			c=(aa+10-bb-k)+48;
			s=c+s;
			k=1;
		}
	}
	return s;
}
int main(){
//	freopen("1.txt","r",stdin);
	string s1,s2,s3;
	while(cin>>s1){
		while(s1.size()<4) s1='0'+s1;
		while(true){
			sort(s1.begin(),s1.end());
			s2=s1;
			reverse(s1.begin(),s1.end());
			s3=redu(s1,s2);
			cout<<s1<<" - "<<s2<<" = "<<s3<<endl;
			if(s3=="6174"||s3=="0000") break;
			s1=s3;
		}
	}
	return 0;
}
