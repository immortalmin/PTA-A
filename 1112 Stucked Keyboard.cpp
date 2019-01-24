#include<iostream>
#include<string>
#include<map>
using namespace std;
int k;
string s;
map<char,int>mm,m2;
bool judge(int now){
	int flag=0;
	if(now+k>s.size()) return false;
	for(int i=now+1;i<now+k;i++){
		if(s[i]!=s[now]){
			flag=1;
			break;
		}
	}
	if(flag==0) return true;
	else return false;
}
int main(){
//	freopen("1.txt","r",stdin);
	cin>>k>>s;
	mm.clear();
	m2.clear();
	for(int i=0;i<s.size();i++){
		if(mm[s[i]]==1) continue;
		if(judge(i)) i+=(k-1);
		else{
			mm[s[i]]=1;
		}
	}
	string s1="",s2="";
	for(int i=0;i<s.size();i++){
		s1+=s[i];
		if(mm[s[i]]==0){
			i+=(k-1);
			if(m2[s[i]]==0){
				s2+=s[i];
				m2[s[i]]=1;
			}
		} 
	}
	cout<<s2<<endl<<s1<<endl;
	return 0;
}
