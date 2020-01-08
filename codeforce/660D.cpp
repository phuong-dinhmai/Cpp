#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
using namespace std;

const int N = 2005;

int n;
ii a[N];
map <ii, int> mp;
int ans = 0;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			int nx = a[i].x + a[j].x;
			int ny = a[i].y + a[j].y;
			mp[ii(nx, ny)]++;
		}
	for (map <ii, int> :: iterator it = mp.begin(); it != mp.end(); it++) ans += (it -> y)*(it -> y - 1)/2;
	cout << ans << endl;
}
