#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct DSU {
	int n;
	int f[1000005],g[1000005];
	DSU() {
		n=0;
	}
	DSU(int oo) {
		n=oo;
		for(int i=1;i<=n;i++) {
			f[i]=i;
			g[i]=1;
		}
	}
	void Init(int oo) {
		n=oo;
		for(int i=1;i<=n;i++) {
			f[i]=i;
			g[i]=1;
		}
	}
	int Find(int x) {
		if(x==f[x])
			return x;
		int oo=f[x];
		f[x]=Find(f[x]);
		return f[x];
	}
	void Merge(int x,int y) {
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy) {
			f[fx]=fy;
			g[fy]+=g[fx];
		}
	}
}D;
int n,m;
ll k;
bool vis[1005][1005];
int tot=0;
bool jyl[1005][1005];
ll b[1005][1005];
int wwx[1005][1005];
struct node {
	int id;
	ll num;
	int x,y;
	bool operator<(const node tmp)const {
		return num<tmp.num;
	}
}a[1000005];
bool cmpnum(node pp,node qq);
void solve(int sx,int sy,ll num);
void dfs(int x,int y,ll num);
int main() {
	int i,j;
	int oo,pp,qq;
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			scanf("%lld",&a[(i-1)*m+j].num);
			b[i][j]=a[(i-1)*m+j].num;
			a[(i-1)*m+j].id=(i-1)*m+j;
			a[(i-1)*m+j].x=i;
			a[(i-1)*m+j].y=j;
		}
	}
	sort(a+1,a+n*m+1);
	D.Init(n*m);
	for(i=n*m;i>=1;i--) {
		pp=a[i].x;
		qq=a[i].y;
		vis[pp][qq]=1;
		for(j=0;j<4;j++) {
			int p1=pp+dx[j],q1=qq+dy[j];
			if(p1<1||q1<1||p1>n||q1>m||0==vis[p1][q1])
				continue;
			D.Merge(a[i].id,(p1-1)*m+q1);
		}
		oo=D.Find(a[i].id);
		if(a[i].num==0||k%a[i].num||D.g[oo]*a[i].num<k)
			continue;
		printf("YES\n");
		solve(pp,qq,a[i].num);
		return 0;
	}
	printf("NO\n");
    return 0;
}
bool cmpnum(node pp,node qq) {
	return pp.num<qq.num;
}
void solve(int sx,int sy,ll num) {
	memset(jyl,0,sizeof jyl);
	memset(wwx,0,sizeof wwx); 
	tot=k/num;
	dfs(sx,sy,num);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(wwx[i][j])
				printf("%d ",num);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
void dfs(int x,int y,ll num) {
	if(!tot)
		return;
	if(b[x][y]<num)
		return;
	jyl[x][y]=1;
	if(b[x][y]>=num&&!wwx[x][y]) {
		wwx[x][y]=1;
		tot--;
	}
	for(int i=0;i<4;i++) {
		int x1=x+dx[i],y1=y+dy[i];
		if(x1<1||y1<1||x1>n||y1>m||jyl[x1][y1])
			continue;
		dfs(x1,y1,num);
	}
}
