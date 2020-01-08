#include <bits/stdc++.h>
#define WHITE 0
#define BLACK 1
#define RED -1
#define vi vector <long long>
#define maxN 10000
using namespace std;

vi a[maxN];

bool have(int x, int y)
{
	for (int i = 0; i < a[x].size(); i++)
		if (a[x][i] == y) return true;
	return false;
}

main(){
	int test;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);

	cin >> test;
	for (int k = 0; k < test; k++)
	{
		//getchar();
		int n;
		int mx = 0;
		cin >> n;
		for (int i = 0; i < maxN; i++) a[i].clear();
		for (int i = 0; i < n; i++)
		{
			long long  m;
			cin >> m;
			for (long long j = 0; j < m; j++)
			{
				int x;
				cin >> x;
				x--;
				if (!have(x,i)) a[x].push_back(i);
				if (!have(i,x)) a[i].push_back(x);
			}
		}

		vi color(n, WHITE);
		for(int i = 0; i < n; i++)
			if (color[i] == WHITE)
			{
				bool done = true;
				queue <int> ok;
				ok.push(i);
				color[i] = RED;
				int ans1 = 0, ans2 = 1;
				while (!ok.empty())
				{
					int x = ok.front();
					ok.pop();
					for (int j = 0; j < a[x].size(); j++)
						if (color[a[x][j]] == WHITE)
						{
							if (color[x] == BLACK)
							{
								color[a[x][j]] = RED;
								ans2++;
							}
							else
							{
								color[a[x][j]] = BLACK;
								ans1++;
							}
							ok.push(a[x][j]);
						}
						else
							if (color[x] == color[a[x][j]])
							{
								done = false;
							}
				}
				if (done) mx += max(ans1, ans2);
			}
		cout << mx << endl;
	}

}
