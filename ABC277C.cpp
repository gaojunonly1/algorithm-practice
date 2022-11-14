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

const int N1=400005;

int a[N1];
map<int,int>pos;
vector<int>G[N1];
bool vis[N1];
vector<pii>jyl;

void bfs(int u);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	scanf("%d",&n);
	a[++*a]=1;
	fz1(i,n) {
		scanf("%d%d",&pp,&qq);
		jyl.pb(mp(pp,qq));
		a[++*a]=pp;
		a[++*a]=qq;
	}
	sort(a+1,a+*a+1);
	*a=unique(a+1,a+*a+1)-a-1;
	fz1(i,*a) {
		pos[a[i]]=i;
	}
	ff(jyl,itr) {
		pii tmp=*itr;
		pp=pos[tmp.fi];
		qq=pos[tmp.se];
		G[pp].pb(qq);
		G[qq].pb(pp);
	}
	bfs(1);
	fd1(i,*a) {
		if(vis[i]) {
			printf("%d\n",a[i]);
			break;
		}
	}
    return 0;
}

void bfs(int u) {
	queue<int>que;
	que.push(u);
	while(!que.empty()) {
		u=que.front();
		vis[u]=1;
		ff(G[u],itr) {
			int v=*itr;
			if(vis[v])
				continue;
			que.push(v);
		}
		que.pop();
	}
}
