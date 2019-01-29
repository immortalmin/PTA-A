#include<iostream>
#include<string>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	int a[55];
	string b[55],c[55];
	cin>>n;
	for(int i=1;i<=54;i++){
		cin>>a[i];
	}
	b[1]="S1",b[2]="S2",b[3]="S3",b[4]="S4",b[5]="S5",b[6]="S6",b[7]="S7",b[8]="S8",b[9]="S9",b[10]="S10",b[11]="S11",b[12]="S12",b[13]="S13"; 
	b[14]="H1",b[15]="H2",b[16]="H3",b[17]="H4",b[18]="H5",b[19]="H6",b[20]="H7",b[21]="H8",b[22]="H9",b[23]="H10",b[24]="H11",b[25]="H12",b[26]="H13";
	b[27]="C1",b[28]="C2",b[29]="C3",b[30]="C4",b[31]="C5",b[32]="C6",b[33]="C7",b[34]="C8",b[35]="C9",b[36]="C10",b[37]="C11",b[38]="C12",b[39]="C13";
	b[40]="D1",b[41]="D2",b[42]="D3",b[43]="D4",b[44]="D5",b[45]="D6",b[46]="D7",b[47]="D8",b[48]="D9",b[49]="D10",b[50]="D11",b[51]="D12",b[52]="D13";
	b[53]="J1",b[54]="J2";
	while(n--){
		for(int i=1;i<=54;i++){
			c[a[i]]=b[i];
		}
		for(int i=1;i<=54;i++) b[i]=c[i];
	}
	for(int i=1;i<=54;i++){
		if(i!=1) cout<<" ";
		cout<<b[i];
	}
	cout<<endl;
	return 0;
}
