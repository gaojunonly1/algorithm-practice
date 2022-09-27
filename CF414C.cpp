#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,Bin[25];
int a[1050005];
int b[1050005];
ll nxd[25],sxd[25];
ll wwx;
void Merge(int l,int r,int cs);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&n);
	Bin[0]=1;
	for(i=1;i<=n;i++)
		Bin[i]=Bin[i-1]<<1;
	for(i=1;i<=Bin[n];i++)
		scanf("%d",&a[i]);
	Merge(1,Bin[n],n);
	int Q;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d",&oo);
		while(oo) {
			swap(sxd[oo],nxd[oo]);
			oo--;
		}
		wwx=0;
		for(i=1;i<=n;i++)
			wwx+=1ll*nxd[i];
		printf("%lld\n",wwx);
	}
    return 0;
}
void Merge(int l,int r,int cs) {
	if(l>=r)
		return;
	int mid=(l+r)>>1;
	Merge(l,mid,cs-1);
	Merge(mid+1,r,cs-1);
	int i,j;
	i=l;
	j=mid+1;
	while(i<=mid&&j<=r) {
		if(a[i]<a[j]) {
			sxd[cs]+=1ll*(r-j+1); //shunxudui
			i++;
		}
		else
			j++;
	}
	i=l;
	j=mid+1;
	int pos=0;
	while(i<=mid&&j<=r) {
		if(a[i]>a[j]) {
			nxd[cs]+=1ll*(mid-i+1); //nixudui
			b[++pos]=a[j++];
		}
		else
			b[++pos]=a[i++];
	}
	for(;i<=mid;i++)
		b[++pos]=a[i];
	for(;j<=r;j++)
		b[++pos]=a[j];
	for(i=l;i<=r;i++)
		a[i]=b[i-l+1];
}
