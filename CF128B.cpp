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

const int N1=100005;

struct Node {
	int ch[26];
	int len,fa;
	Node() {
		memset(ch,0,sizeof ch);
		len=0;
	}
}dian[N1<<1];
int las=1;
int tot=1; //总共的节点个数 
int syf[N1<<1];//每个等价类在S中的出现次数 
char s[N1];
int ecnt=0,head[N1<<1],to[N1<<1],Next[N1<<1];
int buc[N1<<1];
int rk[N1<<1];
ll jyl[N1<<1];
void extend(int c);
void dfs(int u);
void add(int u,int v);
void query(ll T);
int main() {
//	freopen("test.in","r",stdin);
	int i,j;
	int o;
	scanf("%s",s);
	ll T;
	scanf("%lld",&T);
	int len=strlen(s);
	fz0k(i,len) {
		extend(s[i]-'a');
	}
	fz1(i,tot) {
		buc[dian[i].len]++;
	}
	fz1(i,len) {
		buc[i]+=buc[i-1];
	}
	fz1(i,tot) {
		rk[buc[dian[i].len]--]=i;
	}
	fd1(i,tot) {
		syf[dian[rk[i]].fa]+=syf[rk[i]];
	}
	syf[1]=0;
	fd1(i,tot) {
		o=rk[i];
		jyl[o]=syf[o];
		fz0k(j,26) {
			jyl[o]+=jyl[dian[o].ch[j]];
		}
	}
	query(T);
}
void extend(int c) {
	int p=las;
	int np=las=++tot;
	dian[np].len=dian[p].len+1;
	syf[tot]=1;
	for(;p&&!dian[p].ch[c];p=dian[p].fa) {
		dian[p].ch[c]=np;
	}
	if(!p) {
		dian[np].fa=1;
	}
	else {
		int q=dian[p].ch[c];
		if(dian[q].len==dian[p].len+1) {
			dian[np].fa=q;
		}
		else {
			int nq=++tot;
			dian[nq]=dian[q];
			dian[nq].len=dian[p].len+1;
			dian[q].fa=dian[np].fa=nq;
			for(;p&&dian[p].ch[c]==q;p=dian[p].fa) {
				dian[p].ch[c]=nq;
			}
		}
	}
}
void query(ll T) {
	int i;
	if(T>jyl[1]) {
		printf("No such line.\n");
		return;
	}
	int cur=1;
	while((T-=syf[cur])>0) {
		i=0;
		while(T>jyl[dian[cur].ch[i]]&&i<26) {
			T-=jyl[dian[cur].ch[i]];
			i++;
		}
		cur=dian[cur].ch[i];
		putchar(i+'a');
	}
}
