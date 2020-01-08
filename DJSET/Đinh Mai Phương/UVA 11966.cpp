#include <bits/stdc++.h>
#define vi vector <int>
#define vf vector <float>
using namespace std;

vi size_of_set, father;
vf x,y;
int n;
float m;

bool dis(int i, int j)
{
	float res = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
	return (res <= m * m);
}

void init()
{
	father.assign(n,0);
	for (int i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n,1);
}

int find(int x)
{
	return (x == father[x]? x : (father[x] = find(father[x])));
}

bool same_set(int x, int y)
{
	return (find(x) == find(y));
}

void make_set (int i, int j)
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
}

main(){
	int test;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cin >> n >> m;
		int ans = n;
		x.assign(n,0);
		y.assign(n,0);
		for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
		init();
		 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j && dis(i,j)) 
					if(!same_set(i,j)) 
					{
						make_set(i,j);
						ans--;
					} 
		cout << "Case " << k+1 << ": " << ans << endl;
	}
}
