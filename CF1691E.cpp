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

const char al='\n';

const int N1=200005;

struct DSU {
	int n;
	vector<int>fa;
	DSU(int n1):n(n1) {
		int i;
		fa.resize(n+1);
		fz1(i,n) {
			fa[i]=i;
		}
	}
	int findf(int x) {
		return fa[x]=(x==fa[x])?fa[x]:findf(fa[x]);
	}
	void merge(int x,int y) {
		int xx=findf(x);
		int yy=findf(y);
		if(xx!=yy) {
			fa[xx]=yy;
		}
	}
};

struct Seg {
	int c,l,r,id,type;
	Seg(int c1,int l1,int r1,int id1,int type1):c(c1),l(l1),r(r1),id(id1),type(type1){}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	int i;
	int T,n;
	int c,l,r;
	cin>>T;
	while(T--) {
		cin>>n;
		vector<Seg>jyl;
		fz1(i,n) {
			cin>>c>>l>>r;
			jyl.pb({c,l,r,i,0});
			jyl.pb({c,r,-1,i,1});
		}
		sort(jyl.begin(),jyl.end(),[=](const Seg &pp,const Seg &qq) {
			return pp.l==qq.l?pp.type<qq.type:pp.l<qq.l;
		});
		set<pii>jfm[2];
		DSU* d1=new DSU(n);
		ff(jyl,itr) {
//			cout<<itr->l<<" "<<itr->r<<endl;
			if((itr->type)==0) {
				jfm[itr->c].insert(mp(itr->r,itr->id));
				while(jfm[(itr->c)^1].size()>1) {
					d1->merge(jfm[(itr->c)^1].begin()->se,itr->id);
					jfm[(itr->c)^1].erase(jfm[(itr->c)^1].begin());
				}
				if(!jfm[(itr->c)^1].empty()) {
					d1->merge(jfm[(itr->c)^1].begin()->se,itr->id);
				}
			}
			else {
				jfm[itr->c].erase(mp(itr->l,itr->id));
			}
		}
		int wwx=0;
		fz1(i,n) {
			if(i==d1->findf(i)) {
				wwx++;
			}
		}
		cout<<wwx<<endl;
	}

    return 0;
}
