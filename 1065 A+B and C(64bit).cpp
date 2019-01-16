#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a,string b) {
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string s="",t;
	int k=0,aa,bb,cc;
	char c;
	if(a.size()<b.size()) {
		t=a;
		a=b;
		b=t;
	}
	for(int i=0; i<a.size(); i++) {
		if(i<b.size()) {
			aa=a[i]-48;
			bb=b[i]-48;
			cc=(aa+bb+k)%10;
			k=(aa+bb+k)/10;
			c=cc+48;
			s=c+s;
		} else {
			aa=a[i]-48;
			bb=(aa+k)%10;
			c=bb+48;
			s=c+s;
			k=(aa+k)/10;
		}
	}
	if(k!=0) {
		c=k+48;
		s=c+s;
	}
	return s;
}
string redu(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string s="",t;
	int k=0,aa,bb,cc;
	char c;
	for(int i=0; i<a.size(); i++) {
		if(i<b.size()) {
			aa=a[i]-48;
			bb=b[i]-48;
			if(aa-bb-k<0){
				aa+=10;
				cc=(aa-bb-k)%10;
				c=cc+48;
				s=c+s;
				k=1;
			}else{
				cc=(aa-bb-k)%10;
				c=cc+48;
				s=c+s;
				k=0;
			}
		} else {
			aa=a[i]-48;
			if(aa-k<0){
				aa+=10;
				cc=(aa-k)%10;
				c=cc+48;
				s=c+s;
				k=1;
			}else{
				cc=(aa-k)%10;
				c=cc+48;
				s=c+s;
				k=0;
			}
		}
	}
	string ss="";
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'&&flag==0) continue;
		else{
			ss+=s[i];
			flag=1;
		}
	}
	if(flag==0) ss="0";
	return ss;
}
int judge(string a,string b){
	if(a.size()>b.size()) return 1;
	else if(b.size()>a.size()) return 2;
	else{
		if(a>b) return 1;
		else return 2;
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	string a,b,c,s;
	int n;
	cin>>n;
	for(int ii=0;ii<n;ii++){
		cin>>a>>b>>c;
		if(a[0]!='-'&&b[0]!='-'){
			s=add(a,b);
		}else if(a[0]=='-'&&b[0]=='-'){
			a=a.substr(1,a.size());
			b=b.substr(1,b.size());
			s='-'+add(a,b);
		}else if(a[0]!='-'&&b[0]=='-'){
			b=b.substr(1,b.size());
			if(judge(a,b)==1) s=redu(a,b);
			else{
				s=redu(b,a);
				if(s!="0") s='-'+s;
			}
		}else if(a[0]=='-'&&b[0]!='-'){
			a=a.substr(1,a.size());
			if(judge(a,b)==1){
				s=redu(a,b);
				if(s!="0") s='-'+s;
			}
			else s=redu(b,a);
		}
		cout<<"Case #"<<ii+1<<": ";
		if(s[0]!='-'&&c[0]!='-'){
			if(judge(s,c)==1) cout<<"true"<<endl;
			else cout<<"false"<<endl;
		}else if(s[0]=='-'&&c[0]!='-') cout<<"false"<<endl;
		else if(s[0]!='-'&&c[0]=='-') cout<<"true"<<endl;
		else{
			s=s.substr(1,s.size());
			c=c.substr(1,c.size());
			if(judge(s,c)==1||c==s) cout<<"false"<<endl;
			else cout<<"true"<<endl;
		}
	}
	return 0;
}
