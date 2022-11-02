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

const int N1=405;
const int LEN=2000005;

char t[N1];
char s[LEN];
vector<char>tt;
vector<char>ss;


class ACAM {
public:
	vector<char>s1;
	bitset<21> syf[N1],jyl[LEN],gj[LEN];
	void Init(int nn) {
		int i;
		n=nn;
		cnt=0;
		memset(ref,0,sizeof ref);
		fz1(i,400) {
			syf[i].reset();
		}
	}
	void Insert(const vector<char>t) {
		int cur=0;
		ff(t,itr) {
			int oo=(int)(*itr)-'a';
			if(0==Trie[cur].son[oo]) {
				Trie[cur].son[oo]=++cnt;
			}
			cur=Trie[cur].son[oo];
		}
		ref[cur]=t.size();
		syf[cur]|=1<<(t.size()-1);
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
			syf[u]|=syf[Trie[u].fail];
			fz0k(i,26) {
				if(Trie[u].son[i]) {
					Trie[Trie[u].son[i]].fail=Trie[Trie[u].fail].son[i];
					que.push(Trie[u].son[i]);
				}
				else {
					Trie[u].son[i]=Trie[Trie[u].fail].son[i];
				}
			}
			que.pop();
		}
	}
	void Query(int id) {
		int i;
		int cur=0;
		fz0k(i,s1.size()) {
			cur=Trie[cur].son[(int)s1[i]-'a'];
			jyl[i+1]=syf[cur];
		}
	}
	void Solve(vector<char>ss,int id) {
		int i,j;
		s1=ss;
		Query(id);
		gj[0]=1;
		fz1(i,ss.size()) {
			gj[i]=gj[i-1]<<1;
			if((jyl[i]&gj[i-1]).count()) {
				gj[i][0]=1;
			}
		}
		fd0g(i,ss.size()) {
			if(gj[i][0]) {
				printf("%d\n",i);
				break;
			}
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
};

ACAM A1;

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,m;
	scanf("%d%d",&n,&m);
	A1.Init(n);
	fz1(i,n) {
		scanf("%s",t+1);
		o=strlen(t+1);
		tt.resize(0);
		fz1(j,o) {
			tt.pb(t[j]);
		}
		A1.Insert(tt);
	}
	A1.Build();
	fz1(i,m) {
		scanf("%s",s+1);
		o=strlen(s+1);
		ss.resize(0);
		fz1(j,o) {
			ss.pb(s[j]);
		}
		A1.Solve(ss,i);
	}
    return 0;
}
