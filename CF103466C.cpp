#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1101
ll a[M][M];
ll one[M][M],two[M][M],three[M][M],four[M][M]; 
int in[M][M],out[M][M];
int vis[M][M];
ll mod=1e9+7;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int n,m;
struct Point
{
	int x,y;
};
queue <Point> q;
struct B
{
	ll val;
	int x, y;
}b[M*M];
bool cmp(B b1,B b2)
{
	return b1.val<b2.val;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
			b[(i-1)*m+j]={a[i][j],i,j};
		}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		q.push({b[i].x,b[i].y});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!((a[i-1][j]==a[i][j]-1&&i>1)||(a[i+1][j]==a[i][j]-1&&i<n)||(a[i][j-1]==a[i][j]-1&&j>1)||(a[i][j+1]==a[i][j]-1&&j<m)))
				in[i][j]=1,one[i][j]=1;
			if(!((a[i-1][j]==a[i][j]+1&&i>1)||(a[i+1][j]==a[i][j]+1&&i<n)||(a[i][j-1]==a[i][j]+1&&j>1)||(a[i][j+1]==a[i][j]+1&&j<m)))
				out[i][j]=1;			
		}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			if(in[i][j])
//			{
//				q.push({i,j}),vis[i][j]=1;
//			}
	ll ans=0;
	while(!q.empty())
	{
		Point aa=q.front();
		q.pop();
		//vis[aa.x][aa.y]=0;
		for(int i=1;i<=4;i++)
		{
			int xx=aa.x;
			int yy=aa.y;
			if(a[xx+dx[i]][yy+dy[i]]==a[xx][yy]+1&&xx+dx[i]>=1&&xx+dx[i]<=n&&yy+dy[i]>=1&&yy+dy[i]<=m)
			{				
				four[xx+dx[i]][yy+dy[i]]+=three[xx][yy]+four[xx][yy];
				four[xx+dx[i]][yy+dy[i]]%=mod;
				three[xx+dx[i]][yy+dy[i]]+=two[xx][yy];
				three[xx+dx[i]][yy+dy[i]]%=mod;
				two[xx+dx[i]][yy+dy[i]]+=one[xx][yy];
				two[xx+dx[i]][yy+dy[i]]%=mod;
				//if(!vis[xx+dx[i]][yy+dy[i]])
				//	q.push({xx+dx[i],yy+dy[i]}),vis[xx+dx[i]][yy+dy[i]]=1;
			}
		}
		if(out[aa.x][aa.y])
			ans=(ans+four[aa.x][aa.y])%mod;
		one[aa.x][aa.y]=0,two[aa.x][aa.y]=0,three[aa.x][aa.y]=0,four[aa.x][aa.y]=0;
	}
	printf("%lld",ans%mod);
}
