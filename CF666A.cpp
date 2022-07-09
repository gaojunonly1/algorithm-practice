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
	string s;
	int i,j;
	cin>>s;
	int n=s.size();
	if(n<=6) {
		cout<<"0"<<endl;
		return 0;
	}
	vector<bool>dp2(n,0),dp3(n,0);
	for(i=n-1;i>=5;i--) {
		if(n==i+2)
			dp2[i]=1;
		if(n==i+3)
			dp3[i]=1;
		if(n>i+2) {
			if(dp3[i+2])
				dp2[i]=1;
			if(dp2[i+2]&&(s[i]!=s[i+2]||s[i+1]!=s[i+3]))
				dp2[i]=1;
		}
		if(n>i+3) {
			if(dp2[i+3])
				dp3[i]=1;
			if(dp3[i+3]&&(s[i]!=s[i+3]||s[i+1]!=s[i+4]||s[i+2]!=s[i+5]))
				dp3[i]=1;
		}
	}
	set<string>wwx;
	for(i=5;i<n;i++) {
		if(dp2[i])
			wwx.insert(s.substr(i,2));
		if(dp3[i])
			wwx.insert(s.substr(i,3));
	}
	cout<<wwx.size()<<endl;
	for(auto oo:wwx)
		cout<<oo<<endl;
    return 0;
}
