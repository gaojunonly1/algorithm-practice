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
int n,m;
vector<pii> syf;
vector<int> a[N1];
vector<int> aa[N1];
int ind[N1<<1];
int C;
vector<int> G[N1<<1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;

	scanf("%d%d",&n,&m);
	syf.resize(n+1);
	fz1(i,n) {
		syf[i].fi=iinf;
		syf[i].se=-iinf;
	}
	fz1(i,n) {
		a[i].resize(m+1);
		fz1(j,m) {
			scanf("%d",&oo);
			a[i][j]=oo;
			if(oo!=0) {
				syf[i].fi=min(syf[i].fi,oo);
				syf[i].se=max(syf[i].se,oo);
			}
		}
	}
	fz1(i,n) {
		if(syf[i].fi==iinf) {
			syf[i].fi=syf[i].se=0;
		}
	}
	sort(syf.begin(),syf.end());
	bool gj=0;
	oo=0;
	ff(syf,itr) {
		if(itr->fi<oo) {
			gj=1;
		}
		oo=itr->se;
	}
	if(gj==1) {
		printf("No\n");
		return 0;
	}
	C=m;
	fz1(i,n) {
		vector<pii>jyl(0);
		fz1(j,m) {
			if(a[i][j]!=0) {
				jyl.pb(mp(a[i][j],j));
			}
		}
		sort(jyl.begin(),jyl.end());
		int cnt=0;
		fz0k(j,jyl.size()) {
			if(j==0||jyl[j].fi!=jyl[j-1].fi) {
				cnt++;
				aa[cnt].resize(0);
			}
			aa[cnt].pb(jyl[j].se);
		}
//		cout<<i<<" "<<cnt<<endl;
		fz1(j,cnt) {
			ff(aa[j],itr) {
				if(j!=1) {
					G[C+j-1].pb(*itr);
					ind[*itr]++;
				}
				if(j!=cnt) {
					G[*itr].pb(C+j);
					ind[C+j]++;
				}
			}
		}
		if(cnt>1) {
			C+=cnt-1;
		}
	}
	queue<int>que;
	fz1(i,C) {
		if(!ind[i]) {
			que.push(i);
		}
	}
	while(!que.empty()) {
		int u=que.front();
		ff(G[u],itr) {
			int v=*itr;
			ind[v]--;
			if(ind[v]==0) {
				que.push(v);
			}
		}
		que.pop();
	}
	oo=0;
	fz1(i,C) {
		oo+=ind[i];
	}
	if(oo==0) {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
    return 0;
}
