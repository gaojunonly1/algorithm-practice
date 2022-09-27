#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int cor[1005][1005];
multiset<int>corX[1000005],corY[1000005];
struct Tree {
	int s[1005][1005];
	#define lowbit(x) ((x)&(-x))
	Tree() {
		memset(s,0,sizeof s);
	}
	void Add(int x,int y,int z) {
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=m;j+=lowbit(j))
				s[i][j]+=z;
	}
	int Ask(int x,int y) {
		int jyl=0;
		for(int i=x;i>0;i-=lowbit(i))
			for(int j=y;j>0;j-=lowbit(j))
				jyl+=s[i][j];
		return jyl;
	}
	void Add1(int a,int b,int c,int d,int v) {
		Add(a,b,v);
		Add(a,d+1,-v);
		Add(c+1,b,-v);
		Add(c+1,d+1,v);
		return;
	}
}T1;
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=1000000;i++)
		corX[i].clear(),corY[i].clear();
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			scanf("%d",&oo);
			cor[i][j]=oo;
			corX[oo].insert(i);
			corY[oo].insert(j);
		}
	}
	int a,b,c,d;
	for(i=1;i<=1000000;i++) {
		if(corX[i].size()>=2) {
			a=*corX[i].begin(),b=*corY[i].begin();
			c=*corX[i].rbegin(),d=*corY[i].rbegin();
			T1.Add1(a,b,c,d,1);
		}
	}
	int Q,opt,x,y,cc;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d%d",&opt,&x,&y);
		if(1==opt) {
			oo=T1.Ask(x,y);
			oo>0?puts("YES"):puts("NO");
		}
		else {
			scanf("%d",&cc);
			if(cc==cor[x][y])
				continue;
			i=cor[x][y]; //the last color
			if(corX[i].size()>=2) {
				a=*corX[i].begin(),b=*corY[i].begin();
				c=*corX[i].rbegin(),d=*corY[i].rbegin();
				T1.Add1(a,b,c,d,-1);
			}
			auto it=corX[i].lower_bound(x);
			corX[i].erase(it);
			auto it1=corY[i].lower_bound(y);
			corY[i].erase(it1);
			if(corX[i].size()>=2) {
				a=*corX[i].begin(),b=*corY[i].begin();
				c=*corX[i].rbegin(),d=*corY[i].rbegin();
				T1.Add1(a,b,c,d,1);
			}
			i=cor[x][y]=cc; //the new color
			if(corX[i].size()>=2) {
				a=*corX[i].begin(),b=*corY[i].begin();
				c=*corX[i].rbegin(),d=*corY[i].rbegin();
				T1.Add1(a,b,c,d,-1);
			}
			corX[i].insert(x);
			corY[i].insert(y);
			if(corX[i].size()>=2) {
				a=*corX[i].begin(),b=*corY[i].begin();
				c=*corX[i].rbegin(),d=*corY[i].rbegin();
				T1.Add1(a,b,c,d,1);
			}
		}
	}
    return 0;
}
