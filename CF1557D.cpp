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

const int N1=300005;

int tot=0;
int head[N1],Next[N1<<1],to[N1<<1];
void add(int u,int v);
void add_edge(int u,int v);

struct node {
	int id,l,r;
	bool operator<(const node tmp)const {
		return id<tmp.id;
	}
}a[N1];
int b[N1<<1];
int S[N1];
vector<int>S1[N1<<1],S2[N1<<1];
bool check(node pp,node qq);

bool vis[N1];
int dist[N1];
int pre[N1];
void dfs(int u);

bool islj[N1];

int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,m;
	scanf("%d%d",&n,&m);
	fz1(i,m) {
		scanf("%d%d%d",&a[i].id,&a[i].l,&a[i].r);
		b[++*b]=a[i].l;
		b[++*b]=a[i].r;
	}
	sort(b+1,b+*b+1);
	int nn=unique(b+1,b+*b+1)-b-1;
	sort(a+1,a+m+1);
	fz1(i,m) {
		a[i].l=lower_bound(b+1,b+nn+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+nn+1,a[i].r)-b;
		S1[a[i].l].pb(a[i].id);
		S2[a[i].r+1].pb(a[i].id);
	}
	
	set<int>lwj;
	memset(S,0,sizeof S);
	fz1(i,nn) {
		ff(S2[i],itr) {
			S[*itr]--;
			if(S[*itr]==0) {
				lwj.erase(*itr);
			}
		}
		ff(S1[i],itr) {
			S[*itr]++;
			if(S[*itr]==1) {
				if(lwj.size()) {
					auto it=lwj.lower_bound(*itr);
					if(it!=lwj.end()) {
						add(*itr,*it);
					}
					if(it!=lwj.begin()) {
						it--;
						add(*it,*itr);
					}
				}
				lwj.insert(*itr);
			}
		}
	}
	
	int jyl=1;
	fd1(i,n) {
		dist[i]=1;
		pre[i]=i;
		for(j=head[i];j!=0;j=Next[j]) {
			if(dist[to[j]]+1>dist[i]) {
				dist[i]=dist[to[j]]+1;
				pre[i]=to[j];
			}
		}
		if(dist[i]>dist[jyl]) {
			jyl=i;
		}
	}
	vector<int>wwx;
	o=jyl;
	islj[o]=1;
	while(pre[o]!=o) {
		o=pre[o];
		islj[o]=1;
	}
	fz1(j,n) {
		if(!islj[j]) {
			wwx.pb(j);
		}
	}
	printf("%d\n",wwx.size());
	ff(wwx,itr) {
		printf("%d ",*itr);
	}
	printf("\n");
    return 0;
}
bool check(node pp,node qq) {
	if(pp.l>qq.l)
		swap(pp,qq);
	return (pp.r>=qq.l)?1:0;
}
void add(int u,int v) {
	if(u==v)
		return;
	Next[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void add_edge(int u,int v) {
	add(min(u,v),max(u,v));
}
