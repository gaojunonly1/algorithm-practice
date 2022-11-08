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

const int N1=200005;

char s[N1];
int a[N1];

void solve();

int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}

    return 0;
}

void solve() {
	int i,j,k;
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	fz1(i,n) {
		scanf("%d",&a[i]);
	}
	bool bo=0; 
	int syf=0;
	priority_queue<int,vector<int>,greater<int>>heap;
	fz1(i,n) {
		if(s[i]=='0') {
			if(i<n&&s[i+1]=='1') {
				bo=1;
				syf+=a[i];
				heap.push(a[i]);
			}
		}
		else {
			syf+=a[i];
			heap.push(a[i]);
			if(i==n||s[i+1]=='0') {
				if(bo) {
					syf-=heap.top();
					bo=0;
				}
				while(!heap.empty()) {
					heap.pop();
				}
			}
		}
	}
	printf("%d\n",syf);
}
