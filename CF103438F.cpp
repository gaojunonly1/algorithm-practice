#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ll N,X,R,P,K;
	int i,j,k;
	cin>>N>>X>>R>>P>>K;
	vector<bool>a(N+5);
	for(i=1;i<=N;i++) {
		char ch=' ';
		while(!isdigit(ch))
			ch=getchar();
		a[i]=(ch-'0');
	}
	vector<pair<ll,int>>jyl(N+5);
	for(i=1;i<=N;i++) {
		if(a[i]==0)
			jyl[i]=mp((N-i+1)*P,i);
		else
			jyl[i]=mp((N-i+1)*(P+R),i);
	}
	sort(jyl.begin(),jyl.end());
	reverse(jyl.begin(),jyl.end());
	vector<bool>lwj(N+5,0);
	for(i=0;i<K;i++)
		lwj[jyl[i].se]=1;
	ll wwx=0,r=0,p=0;
	for(i=1;i<=N;i++) {
		if(a[i])
			r++;
		if(lwj[i]) {
			r=max(r-1,0ll);
			p++;
		}
		wwx=wwx+X+1ll*P*p-1ll*R*r;
	}
	cout<<wwx<<endl;
    return 0;
}
