#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const int N1=100005;
int n;
int a[N1];
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	o=0;
	for(i=n;i>=1;i--) {
		if(a[i]==0) {
			o++;
		}
		else {
			break;
		}
	}
	if(o==0) {
		printf("NO\n");
		return 0;
	}
	if(o==1) {
		printf("YES\n");
		for(i=1;i<n;i++)
			printf("%d->",a[i]);
		printf("%d\n",a[n]);
		return 0;
	}
	if(o==2) {
		int pos=-1;
		for(i=n-o;i>=1;i--) {
			if(a[i]==0) {
				pos=i;
				break;
			}
		}
		if(pos==-1) {
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(i=1;i<pos;i++) {
			printf("%d->",a[i]);
		}
		for(i=pos;i<n-1;i++) {
			printf("(%d->",a[i]);
		}
		printf("%d",a[n-1]);
		for(i=1;i<=n-1-pos;i++) {
			printf(")");
		}
		printf("->%d\n",a[n]);
	}
	else {
		printf("YES\n");
		for(i=1;i<=n-o;i++) {
			printf("%d->",a[i]);
		}
		for(i=n-o+1;i<n-1;i++) {
			printf("(%d->",a[i]);
		}
		printf("%d",a[n-1]);
		for(i=1;i<=o-2;i++) {
			printf(")");
		}
		printf("->%d\n",a[n]);
	}
    return 0;
}
