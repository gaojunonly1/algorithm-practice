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

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("test.in","r",stdin);
//#endif

	int i;
	ll N,X;
	cin>>N>>X;
	vector<ll>A;
	map<ll,bool>jyl;
	fz1(i,N) {
		ll oo;
		cin>>oo;
		A.pb(oo);
		jyl[oo]=1;
	}
	ff(A,itr) {
		if(jyl[(*itr)-X]) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");

    return 0;
}
