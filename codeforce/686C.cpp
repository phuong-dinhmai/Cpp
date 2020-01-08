#include <bits/stdc++.h>
#define ii pair <int, int>
#define vi vector <int>
using namespace std;

const int inf = 1e9+7;

int n, m, size_n, size_m;
map <ii, int> mp;
vi a;
int ans = 0;

int num(int pos, int val)
{
	int res = 0;
	if (val < 1) return inf;
	for (int i = 1; i <= val; i++)
	{
		res = res*7 + a[pos+i-1];
	}
	//cout << res << endl;
	return res;
}

int size(int num)
{
	int ans = 0;
	if (num == 0) return 1;
	while (num > 0)
	{
		num /= 7;
		ans++;
	}
	return ans;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	size_n = size(n);
	size_m = size(m);
	//cout << size_n << " " << size_m << endl;
	for (int i = 1; i < (1 << 7); i++)
	{
		bool flag = false;
		for (int j = 0; j < 7; j++)
		{
			if (((i >> j) & 1) != 0)
			{
				a.push_back(j);
			} 
			if (j == 0) flag = true;
		}
		do
		{
			int k = size_n;
			for (int j = 0; j < 2; j++)
			{
				int x = num(0, k);
				bool ok = true;
				if (a.size() - k < size_m-1) continue;
				int y = num(k, a.size() - k);
				//cout << x << " " << y << endl;
				if (flag && (k != size_n || a.size() - k != size_m)) ok = false;
				//if (x < n && y < m) cout << k << " " << x << " " << y << endl;
				if (ok && x < n && y < m) mp[ii(x, y)]++;
				k--;
			}
		} while (next_permutation(a.begin(), a.end()));
		a.clear();
	}
	//for (map <ii, int> :: iterator it = mp.begin(); it != mp.end(); it++) cout << (it -> first).first << " " << (it -> first).second << endl;
	cout << mp.size() << endl;
}
