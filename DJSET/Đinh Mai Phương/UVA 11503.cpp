#include <bits/stdc++.h>
#define maxN 100000
using namespace std;

long long  father[maxN], size_of_set[maxN];
map <string, long long > ma;

void init()
{
	for (long long  i = 0; i < maxN; i++) father[i] = i;
	for (long long  i = 0; i < maxN; i++) size_of_set[i] = 1;
	ma.clear();
}

long long  find(long long  x)
{
	return (x == father[x]? x : (father[x] = find(father[x])));
}

bool same_set(long long  x, long long  y)
{
	return (find(x) == find(y));
}

void make_set(long long  i, long long  j)
{
	long long  x = find(i);
	long long  y = find(j);
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
}

main()
{
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	long long  test;
	cin >> test;
	for (long long  k = 0; k < test; k++)
	{
		long long  n;
		long long  m = 0;
		
		init(); 
		cin >> n;
		for (long long  i = 0; i < n; i++)
		{ 
			string s, ss;
			cin >> s >> ss;
			if (ma.find(s) == ma.end()) 
			{
				ma[s] = m;
				m++;
			}
			if (ma.find(ss) == ma.end())
			{
				ma[ss] = m;
				m++;
			}
			if (!same_set(ma[s], ma[ss])) make_set(ma[s], ma[ss]); 
			long long  x = find(ma[s]);
			cout << size_of_set[x] << endl;
		}
	}
}
