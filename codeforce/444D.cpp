#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

const int base = 27;

vector <int> st[27*27*27*27];
string str;
map <ii, int> mp;
int q;

int hsh(string s)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++) ans = ans * base + (s[i] - 'a' + 1);
	return ans;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> str;
	for (int j = 1; j < 5; j++)
		for (int i = 0; i + j <= str.size(); i++)
		{
			int x = hsh(str.substr(i, j));
			st[x].push_back(i);
		}
	
	cin >> q;
	while(q--)
	{
		string a, b;
		cin >> a >> b;
		int x = hsh(a);
		int y = hsh(b);
		/*cout << st[x].size() << endl;
		for (int i = 0; i < st[x].size(); i++) cout << st[x][i] << " "; cout << endl << endl;
		cout << y << " " << st[y].size() << endl;
		for (int i = 0; i < st[y].size(); i++) cout << st[y][i] << " "; cout << endl;*/
		if (x < y) swap(x, y), a.swap(b);
		if (st[x].size() == 0 || st[y].size() == 0) printf("-1\n");
		else if (mp.count(ii(x, y))) printf("%d\n", mp[ii(x, y)]);
		else
		{
			unsigned int ans = str.size();
			for (int i = 0; i < st[x].size(); i++)
			{
				int pos = lower_bound(st[y].begin(), st[y].end(), st[x][i]) - st[y].begin();
				if (st[x][i] > st[y][pos] || pos == st[y].size()) continue;
				ans = min(ans, max(st[x][i] + a.size(), st[y][pos] + b.size()) - st[x][i]);
			}
			
			for (int i = 0; i < st[y].size(); i++)
			{
				int pos = lower_bound(st[x].begin(), st[x].end(), st[y][i]) - st[x].begin();
				//cout << st[y][i] << " " << st[x][pos] << endl;
				if (pos == st[x].size() || st[y][i] > st[x][pos]) continue;
				ans = min(ans, max(st[y][i] + b.size(), st[x][pos] + a.size()) - st[y][i]);
			}
			
			mp[ii(x, y)] = ans;
			printf("%d\n", ans);
		}
	}
}
