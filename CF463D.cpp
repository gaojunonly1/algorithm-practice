#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	int i,j,k;
	for(i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
	}
	map<pii,int>jyl;
	for(i=2;i<=m;i++) {
		for(j=0;j<n;j++) {
			int oo;
			cin>>oo;
			jyl[pii(oo-1,i)]=j;
		}
	}
	vector<int>wwx(n,0);
	int lwj=1;
	wwx[a[0]]=1;
	for(i=1;i<n;i++) {
		for(j=0;j<i;j++) {
			bool flg=0;
			for(k=2;k<=m;k++)
				if(jyl[pii(a[j],k)]>jyl[pii(a[i],k)])
					flg=1;
			if(!flg)
				wwx[a[i]]=max(wwx[a[i]],wwx[a[j]]+1);
		}
		lwj=max(lwj,wwx[a[i]]=max(wwx[a[i]],1));
	}
	cout<<lwj<<endl;
    return 0;
}
