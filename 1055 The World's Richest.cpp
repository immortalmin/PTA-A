#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct Info{
	char name[20];
	int age,money;
}info;
vector<Info>v1;
bool mysort1(Info a,Info b){
	if(a.money!=b.money) return a.money>b.money;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<=0;//char数组排序 
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",&info.name,&info.age,&info.money);
		v1.push_back(info);
	}
	sort(v1.begin(),v1.end(),mysort1);
	int num,l,r;
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&num,&l,&r);
		printf("Case #%d:\n",i+1);
		int flag=0;
		for(int j=0;j<v1.size();j++){
			if(v1[j].age>=l&&v1[j].age<=r){
				flag=1;
//				strcpy(c,v1[j].name.c_str());//string转char数组 
				printf("%s %d %d\n",v1[j].name,v1[j].age,v1[j].money);
				num--;
				if(num==0) break;
			}
		}
		if(flag==0){
			printf("None\n");
			continue;
		}
	}
	return 0;
}
