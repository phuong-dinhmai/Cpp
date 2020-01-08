#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int test, n, m;
char a[304][304];
int d[90007];
vector <pair <int, int> > pos;

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while (test--){
		cin >> n >> m;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				if (a[i][j] == '1') pos.push_back(make_pair(i, j));
			}
		}
		
		for (int i = 0; i < pos.size(); ++i){
			for (int j = 0; j < i; ++j) {
				int x = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
				d[x]++;
			}
		}
		
		for (int i = 1; i <= n+m-2; ++i) {
			cout << d[i] << " "; 
			d[i] = 0;
		}
		cout << endl;
		pos.clear();
	}
}
