#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
string cd[155];
int main() {
	int wwx=0;
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>cd[i];
	int wz=0,jyl=0;
	i=0;
	while(i!=n) {
		int oo;
		vector<int>cao;
		if(i&1) {
			for(j=m-1;j>=0;j--)
				if('W'==cd[i][j])
					cao.pb(j);
			oo=(int)cao.size();
			if(0!=oo) {
				jyl=i;
				if(wz<cao[0])
					wwx+=cao[0]-wz+cao[0]-cao[oo-1];
				else
					wwx+=wz-cao[oo-1];
			}
		}
		else {
			for(j=0;j<m;j++)
				if('W'==cd[i][j])
					cao.pb(j);
			oo=(int)cao.size();
			if(0!=oo) {
				jyl=i;
				if(wz>cao[0])
					wwx+=wz-cao[0]+cao[oo-1]-cao[0];
				else
					wwx+=cao[oo-1]-wz;
			}
		}
		if(0!=oo)
			wz=cao[oo-1];
		i++;
	}
	cout<<wwx+jyl<<endl;
    return 0;
}
