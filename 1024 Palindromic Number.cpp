#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool judge(string s){//判断字符串是不是回文 
	int len=s.size();
	for(int i=0;i<len/2;i++) if(s[i]!=s[len-1-i]) return false;
	return true;
}
string proc(string s1){
	string s2=s1;
	reverse(s1.begin(),s1.end());
	string s="";
	int a,b,len=s1.size()-1,ak=0,bk;
	char c;
	for(int i=0;i<s1.size();i++){
		a=s1[i]-48;
		b=s2[i]-48;
		bk=(a+b+ak)%10;
		ak=(a+b+ak)/10;
		c=bk+48;
		s=c+s;
	}
	if(ak!=0){
		c=ak+48;
		s=c+s;
	}
	return s;
}
int main(){
//	freopen("1.txt","r",stdin);
	string n;
	int limit;
	while(cin>>n>>limit){
		int k=limit,flag=0;
		while(!judge(n)){
			if(k==0){
				flag=1;
				cout<<n<<endl<<limit<<endl;
				break;
			}
			k--;
			n=proc(n);	
		}
		if(flag==0){
			cout<<n<<endl<<limit-k<<endl;
		}
	}
	return 0;
}
