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

const int N1=505;
const int M1=250005;

class Graph {
public:
	Graph() {
	}
	Graph(int nn,int mm) {
		int i;
		tot=0;
		tim=0;
		n=nn;
		m=mm;
		fz1(i,n) {
			ex[i]=-inf;
			ey[i]=0;
		}
	}
	void Init(int nn) {
		int i;
		tot=0;
		tim=0;
		n=nn;
		fz1(i,n) {
			ex[i]=-inf;
			ey[i]=0;
		}
	}
	void Add(int x,int y,ll z) {
		ex[x]=max(ex[x],z);
		tot++;
		d1[tot]=y;
		d2[tot]=z;
		Next[tot]=head[x];
		head[x]=tot;
	}
	void Modify(int cur) {
		int x,lst;
		for(x=cur,lst;x;x=lst) {
			lst=mchx[pre[x]];
			mchx[pre[x]]=x;
			mchy[x]=pre[x];
		}
	}
	void Bfs(int cur) {
		int i;
		fz1(i,n) {
			slack[i]=inf;
			pre[i]=0;
		}
		l1=1;
		r1=0;
		que[++r1]=cur;
		tim++;
		for(;;) {
			while(l1<=r1) {
				int u=que[l1];
				l1++;
				visx[u]=tim;
				for(i=head[u];i;i=Next[i]) {
					int v=d1[i];
					ll w=d2[i];
					if(visy[v]==tim) {
						continue;
					}
					ll del=ex[u]+ey[v]-w;
					if(del<slack[v]) {
						slack[v]=del;
						pre[v]=u;
						if(!del) {
							visy[v]=tim;
							if(!mchy[v]) {
								Modify(v);
								return;
							}
							que[++r1]=mchy[v];
						}
					}
				}
			}
			ll del=inf;
			fz1(i,n) {
				if(visy[i]!=tim) {
					del=min(del,slack[i]);
				}
			}
			l1=1;
			r1=0;
			fz1(i,n) {
				if(visx[i]==tim) {
					ex[i]-=del;
				}
				if(visy[i]==tim) {
					ey[i]+=del;
				}
				else {
					slack[i]-=del;
				}
			}
			fz1(i,n) {
				if((visy[i]!=tim)&&(!slack[i])) {
					visy[i]=tim;
					if(!mchy[i]) {
						Modify(i);
						return;
					}
					que[++r1]=mchy[i];
				}
			}
		}
	}
	void KM() {
		int i;
		fz1(i,n) {
			Bfs(i);
		}
	}
	void Solve() {
		int i;
		KM();
		ll gj=0;
		fz1(i,n) {
			gj+=ex[i]+ey[i];
		}
		printf("%lld\n",gj);
	}
private:
	int n,m;
	ll ex[N1],ey[N1],slack[N1];
	int tot=0;
	int Next[M1],head[N1];
	int d1[M1];
	ll d2[M1];
	int pre[N1],visx[N1],visy[N1],mchx[N1],mchy[N1];
	int tim;
	int l1,r1,que[N1];
};

Graph G1;

struct node {
	ll a;
	ll p;
	bool operator<(const node tmp)const {
		return a<tmp.a;
	}
}alice[N1];

ll syf[N1],gj[N1];

ll bob1[N1],bob2[N1];

int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	int n,m;
	scanf("%d",&n);
	G1.Init(n);
	fz1(i,n) {
		scanf("%lld",&alice[i].a);
	}
	fz1(i,n) {
		scanf("%lld",&alice[i].p);
	}
	sort(alice+1,alice+n+1);
	fz1(i,n) {
		scanf("%lld",&bob1[i]);
	}
	fz1(i,n) {
		scanf("%lld",&bob2[i]);
	}
	ll jyl=0;
	int now=1;
	for(i=2;i<=n;i++) {
		if(alice[i].a!=alice[i-1].a) {
			fz(j,now,i-1) {
				jyl=jyl+alice[j].p;
			}
			fz(j,now,i-1) {
				syf[j]=jyl;
			}
			now=i;
		}
	}
	fz(i,now,n) {
		jyl=jyl+alice[i].p;
	}
	fz(i,now,n) {
		syf[i]=jyl;
	}
	fz1(i,n) {
		gj[i]=alice[i].a;
	}
	fz1(i,n) {
		fz1(j,n) {
			oo=bob1[i]+bob2[j];
			o=lower_bound(gj+1,gj+n+1,oo)-gj-1;
			G1.Add(i,j,syf[o]);
		}
	}
	G1.Solve();
    return 0;
}
