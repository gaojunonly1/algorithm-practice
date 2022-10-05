#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int gs[200005];
struct node {
	int l,r,id;
	operator<(const node tmp)const {
		return (l!=tmp.l)?l<tmp.l:id>tmp.id;	
	}
}a[200005];
struct people {
	int r,id;
	operator<(const people tmp)const {
		return r<tmp.r;
	}
};
multiset<people>jyl;
int wwx[200005];
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	scanf("%d",&m);
	for(i=n+1;i<=n+m;i++) {
		scanf("%d%d%d",&a[i].l,&a[i].r,&gs[i]);
		a[i].id=i;
	}
	sort(a+1,a+n+m+1);
	for(i=1;i<=n+m;i++) {
//		cout<<a[i].id<<" "<<a[i].l<<" "<<a[i].r<<endl;
		if(a[i].id>n)
			jyl.insert((people){a[i].r,a[i].id});
		else {
			if(jyl.empty()) {
				printf("NO\n");
				return 0;
			}
			people o=(people){a[i].r,0};
			auto it=jyl.lower_bound(o);
			if(it==jyl.end()) {
				printf("NO\n");
				return 0;
			}
			wwx[a[i].id]=(it->id)-n;
			gs[it->id]--;
			if(0==gs[it->id])
				jyl.erase(it);
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d ",wwx[i]);
	printf("\n");
    return 0;
}
bool cmpl(node pp,node qq) {
	return pp.l!=qq.l?pp.l<qq.l:pp.r<qq.r;
}
