#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int prim[100005];
bool notp[100005];
bool vis[100005];
vector<pii>wwx;
void oula(int n);
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	oula(n/2);
	for(i=*prim;i>=1;i--) {
//		cout<<"@@@  "<<prim[i]<<endl;
		vector<int>jyl;
		for(j=prim[i];j<=n;j+=prim[i]) {
			if(!vis[j]) {
				jyl.pb(j);
				vis[j]=1;
			}
		}
		int oo=jyl.size()-1;
		if(oo%2==0) {
			vis[jyl[1]]=0;
			swap(jyl[1],jyl[oo]);
			oo--;
		}
		for(j=0;j<oo;j+=2)
			wwx.pb(mp(jyl[j],jyl[j+1]));
	}
	printf("%d\n",wwx.size());
	for(auto oo:wwx)
		printf("%d %d\n",oo.fi,oo.se);
    return 0;
}
void oula(int n) {
	int i,j;
	for(i=2;i<=n;i++) {
		if(!notp[i])
			prim[++*prim]=i;
		for(j=1;j<=*prim&&prim[j]*i<=n;j++)
			notp[prim[j]*i]=1;
	}	
}
