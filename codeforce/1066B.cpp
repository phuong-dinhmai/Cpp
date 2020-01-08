#include <bits/stdc++.h>
using namespace std;

const int maxN = 2005;
const int inf = 1e9+7;

bool a[maxN];
int n, r;
int f[maxN];
vector <int> light;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> r;
	light.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) light.push_back(i);
	}
	for (int i = 1; i < n+5; i++) f[i] = inf;
	f[0] = 0;
	bool flag = false;
	for (int i = 1; i < light.size(); ++i){
		if (light[i] - light[i-1] >= 2*r) {
			flag = true;
			break;
		}
	}
	if (flag || light.size() == 1) cout << -1 << endl;
	else {
		for (int i = 1; i <= light[1]; ++i) f[i] = 1;
		for (int i = light[0]+1; i <= n; i++){
			if (!a[i]) continue;
			for (int j = 1; j <= r && i+j-1 <= n; j++){
				f[i+j-1] = min(f[max(0, i-r)] + 1, f[i+j-1]);
			}
		}
		//for (int i = 1; i <= n; i++) cout <<f[i] << " "; cout << endl;
		if (f[n] != inf) cout << f[n] << endl; else cout << -1 << endl;
	}
	//cout << f[n] << endl;
}
