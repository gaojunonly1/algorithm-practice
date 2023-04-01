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

int A[N1],jyl[N1];

vector<int>G[N1];

int idx;
int dfn[N1],low[N1];
int top;
int stk[N1];
bool instk[N1];
int col[N1];
int scc_num;
vector<int>scc[N1];
void Tarjan(int u) {
	dfn[u]=low[u]=++idx;
	stk[++top]=u;
	instk[u]=1;
	int i;
	ff(G[u],itr) {
		int v=*itr;
		if(!dfn[v]) {
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v]) {
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]) {
		scc_num++;
		while(true) {
			int oo=stk[top--];
			col[oo]=scc_num;
			instk[oo]=0;
			scc[scc_num].pb(oo);
			if(oo==u) {
				break;
			}
		}
	}
}

int main() {

	int i;
	int N;
	cin>>N;
	fz1(i,N) {
		cin>>A[i];
		if(i!=A[i]) {
			G[i].pb(A[i]);
		}
	}
	fz1(i,N) {
		if(A[i]!=i&&!dfn[i]) {
			Tarjan(i);
		}
	}
	int wwx=0;
	fz1(i,N) {
		if(i==A[i]||scc[col[i]].size()>1) {
			wwx++;
		}
	}
	cout<<wwx<<al;
    return 0;
}
