#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,b[355];
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n;i++,putchar('\n')) {
		for(j=0;j<n;j++) {
			printf("%d ",((i*j+b[i]-i*i)%n+n)%n);
		}
	}
    return 0;
}
