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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const char al='\n';

const ll Mod=1000000007;

vector<int>G[100005];
ll p[60005];
ll sz[100005];
ll jyl[100005]; 

void dfs(int,int);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	int i;
	int T,n,m;
	cin>>T;
	while(T--) {
		cin>>n;
		fz1(i,n) {
			G[i].clear();
			sz[i]=0;
		}
		fz1(i,n-1) {
			int u,v;
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		cin>>m;
		fz1(i,m) {
			cin>>p[i];
		}
		dfs(1,0);
		*jyl=0;
		fz(i,2,n) {
			jyl[++*jyl]=sz[i]*(n-sz[i]);
		}
		sort(jyl+1,jyl+(*jyl)+1,[&](const ll &pp,const ll &qq) {
			return pp>qq;
		});
		sort(p+1,p+m+1,[&](const ll &pp,const ll &qq) {
			return pp>qq;
		});
		ll wwx=0;
		if(m<n) {
			fz1(i,n-1) {
				if(i<=m) {
					(wwx+=jyl[i]*p[i]%Mod)%=Mod;
				}
				else {
					(wwx+=jyl[i])%=Mod;
				}
			}
		}
		else {
			fz1(i,n-2) {
				(wwx+=jyl[n-i]*p[m-i+1]%Mod)%=Mod;
			}
			ll tmp=1;
			fz1(i,m-n+2) {
				tmp=tmp*p[i]%Mod;
			}
			(wwx+=tmp*jyl[1])%=Mod;
		}
		cout<<wwx<<endl;
	}

    return 0;
}

void dfs(int u,int fa) {
	sz[u]=1;
	ff(G[u],itr) {
		if(*itr==fa) {
			continue;
		}
		dfs(*itr,u);
		sz[u]+=sz[*itr];
	}
}
