#include <bits/stdc++.h>
#define ii pair <long long, long long>
#define vi vector <long long>
#define vfi vector <pair <double, ii> >
using namespace std;

vfi edge;
vi father, size_of_set;
long long n, m;
vi x, y;

void init()
{
	father.assign(m,0);
	x.assign(m,0);
	y.assign(m,0);
	for (long long i = 0; i < m; i++) father[i] = i;
	size_of_set.assign(m,1);
	edge.clear();
}

double dis (long long i, long long j)
{
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

void input()
{
	for (long long i = 0; i < m; i++) cin >> x[i] >> y[i];
	for (long long i = 0; i < m; i++)
		for (long long j = 0; j < m; j++)
			if (i != j) 
			{
				double r = dis(i,j);
				edge.push_back(make_pair (r, ii(i,j)));
			}
	sort(edge.begin(), edge.end());	
}

long long find(long long x)
{
	return (x == father[x]? x : (father[x] = find(father[x])));
}

bool same_set(long long x, long long y)
{
	return (find(x) == find(y));
}

void make_set(long long i, long long j)
{
	long long x = find(i);
	long long y = find(j);
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

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	long long test;
	cin >> test;
	while (test--)
	{
		cin >> n >> m;
		init();
		input();
		long long ans = m;
		double mx = 0;
		
		for (long long i = 0; i < edge.size(); i++) 
			if(!same_set(edge[i].second.first, edge[i].second.second))
			{
				make_set(edge[i].second.first, edge[i].second.second); 
				if (ans != n) 
				{
					mx = edge[i].first;
					ans--;
				}
				else break;
			}
			
		cout <<  setprecision(2) << fixed << mx << endl;
	}
}
