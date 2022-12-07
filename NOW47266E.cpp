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

const int N1=10000005;

int gj=0,syf[N1],cf[N1],jyl[N1];

void modify(int *a,int l,int r,int v);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n,m;
	scanf("%d%d",&n,&m);
	int opt,x,ws;
	fz1(i,m) {
		scanf("%d%d",&opt,&x);
		switch(opt) {
			case 1:
				ws=0;
				while(x<=n) {
					if(x<=n) {
						modify(cf,x,min(n,x+(1<<ws)-1),1);
					}
					x<<=1;
					ws++;
				}
				break;
			case 2:
				gj++;
				ws=0;
				while(x<=n) {
					if(x<=n) {
						modify(cf,x,min(n,x+(1<<ws)-1),-1);
					}
					x<<=1;
					ws++;
				}
				break;
			case 3:
				while(x>0) {
					syf[x]++;
					x>>=1;
				}
				break;
			case 4:
				gj++;
				while(x>0) {
					syf[x]--;
					x>>=1;
				}
				break;
		}
	}
	fz1(i,n) {
		cf[i]=cf[i-1]+cf[i];
		syf[i]+=cf[i];
		syf[i]+=gj;
	}
	fz1(i,n) {
		jyl[syf[i]]++;
	}
	fz0g(i,m) {
		printf("%d ",jyl[i]);
	}
	printf("\n");
	
    return 0;
}

void modify(int *a,int l,int r,int v) {
	a[l]+=v;
	a[r+1]-=v;
}
