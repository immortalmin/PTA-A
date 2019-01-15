#include<iostream>
#include<cstdio>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	int a1,a2,b1,b2,c1,c2,a,b,c,k;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	c=(c1+c2)%29;
	k=(c1+c2)/29;
	b=(b1+b2+k)%17;
	k=(b1+b2+k)/17;
	a=a1+a2+k;
	cout<<a<<"."<<b<<"."<<c<<endl;
}
