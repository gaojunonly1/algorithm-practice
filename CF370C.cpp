#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int cnt=0;
int s1[5005],s2[5005];
struct node {
	int cor,sz;
}a[105];
vector<int>jyl[105];
bool cmpsz(node pp,node qq);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&oo);
		jyl[oo].pb(i);
		s1[i]=s2[i]=oo;
	}
	for(i=1;i<=m;i++)
		if(jyl[i].size()) {
			a[++cnt].cor=i;
			a[cnt].sz=jyl[i].size();
		}
	sort(a+1,a+cnt+1,cmpsz);
	if(a[1].sz*2>n)
		printf("%d\n",(n-a[1].sz)*2);
	else
		printf("%d\n",n);
	for(i=1;i<=n;i++) {
		if(s1[i]!=s2[i])
			continue;
		for(j=1;j<=n;j++) {
			if(i==j)
				continue;
			if(s1[i]!=s2[j]&&s1[j]!=s2[i]) {
				swap(s1[i],s1[j]);
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d %d\n",s1[i],s2[i]);
    return 0;
}
bool cmpsz(node pp,node qq) {
	return pp.sz>qq.sz;
}
