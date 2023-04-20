#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

typedef long long ll;
typedef std::pair<int, int> pii;
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

const char al = '\n';

const int N1 = 200005;
struct Node {
	int pos, z1, z2;
	ll dist;
	bool operator<(const Node& tmp) const {
		return tmp.dist < dist;
	}
};

struct Graph {
	int n;
	int cnt, head[N1], Next[N1 << 1], to[N1 << 1];
	ll val[N1 << 1];
	bool vis[N1][2][2];
	ll wwx[N1][2][2];
	Graph() {}
	Graph(int n1) :n(n1) {
		cnt = 0;
		memset(head,0,sizeof head);
		memset(vis,0,sizeof vis);
		memset(wwx,0x3f,sizeof wwx); 
	}
	void addedge(int, int, ll);
	void Dijkstra(int);
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int i;
	int n, m;
	std::cin >> n >> m;

	Graph *g1 = new Graph(n);
	fz1(i, m) {
		int u, v;
		ll w;
		std::cin >> u >> v >> w;
		g1->addedge(u, v, w);
		g1->addedge(v, u, w);
	}
	g1->Dijkstra(1);
	fz(i, 2, n) {
		std::cout << g1->wwx[i][1][1] << " ";
	}
	std::cout << al;
	return 0;
}

void Graph::addedge(int u, int v, ll w) {
	to[++cnt] = v;
	Next[cnt] = head[u];
	val[cnt] = w;
	head[u] = cnt;
}

void Graph::Dijkstra(int s) {
	std::priority_queue < Node > que;
	que.push({ s,0,0,0 });
	wwx[s][0][0] = 0;
	while (!que.empty()) {
		Node tmp = que.top();
		que.pop();
		int u = tmp.pos, z1 = tmp.z1, z2 = tmp.z2;
		//std::cout << u << " " << z1 << " " << z2 << " " << tmp.dist << std::endl;
		if (vis[u][z1][z2]) {
			continue;
		}
		vis[u][z1][z2] = 1;
		for (int e = head[u]; e; e = Next[e]) {
			int v = to[e];
			if (wwx[v][z1][z2] > tmp.dist + val[e]) {
				wwx[v][z1][z2] = tmp.dist + val[e];
				que.push({v, z1, z2, wwx[v][z1][z2]});
			}
			if (0 == z1) {
				if (wwx[v][1][z2] > tmp.dist) {
					wwx[v][1][z2] = tmp.dist;
					que.push({ v,1,z2,wwx[v][1][z2] });
				}
			}
			if (0 == z2) {
				if (wwx[v][z1][1] > tmp.dist + val[e] * 2) {
					wwx[v][z1][1] = tmp.dist + val[e] * 2;
					que.push({ v,z1,1,wwx[v][z1][1] });
				}
			}
			if (0 == z1 && 0 == z2) {
				if (wwx[v][1][1] > tmp.dist + val[e]) {
					wwx[v][1][1] = tmp.dist + val[e];
					que.push({ v, 1, 1, wwx[v][1][1] });
				}
			}
		}
	}
}
