#include<iostream>
#include<string>
using namespace std;
int conv(string s){
	int sum=0,a;
	for(int i=0;i<s.size();i++){
		a=s[i]-48;
		sum=sum*10+a;
	}
	return sum;
}
int main(){
//	freopen("1.txt","r",stdin);
	string mars[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string mars2[12]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		if(s[0]>='0'&&s[0]<='9'){
			int a=conv(s);
			int b1=a/13;
			int b2=a%13;
			if(b1!=0){
				if(b2!=0){
					cout<<mars2[b1-1]<<" "<<mars[b2]<<endl;
				}
				else cout<<mars2[b1-1]<<endl;
			}
			else cout<<mars[b2]<<endl;
		}else{
			string ss="";
			int sum=0;
			for(int i=0;i<s.size();i++){
				if(s[i]!=' '){
					ss+=s[i];
				}else{
					for(int j=0;j<12;j++){
						if(ss==mars2[j]){
							sum=(j+1)*13;
							break;
						}
					}
					ss="";
				}
			}
			if(ss.size()!=0){
				for(int i=0;i<12;i++){
					if(ss==mars2[i]){
						sum+=(i+1)*13;
						break;
					}
				}for(int i=0;i<13;i++){
					if(ss==mars[i]){
						sum+=i;
						break;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
