#include <bits/stdc++.h>
#define ii pair <int, int>
#define vi vector <int>
using namespace std;

int n, m, size_n, size_m;
map <ii, int> mp;
vi a;
int ans = 0;

int num(int pos, int val)
{
	int res = 0;
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
	num--;
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
	for (int i = 0; i < (1 << 7); i++)
	{
		bool flag = false;
		for (int j = 0; j < 7; j++)
		{
			if (((i >> j) & 1) != 0) a.push_back(j);
		}
		if (size_n + size_m > a.size()) 
		{
			a.clear(); 
			flag = true;
		}
		//cout << i << " " << bitset<7> (i) << " " << a.size() << ":  ";
		//for (int j = 0; j < a.size(); j++) cout << a[j] << " "; cout << endl;
		if (flag) continue;
		do
		{
			int k = size_n;
			for (int j = 0; j < 2; j++)
			{
				if (a.size() - k > m) continue;
				int x = num(0, k);
				int y = num(k, a.size() - k);
				if (x < n && y < m) mp[ii(x, y)]++;
				//cout << x << " " << y << endl;
				k--;
			}
		} while (next_permutation(a.begin(), a.end()));
		a.clear();
	}
	//for (map <ii, int> :: iterator it = mp.begin(); it != mp.end(); it++) cout << (it -> first).first << " " << (it -> first).second << endl;
	cout << mp.size() << endl;
}
