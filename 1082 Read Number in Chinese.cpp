#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>v;
string q[4]={"Qian","","Shi","Bai"};
string c[9]={"yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
//	freopen("1.txt","r",stdin);
	string s;
	while(cin>>s){
		v.clear();
		if(s=="0"||s=="-0"){
			cout<<"ling"<<endl;
			continue;
		}
		if(s[0]=='-'){
			v.push_back("Fu");
			s=s.substr(1,s.size());
		}
		int w,a,l=0,l1=0,l2=0;
		for(int i=0;i<s.size();i++){
			w=(s.size()-i)%4;
			a=s[i]-48;
			if(a==0){
				l=1;
				if(w==1){
					if(s.size()>8){
						if(l1==0){
							v.push_back("Yi");
							l1=1;
						}else if(l1==1&&v[v.size()-1]!="Yi"){
							v.push_back("Wan");
							l1=2;
						}else if(l1==1) l1=2;
					}else if(s.size()>4){
						if(l2==0){
							v.push_back("Wan");
							l2=1;
						}
					}
				}
				continue;
			}else if(a!=0&&l==1){
				v.push_back("ling");
				l=0;
			}
			if(a!=0){
				v.push_back(c[a-1]);
			}
			if(w!=1) v.push_back(q[w]);
			else{
				if(s.size()>8){
					if(l1==0){
						v.push_back("Yi");
						l1=1;
					}else if(l1==1){
						v.push_back("Wan");
						l1=2;
					}
				}else if(s.size()>4){
					if(l2==0){
						v.push_back("Wan");
						l2=1;
					}
				}
			}
		}
		for(int i=0;i<v.size();i++){
			if(i!=0) cout<<" ";
			cout<<v[i];
		}
		cout<<endl;
	}
	return 0;
}
