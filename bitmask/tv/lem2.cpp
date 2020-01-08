#include <bits/stdc++.h>
#define eb emplace_back
#define mp make_pair
#define ft first
#define nd second
#define init(x,n,y) x.assign(n,y);
using namespace std;
 
typedef vector<int> vi;
 
int main() {
	ios_base::sync_with_stdio(false);
	int n, k ; cin >> n >> k;
	k = (1<<(k-1));
	vi a(n); 
	for (int i=0;i<n;++i) {
		a[i]=(1<<n)-1;
		int s, in; cin >> s;
		while (s--) {cin >> in; a[i]^=(1<<(in-1));}
	}
	int start = 0, in;
	for (int i=0;i<n;++i) {
		cin >> in; start+=(in<<i);
	}
	vi Dist(1<<20,1e9); Dist[start]=0;
	queue<int> q; q.push(start); 
	vi Pre(1<<20, -1);
	while (!q.empty() && Dist[k]==int(1e9)) {
		int v = q.front(); q.pop(); 
		for (int i=0;i<n;++i) {
			int u = (v | (1<<i)) & a[i];
			if (Dist[u]!=int(1e9)) continue;
			Dist[u]=Dist[v]+1; Pre[u] = v; q.push(u); 
		}
	}
	cout << (Dist[k]==int(1e9)?-1:Dist[k]) << endl;
	if (Dist[k] != int(1e9)) {
		//while (k != -1) cout << bitset<20>(k) << endl, k = Pre[k];
	}
} 