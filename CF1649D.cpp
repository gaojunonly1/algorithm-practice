#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
ll m,a[1000005];
int jfm[1000005];
bool wwx;
set<int>jyl;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,pp,qq;
	ll oo;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		memset(jfm,0,sizeof jfm);
		jyl.clear();
		for(i=1;i<=n;i++) {
			cin>>oo;
			jyl.insert(oo);
		}
		n=0;
		for(auto tmp:jyl) {
			a[++n]=tmp;
			jfm[tmp]=n;
		}
		jfm[m+1]=n+1;
		for(i=m;i>=1;i--)
			if(!jfm[i])
				jfm[i]=jfm[i+1];
		if(a[1]!=1) {
			puts("No");
			continue;
		}
		wwx=1;
		for(i=2;i<=n&&wwx;i++) {
			for(j=2;j*a[i]<=m&&wwx;j++) {
				pp=j*a[i]<=m?jfm[j*a[i]]:n+1;
				qq=(j+1)*a[i]<=m?jfm[(j+1)*a[i]]:n+1;
				if((pp!=qq)&&(a[jfm[j]]!=j)) {
					wwx=0;
					break;
				}
			}
		}
		wwx?puts("Yes"):puts("No");
	}
}
