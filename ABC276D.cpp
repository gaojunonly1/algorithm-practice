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

const int N1=1005;

int a[N1];
int syf[N1],gj[N1]; 

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	scanf("%d",&n);
	pp=iinf;
	qq=iinf;
	int c1=0,c2=0;
	fz1(i,n) {
		scanf("%d",&a[i]);
		while(a[i]%2==0) {
			syf[i]++;
			a[i]/=2;
		}
		while(a[i]%3==0) {
			gj[i]++;
			a[i]/=3;
		}
		pp=min(pp,syf[i]);
		qq=min(qq,gj[i]);
		c1+=syf[i];
		c2+=gj[i];
	}
	fz(i,2,n) {
		if(a[i]!=a[i-1]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",c1-pp*n+c2-qq*n);

    return 0;
}
