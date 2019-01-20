#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
double conv(string s){
	double sum=0;
	double k1=0.1;
	int k2=1,a;
	for(int i=0;i<s.size();i++){
		if(s[i]=='.'){
			k2=-1;
			continue;
		}
		if(k2==1){
			a=s[i]-48;
			sum=sum*10+a;
		}else{
			a=s[i]-48;
			sum=sum+a*k1;
			k1*=0.1;
		}
	}
	return sum;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	string s;
	double d,sum2=0;
	int k2=0; 
	for(int z=0;z<n;z++){
		cin>>s;
		int flag1=0;//是否是数值 
		int k1=0;//小数点的个数
		int flag2=1;//是否是负数
		if(s[0]=='-'){//如果第一个字符是符号。就去掉第一个字符，并标记 
			flag2=-1;
			s=s.substr(1,s.size()-1);
		}
		if(s.size()==0){//避免字符串"-"的情况 
			flag1=1;
		}else{
			for(int i=0;i<s.size();i++){
				if(!(s[i]>='0'&&s[i]<='9'||s[i]=='.')){//如果不是数字或小数点 
					flag1=1; 
					break;
				}else if(s[i]=='.'){//如果是小数点 
					k1++;
					//这题小数点居然可以在最后一位，醉了 
					if(k1>1||i==0||s.size()-1-i>2){//小数点在第一位或者有效数字大于2或小数点数量大于1 
						flag1=1;
						break;
					}
				}
			}
		}
		if(flag1==0){
			d=conv(s);
			if(flag2==-1) d=-d;
			if(d<-1000||d>1000){
				if(flag2==-1) s='-'+s;
				cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
				continue;
			}
			sum2+=d;
			k2++;
		}else{
			if(flag2==-1) s='-'+s;
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
		
	}
	if(k2==1){
		printf("The average of 1 number is %.2lf\n",sum2);
	}else if(k2==0){
		cout<<"The average of 0 numbers is Undefined"<<endl;
	}else{
		printf("The average of %d numbers is %.2lf\n",k2,sum2/k2);
	}
	return 0;
}
