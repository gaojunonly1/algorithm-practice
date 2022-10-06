#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int m;
int bin[15];
int jyl;
int wwx[1055][1055];
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&m);
	bin[0]=1ll;
	for(i=1;i<=11;i++) {
		bin[i]=bin[i-1]<<1;
		if(bin[i]==m)
			jyl=i;
	}
	wwx[1][1]=wwx[1][2]=wwx[2][1]=1;
	wwx[2][2]=-1;
	for(i=2;i<=jyl;i++) {
		for(j=1;j<=bin[i-1];j++)
			for(k=1;k<=bin[i-1];k++) {
				wwx[j][k+bin[i-1]]=wwx[j][k]*-1;
				wwx[j+bin[i-1]][k]=wwx[j][k]*-1;
				wwx[j+bin[i-1]][k+bin[i-1]]=wwx[j][k]*-1;
			}
	}
	for(i=1;i<=m;i++,printf("\n"))
		for(j=1;j<=m;j++)
			printf("%d ",wwx[i][j]);
    return 0;
}
