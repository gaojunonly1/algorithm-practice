#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,K,sx,sy,tx,ty;
struct node {
	int x[2],y[2];
}qiang[20];
int dt[20][20];
int heng[20][20],shu[20][20];
void solve();
bool check(int zt);
int popcount(int zt);
bool dfs(int x,int y);
int main() {
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
    return 0;
}
void solve() {
	int i,j,k;
	cin>>n>>m>>K;
	cin>>sx>>sy>>tx>>ty;
	for(i=0;i<K;i++) {
		cin>>qiang[i].x[0]>>qiang[i].y[0]>>qiang[i].x[1]>>qiang[i].y[1];
		if(qiang[i].x[0]==qiang[i].x[1]&&qiang[i].y[0]>qiang[i].y[1])
			swap(qiang[i].y[0],qiang[i].y[1]);
		if(qiang[i].y[0]==qiang[i].y[1]&&qiang[i].x[0]>qiang[i].x[1])
			swap(qiang[i].x[0],qiang[i].x[1]);
	}
	int wwx=K;
	vector<int>dp((1<<K)+5,0);
	for(i=0;i<(1<<K);i++) {
		if(dp[i])
			continue;
		dp[i]=check(i);
		if(1==dp[i]) {
			wwx=min(wwx,popcount(i));
			for(j=0;j<K;j++)
				dp[i|(1<<j)]|=dp[i];
		}
	}
	cout<<wwx<<endl;
}
bool check(int zt) {
	memset(dt,0,sizeof dt);
	memset(heng,0,sizeof heng);
	memset(shu,0,sizeof shu);
	for(int i=0;i<K;i++) {
		if(0==((1<<i)&zt)) {
			if(qiang[i].x[0]==qiang[i].x[1]) {
				for(int j=qiang[i].y[0];j<qiang[i].y[1];j++)
					heng[qiang[i].x[0]][j]=1;
			}
			else {
				for(int j=qiang[i].x[0];j<qiang[i].x[1];j++)
					shu[j][qiang[i].y[0]]=1;
			}
		}
	}
	return dfs(sx,sy);
}
int popcount(int zt) {
	int wwx=0;
	while(zt) {
		if(zt&1)
			wwx++;
		zt>>=1;
	}
	return wwx;
}
bool dfs(int x,int y) {
	dt[x][y]=1;
	if(x==tx&&y==ty)
		return 1;
	bool wwx=0;
	if(x>=1&&0==heng[x][y]&&0==dt[x-1][y])
		wwx|=dfs(x-1,y);
	if(x+1<n&&0==heng[x+1][y]&&0==dt[x+1][y])
		wwx|=dfs(x+1,y);
	if(y>=1&&0==shu[x][y]&&0==dt[x][y-1])
		wwx|=dfs(x,y-1);
	if(y+1<m&&0==shu[x][y+1]&&0==dt[x][y+1])
		wwx|=dfs(x,y+1);
	return wwx;
}
