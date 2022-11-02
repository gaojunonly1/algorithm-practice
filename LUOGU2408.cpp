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

const int LEN=1000005;

char s[LEN];

class SA {
public:
	SA() {
	}
	void Init(char *s1) {
		int i;
		s=s1;
		n=strlen(s+1);
		m=(int)'z';
		fz1(i,n) {
			x[i]=s[i];
		}
	}
	void GetSA() {
		int i,bin;
		fz1(i,n) {
			buc[x[i]]++;
		}
		fz(i,2,m) {
			buc[i]+=buc[i-1];
		}
		fd1(i,n) {
			sa[buc[x[i]]--]=i;
		}
		for(bin=1;bin<=n;bin<<=1) {
			int num=0;
			fz(i,n-bin+1,n) {
				y[++num]=i;
			}
			fz1(i,n) {
				if(sa[i]>bin) {
					y[++num]=sa[i]-bin;
				}
			}
			fill(buc+1,buc+m+1,0);
			fz1(i,n) {
				buc[x[i]]++;
			}
			fz(i,2,m) {
				buc[i]+=buc[i-1];
			}
			fd1(i,n) {
				sa[buc[x[y[i]]]--]=y[i];
				y[i]=0;
			}
			swap(x,y);
			num=1;
			x[sa[1]]=1;
			fz(i,2,n) {
				int pp=sa[i]+bin<=n?y[sa[i]+bin]:0;
				int qq=sa[i-1]+bin<=n?y[sa[i-1]+bin]:0;
				if(y[sa[i]]==y[sa[i-1]]&&pp==qq) {
					x[sa[i]]=num;
				}
				else {
					x[sa[i]]=++num;
				}
			}
			m=num;
		}
	}
	void GetLCP() {
		int i,j,k=0;
		fz1(i,n) {
			rk[sa[i]]=i;
		}
		fz1(i,n) {
			if(rk[i]==1) {
				height[1]=0;
				continue;
			}
			if(k) {
				k--;
			}
			j=sa[rk[i]-1];
			while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) {
				k++;
			}
			height[rk[i]]=k;
		}
	}
	void Solve() {
		int i;
		GetSA();
		GetLCP();
		ll syf=1ll*(n+1)*n/2;
		fz1(i,n) {
			syf=syf-1ll*height[i];
		}
		printf("%lld\n",syf);
	}
private:
	char *s;
	int n,m;
	int x[LEN],y[LEN],buc[LEN],sa[LEN];
	//buc是一个桶
	//sa[i]表示字典序第i的后缀的首字母的位置
	//x[i]表示第i个
	int rk[LEN],height[LEN];
};

SA S1;

int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	scanf("%d",&o);
	scanf("%s",s+1);
	S1.Init(s);
	S1.Solve();
    return 0;
}
