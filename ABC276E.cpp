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

const int N1=10000005;

int dx[]={0,0,-1,1},dy[]={1,-1,0,0};

int n,m;

vector<char> ditu[N1];
vector<int> syf[N1];
vector<int> vis[N1];

void bfs(int sx,int sy);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%d%d",&n,&m);
	fz1(i,n) {
		ditu[i].resize(m+1);
		syf[i].resize(m+1);
		vis[i].resize(m+1);
		fz1(j,m) {
			syf[i][j]=0;
			char ch=' ';
			while(ch!='S'&&ch!='.'&&ch!='#') {
				ch=getchar();
			}
			ditu[i][j]=ch;
			if(ditu[i][j]=='S') {
				pp=i;
				qq=j;
			}
		}
	}
//	puts("23333");
	fz0k(i,4) {
		int nx=pp+dx[i],ny=qq+dy[i];
		if(nx<1||ny<1||nx>n||ny>m)
			continue;
		if(ditu[nx][ny]=='.') {
			bfs(nx,ny);
		}
	}
	fz1(i,n) {
		fz1(j,m) {
			if(ditu[i][j]!='.')
				continue;
			if(syf[i][j]>=2) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
    return 0;
}

void bfs(int sx,int sy) {
//	cout<<"sx="<<sx<<" "<<"sy="<<sy<<endl;
	int i,j;
	queue<pii>que;
	fz1(i,n) {
		fz1(j,m) {
			vis[i][j]=0;
		}
	}
	que.push(mp(sx,sy));
	syf[sx][sy]++;
	vis[sx][sy]=1;
	while(!que.empty()) {
		pii tmp=que.front();
		fz0k(i,4) {
			int nx=tmp.fi+dx[i],ny=tmp.se+dy[i];
			if(nx<1||ny<1||nx>n||ny>m)
				continue;
			if(ditu[nx][ny]!='.'||vis[nx][ny])
				continue;
			vis[nx][ny]=1;
			syf[nx][ny]++;
			que.push(mp(nx,ny));
		}
		que.pop();
	}
}
