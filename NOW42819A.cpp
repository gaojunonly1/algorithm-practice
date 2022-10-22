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
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const int N1=200005;
class DSU {
	public:
		int ans[N1];
		DSU() {
		}
		DSU(int nn) {
			n=nn;
			for(int i=1;i<=n;i++) {
				fa[i]=i;
				jyl[i].pb(i);
				ans[i]=-1;
			}
			ans[1]=0;
		}
		void Init(int nn) {
			n=nn;
			for(int i=1;i<=n;i++) {
				fa[i]=i;
				jyl[i].pb(i);
				ans[i]=-1;
			}
			ans[1]=0;
		}
		int Find(int x) {
			if(fa[x]==x) {
				return x;
			}
			else {
				return fa[x]=Find(fa[x]);
			}
		}
		void Merge(int x,int y,int tim) {
			int xx=Find(x),yy=Find(y);
			if(xx==yy)
				return;
//			cout<<"@@@  "<<x<<" "<<xx<<" "<<y<<' '<<yy<<endl;
			if(jyl[xx].size()>jyl[yy].size())
				swap(xx,yy);
			if(xx==Find(1)) {
				ff(jyl[yy],itr) {
					ans[*itr]=tim;
				}
			}
			else if(yy==Find(1)) {
				ff(jyl[xx],itr) {
					ans[*itr]=tim;
				}
			}
			fa[xx]=yy;
			ff(jyl[xx],itr) {
				jyl[yy].pb(*itr);
			}
		}
    private:
        int n;
		int fa[N1];
		vector<int>jyl[N1];
}D;
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,m1,m2;
	scanf("%d",&n);
	scanf("%d%d",&m1,&m2);
	D.Init(n);
	fz1(i,m1) {
		scanf("%d%d",&p,&q);
		D.Merge(p,q,0);
	}
	fz1(i,m2) {
		scanf("%d%d",&p,&q);
		D.Merge(p,q,i);
	}
	fz1(i,n) {
		printf("%d\n",D.ans[i]);
	}
    return 0;
}
