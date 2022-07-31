#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,K;
ll dist[305][305];
int m;
int main() {
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>dist[i][j];
	cin>>K;
	vector<ll>jyl;
	while(K--) {
		int a,b;
		ll c;
		ll wwx=0;
		cin>>a>>b>>c;
		if(dist[a][b]<=c) {
			for(i=1;i<=n;i++)
				for(j=i+1;j<=n;j++)
					wwx+=dist[i][j];
			jyl.pb(wwx); 
			continue;
		}
		dist[a][b]=dist[b][a]=c;
		for(i=1;i<=n;i++)
			dist[i][a]=dist[a][i]=min(dist[i][a],dist[i][b]+dist[b][a]);
		for(i=1;i<=n;i++)
			dist[i][b]=dist[b][i]=min(dist[i][b],dist[i][a]+dist[a][b]);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				dist[i][j]=dist[j][i]=min(dist[i][j],min(dist[i][a]+dist[a][j],dist[i][b]+dist[b][j]));
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				wwx+=dist[i][j];
		jyl.pb(wwx); 
	}
	for(auto oo:jyl)
		cout<<oo<<" ";
    return 0;
}
