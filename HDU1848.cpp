#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int f[1005];
int SG[1005];
int solve(int n);
int main() {
	int i;
	f[1]=1; f[2]=2;
	for(i=3;;i++) {
		f[i]=f[i-2]+f[i-1];
		if(f[i]>1000)
			break;
	}
	fill(SG,SG+1000,-1);
	SG[0]=0;
	while(true) {
		int m,n,p;
		scanf("%d%d%d",&m,&n,&p);
		if(0==m&&0==n&&0==p)
			break;
		m=solve(m);
		n=solve(n);
		p=solve(p);
		if(m^n^p)
			printf("Fibo\n");
		else
			printf("Nacci\n");
	}
    return 0;
}
int solve(int x) {
	if(-1!=SG[x])
		return SG[x];
	bool vis[1005];
	memset(vis,0,sizeof vis);
	for(int i=1;;i++) {
		if(f[i]>x)
			break;
		vis[solve(x-f[i])]=1;
	}
	for(int i=0;i<=1000;i++)
		if(0==vis[i])
			return SG[x]=i;
}
