#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const int N1=1000005;

int a[N1];

void solve();

int main() {
    int i,j,k;
    int o,p,q;
    ll oo,pp,qq;
    
    int T;
    scanf("%d",&T);
    while(T--) {
        solve();
    }

    return 0;
}

void solve() {
    int i;
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    int oo=(n-1)*(m-1);
    int syf=K;
    int x;
    priority_queue<int> que;
    while(!que.empty())
        que.pop();
    fz1(i,K) {
        scanf("%d",&a[i]);
    }
    fz1(i,K) {
        que.push(a[i]);
        if(que.size()==n*m-2) {
            printf("TIDAK\n");
            return;
        }
        while(!que.empty()&&que.top()==syf) {
            que.pop();
            syf--;
        }
    }
    printf("YA\n");
}
