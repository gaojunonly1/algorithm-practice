#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	string s;
	int i,j,k;
	cin>>s;
	int a[4]={1,6,8,9};
	vector<int>jyl(10,0);
	do {
		int oo=a[0]*1000+a[1]*100+a[2]*10+a[3];
		jyl[oo%7]=oo;
	}while(next_permutation(a,a+4));
	vector<bool>bo(10,0);
	int cnt0=0;
	int num=0;
	for(auto o:s) {
		if('0'==o) {
			cnt0++;
			continue;
		}
		if('1'==o||'6'==o||'8'==o||'9'==o) {
			if(0==bo[(int)(o-'0')])
				bo[(int)(o-'0')]=1;
			else {
				num=num*10+(int)(o-'0');
				num%=7;
				putchar(o);
			}
		}
		else {
			num=num*10+(int)(o-'0');
			num%=7;
			putchar(o);
		}
	}
	num*=10000;
	num%=7;
	cout<<jyl[(7-num)%7];
	while(cnt0--)
		putchar('0');
	cout<<endl;
    return 0;
}
