#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
bool mark[200005];
int N,M;
struct dian{
	int x,y;
}P[2005];
struct bian {
	int s,a,b;
}A[2005*2005];
bitset<2005>jihe[2005];
bool cmp_bian(bian pp,bian qq);
void prepare();
void solve();
int main() {
	prepare();
	int T;
	cin>>T;
	while(T--)
		solve();
    return 0;
}
void prepare() {
	int i,j,k;
	mark[1]=1;
	for(i=2;i<=200000;i++) {
		if(mark[i])
			continue;
		for(j=i+i;j<=200000;j+=i)
			mark[j]=1;
	}
}
bool cmp_bian(bian pp,bian qq) {
	return pp.s<qq.s;
}
void solve() {
	int i,j,k;
	cin>>N>>M;
	for(i=1;i<=N;i++)
		jihe[i].reset();
	for(i=1;i<=N;i++)
		cin>>P[i].x>>P[i].y;
	int wwx=0,cnt=0;
	for(i=1;i<=N;i++)
		for(j=i+1;j<=N;j++)
			A[++cnt]=(bian){abs(P[i].x-P[j].x)+abs(P[i].y-P[j].y),i,j};
	sort(A+1,A+cnt+1,cmp_bian);
	for(i=1;i<=cnt;i++) {
		if(0==mark[A[i].s])
			wwx+=(jihe[A[i].a]^jihe[A[i].b]).count();
		jihe[A[i].a][A[i].b]=1;
		jihe[A[i].b][A[i].a]=1;
	}
	cout<<wwx<<endl;
}
