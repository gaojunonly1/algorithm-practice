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

const int N1=105;

int a[N1],mn[N1];

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%d",&a[i]);
	}
	mn[n]=a[n];
	fd1(i,n-1) {
		if(a[i]>mn[i+1]) {
			set<int>syf;
			fz(j,i,n) {
				syf.insert(a[j]);
			}
			fz1(j,i-1) {
				printf("%d ",a[j]);
			}
			auto itr=syf.lower_bound(a[j]);
			itr--;
			printf("%d ",*itr);
			vector<int>gj;
			ff(syf,it) {
				if(it==itr)
					continue;
				gj.pb(*it);
			}
			reverse(gj.begin(),gj.end());
			ff(gj,it) {
				printf("%d ",*it);
			}
			break;
		}
		mn[i]=min(mn[i+1],a[i]);
	}
    return 0;
}
