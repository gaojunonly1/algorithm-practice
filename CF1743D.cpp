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

const int N1=1000005;

char s[N1];
int a[N1],b[N1];

struct node {
	node() {}
	node(int nn) {
		int i;
		n=nn;
	}
	int n;
	int num[N1];
	bool operator<(const node tmp)const {
		int i;
		fz1(i,n) {
			if(num[i]!=tmp.num[i]) {
				return num[i]<tmp.num[i];
			}
		}
		return 0;
	}
}syf,gj;

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	fz1(i,n) {
		a[i]=s[i]-'0';
	}
	int nn=0;
	i=1;
	while(a[i]==0)
		i++;
	if(i>n) {
		printf("0\n");
		return 0;
	}
	fz(i,i,n) {
		a[++nn]=a[i];
	}
	n=nn;
	int m;
	fz1(i,n) {
		if(a[i]==0) {
			m=n-i+1;
			break;
		}
	}
	fz1(i,n) {
		b[i]=1;
	}
	fz1(i,m) {
		b[i+n-m]=a[i];
	}
	syf.n=gj.n=n;
	fz1(i,n) {
		syf.num[i]=a[i]|b[i];
	}
	fz(i,2,n-m) {
		fz1(j,m) {
			b[j+n-m]=a[i+j-1];
		}
//		printf("b=");
//		fz1(j,n) {
//			printf("%d",b[j]);
//		}
//		printf("\n");
		fz1(j,n) {
			gj.num[j]=a[j]|b[j];
		}
//		printf("gj=");
//		fz1(j,n) {
//			printf("%d",gj.num[j]);
//		}
//		printf("\n");
		if(syf<gj) {
			syf=gj;
		}
	}
	fz1(i,n) {
		printf("%d",syf.num[i]);
	}
	printf("\n");
    return 0;
}
