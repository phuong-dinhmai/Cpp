#include <bits/stdc++.h>
#define ii pair <int, int>
#define start first
#define end second
using namespace std;

const int N = 1e6+7, M = 1e6+5;
const int inf = 1e6+2;

int n, q;
ii a[N];
int f[M][20];

int query(int begin, int en) {
	int ans = 0;
	for (int i = 19; i >= 0; i--) {
		if (f[begin][i] <= en){
			ans += (1 << i);
			begin = f[begin][i] + 1;
		}
	}
	return ans;
}

main(){
//	freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < 20; j++) f[i][j] = inf;
			
	for (int i = 1; i <= n; i++) {
		cin >> a[i].start >> a[i].end;
		f[a[i].start][0] = min(f[a[i].start][0], a[i].end);
	}
	
	for (int i = M-5; i > 0; i--) {
		f[i][0] = min(f[i][0], f[i+1][0]);
	}
	
	for (int j = 1; j < 20; j++) 
		for (int i = 0; i < M-4; i++) 
			f[i][j] = min(f[f[i][j-1]+1][j-1], f[i][j]);
			
	//for (int i = 1; i <= 10; i++) cout << f[i][1] << endl;
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << query(x, y) << endl;
	}
}
