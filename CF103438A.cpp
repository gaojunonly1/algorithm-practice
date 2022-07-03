#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int i,j,k;
	string s,t;
	cin>>n;
	cin>>s;
	cin>>t;
	s="#"+s;
	t="#"+t;
	ll wwx=0;
	int jyl=-1;
	bool flg=0;
	for(i=n;i>=1;i--) {
		if(s[i]!=t[i]) {
			jyl=i;
			flg=s[i]<t[i]?1:0;
		}
		if(-1!=jyl&&flg)
			wwx+=n-jyl+1;
	}
	cout<<wwx<<endl;
    return 0;
}
