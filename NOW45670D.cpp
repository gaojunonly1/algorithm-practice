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

const int N1=4005;

int n,m;
int a[N1][N1];
bool vis[N1][N1];
int dist[2][N1][N1];

int dx[]={0,0,-1,1},dy[]={1,-1,0,0};

void bfs(int sx,int sy,int opt);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int x;
	int sx,sy,ex,ey;
	scanf("%d%d%d",&n,&m,&x);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	fz1(i,n) {
		fz1(j,m) {
			scanf("%d",&a[i][j]);
		}
	}
	bfs(sx,sy,0);
	bfs(ex,ey,1);
	int syf=-1;
	fz1(i,n) {
		fz1(j,m) {
			if(a[i][j]<=x)
				continue;
//			cout<<i<<" "<<j<<" "<<dist[0][i][j]<<" "<<dist[1][i][j]<<endl;
			if(dist[0][i][j]!=-1&&dist[1][i][j]!=-1) {
				if(syf==-1) {
					syf=dist[0][i][j]+dist[1][i][j];
				}
				else {
					syf=min(syf,dist[0][i][j]+dist[1][i][j]);
				}
			}
		}
	}
	printf("%d\n",syf);
    return 0;
}


void bfs(int sx,int sy,int opt) {
	int i;
	memset(dist[opt],-1,sizeof dist[opt]);
	memset(vis,0,sizeof vis);
	queue<pii>que;
	dist[opt][sx][sy]=0;
	vis[sx][sy]=1;
	que.push(mp(sx,sy));
	while(!que.empty()) {
		pii tmp=que.front();
		fz0k(i,4) {
			int nx=tmp.fi+dx[i];
			int ny=tmp.se+dy[i];
			if(nx<1||ny<1||nx>n||ny>m)
				continue;
			if(vis[nx][ny]||a[nx][ny]==-1)
				continue;
			dist[opt][nx][ny]=dist[opt][tmp.fi][tmp.se]+1;
			vis[nx][ny]=1;
			que.push(mp(nx,ny));
		}
		que.pop();
	}
}
