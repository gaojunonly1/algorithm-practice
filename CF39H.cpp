#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int a;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&a);
	for(int i=1;i<=a-1;i++,putchar('\n'))
		for(int j=1;j<=a-1;j++)
			if(j!=1) printf("%2d ",(i*j/a)*10+(i*j)%a);
			else printf("%d ",i*j);
    return 0;
}
