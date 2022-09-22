#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(a&&b&&c&&d&&e&&f) {
		if(b*d*f>a*c*e)
			printf("Ron\n");
		else
			printf("Hermione\n");
	}
	else {
		if(d==0)
			printf("Hermione\n");
		else {
			if((a==0&&b>0)||c==0||(e==0&&f>0&&b>0))
				printf("Ron\n");
			else
				printf("Hermione\n");
		}
	}
    return 0;
}
