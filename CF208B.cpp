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

int a[55];
int dp[55][60][60][60];
bool judge(int p,int q);
bool dfs(int cs,int aa,int bb,int cc);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d\n",&n);
	fz1(i,n) {
		char ch1=' ',ch2=' ';
		while(ch1==' ')
			ch1=getchar();
		while(ch2==' ')
			ch2=getchar();
		o=0;
		if(isdigit(ch1)) {
			o+=(ch1-'0')*4;
		}
		else {
			switch(ch1) {
				case 'T':
					o+=40;
					break;
				case 'J':
					o+=44;
					break;
				case 'Q':
					o+=48;
					break;
				case 'K':
					o+=52;
					break;
				case 'A':
					o+=4;
					break;
				default:
					break;
			}
		}
		switch(ch2) {
			case 'S':
				o=o+0;
				break;
			case 'D':
				o=o+1;
				break;
			case 'H':
				o=o+2;
				break;
			case 'C':
				o=o+3;
				break;
			default:
				break;
		}
		a[i]=o;
	}
	if(n<3) {
		if(n==2) {
			if(judge(a[n],a[n-1])) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			printf("YES\n");
		}
		return 0;
	}
	memset(dp,-1,sizeof dp);
	bool wwx=dfs(n,a[n],a[n-1],a[n-2]);
	wwx?printf("YES\n"):printf("NO\n");
    return 0;
}
bool dfs(int cs,int aa,int bb,int cc) {
	if(-1!=dp[cs][aa][bb][cc])
		return dp[cs][aa][bb][cc];
	if(cs==3) {
//		cout<<aa<<" "<<bb<<" "<<cc<<endl;
		if(judge(aa,bb)&&judge(aa,cc)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool jyl=0;
//	cout<<aa<<" "<<bb<<" "<<a[cs-3]<<" "<<judge(aa,bb)<<" "<<judge(aa,a[cs-3])<<endl;
	if(judge(aa,bb)) {
		jyl|=dfs(cs-1,aa,cc,a[cs-3]);
	}
	if(judge(aa,a[cs-3])) {
		jyl|=dfs(cs-1,bb,cc,aa);
	}
//	cout<<cs<<" "<<jyl<<endl;
	return dp[cs][aa][bb][cc]=jyl;
}
bool judge(int p,int q) {
	if(p%4==q%4||p/4==q/4) {
		return 1;
	}
	return 0;
}
