#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

int n;
vi parent, size_of_set;

void init()
{
	parent.assign(n, 0);
	for (int i = 0; i < n; i++) parent[i] = i;
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
		parent[x] = y;
		size_of_set[y] += size_of_set[x];
	}
	else
	{
		parent[y] = x;
		size_of_set[x] += size_of_set[y];
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test;
	cin >> test;
	while (test--)
	{
		cin >> n;
		getchar();
		
		init(); 
		
		int ans[2] = {0,0};
		char c;
		int x,y;
		string s;
		while (getline(cin, s))
		{
			if (s.empty()) break;
			istringstream ss(s);
			ss >> c;
			ss >> x; 
			ss >> y;
			x--;
			y--;
			if (c == 'q') ans[same_set(x, y)]++;
			if (c == 'c' && !same_set(x,y)) make_set(x,y);
		}
		cout << ans[1] << "," << ans[0] << endl;
		if (test != 0) cout << endl;
	}
}
