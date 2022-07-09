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
	int n,m;
	int i,j;
	cin>>n>>m;
	string s;
	cin>>s;
	s="#"+s;
	if(n-m>m-1) {
		while(m>1) {
			cout<<"LEFT"<<endl;
			m--;
		}
		while(m<n) {
			cout<<"PRINT"<<" "<<s[m]<<endl;
			cout<<"RIGHT"<<endl;
			m++;
		}
		cout<<"PRINT"<<" "<<s[m]<<endl;
	}
	else {
		while(m<n) {
			cout<<"RIGHT"<<endl;
			m++;
		}
		while(m>1) {
			cout<<"PRINT"<<" "<<s[m]<<endl;
			cout<<"LEFT"<<endl;
			m--; 
		}
		cout<<"PRINT"<<" "<<s[m]<<endl;
	}
    return 0;
}
