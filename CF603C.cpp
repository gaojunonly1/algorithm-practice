#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,k;
int wwx;
int solve(int x);
int main() {
	int i;
	int oo;
	scanf("%d%d",&n,&k);
	wwx=0;
	if(k&1) {
		for(i=1;i<=n;i++) {
			scanf("%d",&oo);
			if(oo<=3)
				wwx^=(oo&1);
			else if(0==(oo&1))
				wwx^=solve(oo);
		}
	}
	else {
		for(i=1;i<=n;i++) {
			scanf("%d",&oo);
			if(oo<=2)
				wwx^=oo;
			else
				wwx^=((oo&1)^1);
		}
	}
	if(wwx)
		printf("Kevin\n");
	else
		printf("Nicky\n");
    return 0;
}
int solve(int x) {
	if(x<=3)
		return x&1;
	else if(4==x)
		return 2;
	else if(x&1)
		return 0;
	else
		return solve(x/2)==1?2:1;
}
