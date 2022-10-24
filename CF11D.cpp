#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const int N1=20;
int n,m;
vector<int>G[N1];
ll dp[1<<N1][N1];
int bin[N1];

#define lowbit(x) ((x)&(-x))

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	scanf("%d%d",&n,&m);
	fz1(i,m) {
		scanf("%d%d",&p,&q);
		p--;
		q--;
		G[p].pb(q);
		G[q].pb(p);
	}
	bin[0]=1;
	fz1(i,n) {
		bin[i]=bin[i-1]<<1;
	}
	fz0k(i,n) {
		dp[bin[i]][i]=1;
	}
	ll wwx=0;
	fz1(i,bin[n]-1) {
		fz0k(j,n) {
			if(0==dp[i][j])
				continue;
			ff(G[j],itr) {
				int v=*itr;
				if(lowbit(i)>bin[v])
					continue;
				if(bin[v]&i) {
					if(lowbit(i)==bin[v]) {
						wwx+=dp[i][j];
					}
				}
				else {
					dp[i|bin[v]][v]+=dp[i][j];
				}
			}
		}
	}
	printf("%lld\n",(wwx-m)/2);
    return 0;
}
