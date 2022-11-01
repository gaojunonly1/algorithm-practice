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

const int N1=200005;
const int LEN=2000005;

char t[N1];
char s[LEN];
vector<char>tt[N1];
vector<char>ss;

class ACAM {
public:
	int syf[N1*26];
	void Init(int nn) {
		n=nn;
		cnt=0;
	}
	void Insert(const vector<char>t,int id) {
		int cur=0;
		ff(t,itr) {
			int oo=(int)(*itr)-'a';
			if(0==Trie[cur].son[oo]) {
				Trie[cur].son[oo]=++cnt;
			}
			cur=Trie[cur].son[oo];
		}
		ref[id]=cur;
	}
	void Build() {
		int i;
		queue<int>que;
		fz0k(i,26) {
			if(Trie[0].son[i]) {
				que.push(Trie[0].son[i]);
			}
		}
		while(!que.empty()) {
			int u=que.front();
			fz0k(i,26) {
				if(Trie[u].son[i]) {
					Trie[Trie[u].son[i]].fail=Trie[Trie[u].fail].son[i];
					int v=Trie[u].son[i];
					G[Trie[v].fail].pb(v);
					que.push(v);
				}
				else {
					Trie[u].son[i]=Trie[Trie[u].fail].son[i];
				}
			}
			que.pop();
		}
	}
	void Query(const vector<char>s) {
		int cur=0;
		ff(s,itr) {
			int oo=(*itr)-'a';
			cur=Trie[cur].son[oo];
			syf[cur]++;
		}
	}
	void GetAns() {
		int i;
		fz0k(i,26) {
			if(Trie[0].son[i]) {
				Dfs(Trie[0].son[i]);
			}
		}
	}
	void Dfs(int u) {
		ff(G[u],itr) {
			int v=*itr;
			Dfs(v);
			syf[u]+=syf[v];
		}
	}
	void Solve() {
		int i;
		GetAns();
		fz1(i,n) {
			printf("%d\n",syf[ref[i]]);
		}
	}
private:
	int n;
	int cnt;
	struct TrieNode {
		int fail;
		int son[26]={0};
	}Trie[N1];
	int ref[N1]; //×Ö·û´®µÄ½áÊøµã 
	vector<int>G[N1];
};

ACAM A1;

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	A1.Init(n);
	fz1(i,n) {
		scanf("%s",t+1);
		o=strlen(t+1);
		fz1(j,o) {
			tt[i].pb(t[j]);
		}
		A1.Insert(tt[i],i);
	}
	A1.Build();
	scanf("%s",s+1);
	o=strlen(s+1);
	fz1(i,o) {
		ss.pb(s[i]);
	}
	A1.Query(ss);
	A1.Solve();
    return 0;
}
