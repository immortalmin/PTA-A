#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	string s,s2,s3;
	int k;//用来保存小数点的位置 
	while(cin>>s){
		s2="",s3="";
		int flag=1,flag2=0,flag3=0;
		if(s[0]=='-') flag=-1;
		for(int i=1;i<s.size();i++){
			if(s[i]!='.'&&s[i]!='E'&&flag2==0){
				s2+=s[i];
			}else if(s[i]=='.') k==i;
			else if(s[i]=='E') flag2=1;
			else if(s[i]=='-') flag3=-1;
			else if(s[i]=='+') flag3=1;
			else if(flag3!=0) s3+=s[i];
		}
		int sum=0,a;
		for(int i=0;i<s3.size();i++){
			a=s3[i]-48;
			sum=sum*10+a;
		}
		if(flag3==-1){
			while(sum>1){
				s2='0'+s2;
				sum--;
			}
			s2="0."+s2;
			if(flag==-1) s2='-'+s2;
		}else{
			if(sum>s2.size()-1){
				int kk=sum-(s2.size()-1);
				while(kk--){
					s2+='0';
				}
			}else if(sum<s2.size()-1){
				k+=(s2.size()+1-sum);
				string s4="";
				for(int i=0;i<s2.size();i++){
					if(i==k) s4+='.';
					s4+=s2[i];
				}
				s2=s4;
			}
			if(flag==-1) s2='-'+s2;
		}
		cout<<s2<<endl;
	}
	return 0;
}
