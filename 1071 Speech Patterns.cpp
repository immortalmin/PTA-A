#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
struct Info {
	string word;
	int num;
} info;
vector<Info>v;
map<string,int>mm;
bool mysort(Info a,Info b) {
	if(a.num!=b.num) return a.num>b.num;
	else return a.word<b.word;
}
int main() {
//	freopen("1.txt","r",stdin);
	string s;
	getline(cin,s);
	string ss="";
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
		if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9') {
			ss+=s[i];
		} else {
			if(ss.size()!=0) {
				if(mm[ss]==0) {
					info.word=ss;
					info.num=1;
					v.push_back(info);
					mm[ss]=v.size();
				} else {
					v[mm[ss]-1].num++;
				}
				ss="";
			}
		}
	}
	if(ss.size()!=0) {
		if(mm[ss]==0) {
			info.word=ss;
			info.num=1;
			v.push_back(info);
			mm[ss]=v.size();
		} else {
			v[mm[ss]-1].num++;
		}
		ss="";
	}
	sort(v.begin(),v.end(),mysort);
	cout<<v[0].word<<" "<<v[0].num<<endl;
	return 0;
}
