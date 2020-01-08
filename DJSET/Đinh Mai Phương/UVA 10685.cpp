#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

vi father, size_of_set;
int n, mx;
map <string, int> ma;

void init()
{
	father.assign(n, 0);
	for (int i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n,1);
	ma.clear();
}

int find(int x)
{
	return (x == father[x]? x: (father[x] = find(father[x])));
}

bool same_set(int x, int y)
{
	return (find(x) == find(y));
}

void make_set(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (size_of_set[x] > size_of_set[y])
	{
		father[x] = y;
		size_of_set[y] += size_of_set[x];
	}
	else
	{
		father[y] = x;
		size_of_set[x] += size_of_set[y];
	}
	mx = max(mx, max(size_of_set[x], size_of_set[y]));
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	int m;
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		init();
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			ma[s] = i;
		}
		mx = 1;
		
		for (int i = 0; i < m; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			int x = ma[s1];
			int y = ma[s2];
			if (!same_set(x,y)) make_set(x,y);
		}
		cout << mx << endl;
	}
}
