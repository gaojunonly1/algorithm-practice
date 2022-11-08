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

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	string s;
	int n,m;
	map<string,bool>gj;
	scanf("%d",&n);
	fz1(i,n) {
		fz1(j,5) {
			cin>>s;
			gj[s]=1;
		}
	}
	int syf[10];
	scanf("%d",&m);
	int jyl=0;
	fz1(i,m) {
		cin>>s;
		scanf("%d",&o);
		if(gj[s]) {
			jyl++;
		}
		syf[o]++;
	}
	fz1(i,5) {
		jyl=min(jyl,syf[i]);
	}
	printf("%d\n",jyl);
    return 0;
}
