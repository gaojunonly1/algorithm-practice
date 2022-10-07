#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
char s[1505];
int n,m;
int sx,sy;
bool qiang[1505][1505];
int jyl[1505][1505][2];
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
bool wwx=0;
void dfs(int x,int y);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	memset(qiang,0,sizeof qiang);
	for(i=0;i<n;i++) {
		scanf("%s",s);
		for(j=0;j<m;j++) {
			if(s[j]=='#')
				qiang[i][j]=1;
			else if(s[j]=='S')
				sx=i,sy=j;
		}
	}
	memset(jyl,-1,sizeof jyl);
	dfs(sx,sy);
	wwx?printf("Yes\n"):printf("No\n");
    return 0;
}
void dfs(int x,int y) {
	if(wwx)
		return;
	int i;
	int x1=(x%n+n)%n,y1=(y%m+m)%m;
	if(-1==jyl[x1][y1][0]&&-1==jyl[x1][y1][1]) {
		jyl[x1][y1][0]=x;
		jyl[x1][y1][1]=y;
	}
	else if(jyl[x1][y1][0]!=x||jyl[x1][y1][1]!=y) {
		wwx=1;
		return;
	}
	else {
		return;
	}
	for(i=0;i<4;i++) {
		x+=dx[i];
		y+=dy[i];
		x1=(x%n+n)%n;
		y1=(y%m+m)%m;
		if(0==qiang[x1][y1])
			dfs(x,y);
		x-=dx[i];
		y-=dy[i];
	}
}
