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
	cin>>n;
	string s;
	cin>>s;
	int An=0,Bn=0,Cn=0;
	vector<int>A(0),B(0),C(0);
	for(i=0;i<n*2;i++) {
		if(s[i]=='A') {
			A.pb(i);
			An++;
		}
		else if(s[i]=='B') {
			B.pb(i);
			Bn++;
		}
		else {
			C.pb(i);
			Cn++;
		}
	}
	int X,Y,Z;
	if((An+Bn-Cn)&1||(An+Cn-Bn)&1||(Bn+Cn-An)&1) {
		puts("NO");
		return 0;
	}
	if(0>An+Bn-Cn||0>An+Cn-Bn||0>Bn+Cn-An) {
		puts("NO");
		return 0;
	}
	X=(An+Bn-Cn)>>1;
	Y=(An+Cn-Bn)>>1;
	Z=(Bn+Cn-An)>>1;
	vector<pii>wwx(0);
	vector<bool>Abo(n+5,0),Cbo(n+5,0);
	j=0;
	k=0;
	while(j<Z&&k<Cn) {
		if(C[k]>B[j]) {
			wwx.pb(mp(B[j],C[k]));
			Cbo[k]=1;
			j++;
			k++;
		}
		else
			k++;
	}
	if(Z!=j) {
		puts("NO");
		return 0;
	}
	k=An-1;
	j=Bn-1;
	while(j>=Z&&0<=k) {
		if(A[k]<B[j]) {
			wwx.pb(mp(A[k],B[j]));
			Abo[k]=1;
			k--;
			j--;
		}
		else
			k--;
	}
	if(Z-1!=j) {
		puts("NO");
		return 0;
	}
	j=0;
	k=0;
	int Y1=Y;
	while(j<An&&k<Cn) {
		while(Abo[j])
			j++;
		while(Cbo[k])
			k++;
		if(j<An&&k<Cn) {
			if (A[j]<C[k]){
				wwx.pb(mp(A[j],C[k]));
				j++;
				k++;
				Y1--;
			}
			else {
				puts("NO");
				return 0;
			}
		}
	}
	if(0!=Y1) {
		puts("NO");
		return 0;
	}
	cout<<"YES"<<endl;
	for(auto oo:wwx)
		cout<<oo.fi+1<<" "<<oo.se+1<<endl;
    return 0;
}
