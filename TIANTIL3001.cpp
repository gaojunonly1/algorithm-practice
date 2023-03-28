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

const char al='\n';

int a[10005];
bool dp[10005][105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	int i,j;
	int n,m;
	cin>>n>>m;
	fz1(i,n) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	memset(dp,0,sizeof dp);
	dp[n][a[n]]=1;
	dp[n][0]=1;
	dp[n+1][0]=1;
	fd1(i,n-1) {
		fd0g(j,m) {
			dp[i][j]|=dp[i+1][j];
			if(j+a[i]<=m) {
				dp[i][j+a[i]]|=dp[i+1][j];
			}
		}
	}
	if(!dp[1][m]) {
		cout<<"No Solution"<<al;
		return 0; 
	}
	vector<int>wwx(0);
	fz1(i,n) {
		if(m>=a[i]) {
			if(dp[i+1][m-a[i]]) {
				wwx.pb(a[i]);
				m-=a[i];
			}
		}
	}
	for(int i=0;i<wwx.size();i++) {
		cout<<wwx[i];
		if(i!=wwx.size()-1) {
			cout<<" ";
		}
	}
    return 0;
}
