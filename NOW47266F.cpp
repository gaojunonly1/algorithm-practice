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

const int N1=500005;

int n;
char s[N1];
ll dp[N1][3][3];
/*
dp[L][i][j]
*/
void ad(ll &x,ll &y);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k,L,r;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%s",s+1);
	n=strlen(s+1);
	fz1(L,n) {
		switch(s[L]) {
			case 'a':
				dp[L][1][0]=1;
				dp[L][0][0]=dp[L][0][1]=dp[L][0][2]=0;
				fz0k(i,3) {
					ad(dp[L][1][i],dp[L-1][2][i]);
					ad(dp[L][1][i],dp[L-1][0][i]);
					ad(dp[L][2][i],dp[L-1][1][i]);
				}
				break;
			case 'c':
				dp[L][0][0]=1;
				ad(dp[L][0][0],dp[L-1][0][0]);
				ad(dp[L][1][1],dp[L-1][1][0]);
				ad(dp[L][2][2],dp[L-1][2][0]);
				ad(dp[L][1][2],dp[L-1][1][1]);
				ad(dp[L][1][1],dp[L-1][1][2]);
				ad(dp[L][2][1],dp[L-1][2][1]);
				ad(dp[L][2][2],dp[L-1][2][2]);
				break;
			default:
				dp[L][0][0]=1;
				fz0k(i,3) {
					fz0k(j,3) {
						ad(dp[L][i][j],dp[L-1][i][j]);
					}
				}
				break;
		}
	}
	ll syf=0;
	fz1(i,n) {
		ad(syf,dp[i][1][2]);
		ad(syf,dp[i][2][2]);
	}
	printf("%lld\n",syf);
    return 0;
}

void ad(ll &x,ll &y) {
	x=x+y;
}
