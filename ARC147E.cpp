#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int a[300005],b[300005];
map<int,int>jyl;
int wwx;
priority_queue<pii,vector<pii>,greater<pii>>heap;
priority_queue<int>jc; 
int main() {
	int i;
	scanf("%d",&n);
	wwx=n;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<b[i]) {
			jyl[a[i]]--;
			jyl[b[i]]++;
			wwx--;
		}
		else
			heap.push(mp(b[i],a[i]));
	}
	int cnt=0;
	for(auto oo:jyl) {
		while(!heap.empty()&&heap.top().fi<=oo.fi) {
			jc.push(heap.top().se);
			heap.pop();
		}
		cnt+=oo.se;
		while(cnt<0) {
			if(jc.empty()||jc.top()<=oo.fi) {
				printf("-1\n");
				return 0;
			}
			cnt++;
			wwx--;
			jyl[jc.top()]--;
			jc.pop();
		}
	}
	printf("%d\n",wwx);
    return 0;
}
