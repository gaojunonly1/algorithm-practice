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
ll syf[N1<<1];//每个等价类在S中的出现次数 
char s[N1];
int len;
int ecnt=0,head[N1<<1],to[N1<<1],Next[N1<<1];
void extend(int c);
void dfs(int u);
void add(int u,int v);
int main() {
	freopen("test.in","r",stdin);
//	freopen("gj.out","w",stdout);
	int i;
	scanf("%s",s);
	len=strlen(s);
	fz0k(i,len) {
		extend(s[i]-'a');
	}
	fz(i,2,tot) {
		add(dian[i].fa,i);
	}
//	puts("233333"); 
	dfs(1);
	ll gj=0;
	fz(i,2,tot) {
		if(syf[i]>1) {
			gj=max(gj,1ll*syf[i]*dian[i].len);
		}
	}
	printf("%lld\n",gj);
}
void extend(int c) {
	int p=las;
	int np=las=++tot;
	syf[tot]=1;
	dian[np].len=dian[p].len+1;
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
void dfs(int u) {
	for(int i=head[u];i!=0;i=Next[i]) {
		int v=to[i];
		dfs(v);
		syf[u]+=syf[v];
	}
}
void add(int u,int v) {
	Next[++ecnt]=head[u];
	to[ecnt]=v;
	head[u]=ecnt;
}
