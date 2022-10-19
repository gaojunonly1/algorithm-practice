#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const int N1=1005;
int n;
int a[N1],wwx[N1];
int bin[15];
void ask(int pos,int o);
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	bin[0]=1;
	for(i=1;i<=10;i++)
		bin[i]=bin[i-1]<<1;
	memset(wwx,63,sizeof wwx);
	for(i=0;i<10&&bin[i]<=n;i++) {
		ask(i,0);
		ask(i,1);
	}
	printf("-1\n");
	for(i=1;i<=n;i++)
		printf("%d ",wwx[i]);
	printf("\n");
	fflush(stdout);
    return 0;
}
void ask(int pos,int o) {
	int i;
	vector<int>jyl;
	for(i=1;i<=n;i++) {
		if(((i&bin[pos])>>pos)!=o) {
			jyl.pb(i);
		}
	}
	printf("%d\n",jyl.size());
	for(auto oo:jyl)
		printf("%d ",oo);
	printf("\n");
	fflush(stdout);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(((i&bin[pos])>>pos)==o) {
			wwx[i]=min(wwx[i],a[i]);
		}
	}
}
