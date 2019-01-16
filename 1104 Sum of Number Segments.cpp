#include<iostream>
#include<cstdio>
using namespace std;
double a[100001];
int main()
{
	int n;
	cin>>n;
	double sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
		sum+=(i+1)*a[i]*(n-i);
	}
	printf("%.2lf\n",sum); 
}
