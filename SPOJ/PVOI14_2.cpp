#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

struct data{
	int cost, x, y;
	data (int _cost, int _x, int _y) { cost = _cost, x = _x, y = _y;}
	bool operator < (const data &other) {
		return cost < other.cost;
	}
};

vector <data> bridge;
int n;
int a[N][N];
int father[N*N];
int ans = 0;
vector <int> prepare;

void init(){
	for (int i = 0; i < prepare.size(); i++) {
		father[prepare[i]] = -1;
	}
	prepare.clear();
}

int find(int u) {
	return (father[u] < 0? u: find(father[u]));
}

bool same_set(int u, int v) {
	return (find(u) == find(v));
}

void make_set(int i, int j){
	int x = find(i), y = find(j);
	if (father[x] < father[y]) father[x] += father[y], father[y] = x, ans = min(ans, father[x]);
	else father[y] += father[x], father[x] = y, ans = min(ans, father[y]);
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != n-1) bridge.push_back(data(abs(a[i][j] - a[i+1][j]), i*n+j, (i+1)*n+j));
			if (j != n-1) bridge.push_back(data(abs(a[i][j] - a[i][j+1]), i*n+j, i*n+j+1));
		}
	}
	
	sort(bridge.begin(), bridge.end());
	//for (int i = 0; i < bridge.size(); i++) cout << bridge[i].cost << " " << bridge[i].x << " " << bridge[i].y << endl;
	memset(father, -1, sizeof(father));
	
	for (int i = 0; i < bridge.size(); i++) {
		if (i != 0 && bridge[i].cost != bridge[i-1].cost) init();
		if (!same_set(bridge[i].x, bridge[i].y)) make_set(bridge[i].x, bridge[i].y);
		prepare.push_back(bridge[i].x);
		prepare.push_back(bridge[i].y);
	}
	
	cout << -ans << endl;
}
