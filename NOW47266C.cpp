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

static char buf[1000000],*p1=buf,*p2=buf,obuf[1000000],*p3=obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
template<typename item>
inline void read(register item &x){
    x=0;register int f=1;register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=f;
}
template<typename item>
inline void uread(register item &x){
    x=0;register char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
static char cc[20];
template<typename item>
inline void print(register item x){ 
	register int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)cc[len++]=x%10+'0',x/=10;
	while(len--)putchar(cc[len]);
}
template<typename item>
inline void uprint(register item x){ 
	register int len=0;
	while(x)cc[len++]=x%10+'0',x/=10;
	while(len--)putchar(cc[len]);
}

const int N1=100005;
const int M1=1005;

int n;
int a[N1],b[N1];
int prim[M1],notp[M1];
bool jyl[1000005];

void oula(int nn);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	oula(M1-5);
	read(n);
	fz1(i,n) {
		read(a[i]);
		fz1(j,*prim) {
			if(a[i]%prim[j]==0) {
				jyl[prim[j]]=1;
				while(a[i]%prim[j]==0) {
					a[i]/=prim[j];
				}
			}
		}
		if(a[i]>1) {
			jyl[a[i]]=1;
		}
	}
	fz1(i,n) {
		read(b[i]);
		fz1(j,*prim) {
			if(b[i]%prim[j]==0) {
				if(jyl[prim[j]]==1) {
					printf("No\n");
					return 0;
				}
				while(b[i]%prim[j]==0) {
					b[i]/=prim[j];
				}
			}
		}
		if(b[i]>1) {
			if(jyl[b[i]]==1) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");

	fwrite(obuf,p3-obuf,1,stdout);
    return 0;
}

void oula(int nn) {
	int i,j;
	fz(i,2,nn) {
		if(!notp[i]) {
			prim[++*prim]=i;
		}
		fz1(j,*prim) {
			if(i*prim[j]>nn||i%prim[j]==0) {
				break;
			}
			notp[i*prim[j]]=1;
		}
	}
}
