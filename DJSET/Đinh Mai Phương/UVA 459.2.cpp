#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

int n;
vi parent, size_of_set;

void init()
{
	parent.assign(n, 0);
	for (int i = 0; i < n; i++) 
	{
		parent[i] = i;
	}
	size_of_set.assign(n, 1);
	
}

int find(int x)
{
	if (x != parent[x]) parent[x] = find(parent[x]);
	return parent[x];
}

bool same_set(int i, int j)
{
	return (find(i) == find(j));
}

void make_set(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (size_of_set[x] > size_of_set[y])
	{
		parent[y] = x;
		size_of_set[x] += size_of_set[y];
	}
	else
	{
		parent[x] = y;
		size_of_set[y] += size_of_set[x];
	}
}

main(){
	int test;
	freopen("42.inp","r",stdin);
	freopen("42.out","w",stdout);
	
	cin >> test;
	getchar();
	getchar();
	for (int k = 0; k < test; k++)
	{
		string s;
		getline(cin, s);
		n = s[0] - 'A' + 1;
		
		init(); 
		
		int ans = n;
		while (getline(cin, s))
		{
			if (s.empty()) break;
			int x = s[0] - 'A';
			int y = s[1] - 'A';
			if (!same_set(x,y))
			{
				make_set(x,y);
				ans--;
			}
		}
		
		cout << ans << endl;
		if (k != test - 1) cout << endl;
	}
}
