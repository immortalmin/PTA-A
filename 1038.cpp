#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool pan(string a,string b) { //判断两个字符串的最小组合，
	string s1=a+b;//第一种组合方式
	string s2=b+a;//第二种组合方式
	//判断两种组合方式哪种更小
	if(s1<s2) return true;//1
	else return false;//0
}
vector<string>v;
bool mysort(const string&a,const string&b) {
	if(pan(a,b)) {
		if(a<b) return a<b;
//		else return a>b;
		else return b<a;
	} else {
		if(a<b) return b<a;
		else return a<b;
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	int n;
	while(cin>>n) {
		v.clear();
		string a;
		for(int i=0; i<n; i++) {
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end(),mysort);
		int flag=0;
		string s="";
		for(int i=0; i<v.size(); i++) {
			s+=v[i];
		}
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='0'&&flag==0) continue;
			else {
				flag=1;
				cout<<s[i];
			}
		}
		if(flag==0) cout<<0;
		cout<<endl;
	}

	return 0;
}
