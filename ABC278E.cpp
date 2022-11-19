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

const int N1=305;

int H,W,N,h,w;
int a[N1][N1];
int syf[N1],gj=0,wwx[N1][N1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%d%d%d%d%d",&H,&W,&N,&h,&w);
	fz1(i,H) {
		fz1(j,W) {
			scanf("%d",&a[i][j]);
			syf[a[i][j]]++;
			if(syf[a[i][j]]==1) {
				gj++;
			}
		}
	}
	int nx=1,ny=1;
	fz1(i,h) {
		fz1(j,w) {
			int nx1=nx+i-1;
			int ny1=ny+j-1;
			syf[a[nx1][ny1]]--;
			if(syf[a[nx1][ny1]]==0) {
				gj--;
			}
		}
	}
	wwx[nx][ny]=gj;
	int fx=1;
	int tim=1;
	while(tim<(H-h+1)*(W-w+1)) {
		tim++;
		int nx1,ny1;
		if(fx==1&&ny+w<=W) {
			fz1(i,h) {
				nx1=nx+i-1;
				ny1=ny;
				syf[a[nx1][ny1]]++;
				if(syf[a[nx1][ny1]]==1) {
					gj++;
				}
				ny1=ny+w;
				syf[a[nx1][ny1]]--;
				if(syf[a[nx1][ny1]]==0) {
					gj--;
				}
			}
			ny++;
		}
		else if(fx==-1&&ny-1>=1){
			fz1(i,h) {
				nx1=nx+i-1;
				ny1=ny+w-1;
				syf[a[nx1][ny1]]++;
				if(syf[a[nx1][ny1]]==1) {
					gj++;
				}
				ny1=ny-1;
				syf[a[nx1][ny1]]--;
				if(syf[a[nx1][ny1]]==0) {
					gj--;
				}
			}
			ny--;
		}
		else {
			fx=-fx;
			fz1(j,w) {
				nx1=nx;
				ny1=ny+j-1;
				syf[a[nx1][ny1]]++;
				if(syf[a[nx1][ny1]]==1) {
					gj++;
				}
				nx1=nx+h;
				syf[a[nx1][ny1]]--;
				if(syf[a[nx1][ny1]]==0) {
					gj--;
				}
			}
			nx++;
		}
		wwx[nx][ny]=gj;
	}
	fz1(i,H-h+1) {
		fz1(j,W-w+1) {
			printf("%d ",wwx[i][j]);
		}
		printf("\n");
	}
    return 0;
}
