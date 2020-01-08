#include <bits/stdc++.h>
#define ii pair <int, int>
#define vii vector <ii>
#define x first
#define y second
using namespace std;

int n;
vii hi, lo;

void out()
{
	for (int i = 0; i < hi.size(); i++) printf("%d %d\n", hi[i].x, hi[i].y);
	for (int i = lo.size()-1; i >= 0; i--) printf("%d %d\n", lo[i].x, lo[i].y);
	return;
}

main (){
	//freopen("out.out","w",stdout);
	scanf("%d", &n);
	//printf("%d\n", n);
	if (n & 1)
	{
		printf("NIE\n");
	}
	else
	{
		hi.push_back(ii(0, 2)), hi.push_back(ii(2,2));
		lo.push_back(ii(0, 0)), lo.push_back(ii(2, 0));
		if (n == 4)
		{
			out();
		} 
		else 
		{
			ii t = hi.back();
			hi.pop_back();
			hi.push_back(ii(t.x+2, t.y));
			t = lo.back();
			lo.push_back(ii(t.x, t.y+1)), lo.push_back(ii(t.x+2, t.y+1));
			if (n == 6) out();
			else
			{
				for (int i = 3; 2*i < n; i++)
				{
					if (i & 1)
					{
						ii t = hi.back();
						hi.pop_back();
						hi.push_back(ii(t.x-1, t.y)), hi.push_back(ii(t.x-1, t.y+2)), hi.push_back(ii(t.x, t.y+2));
					}
					else
					{
						ii t = hi.back();
						hi.pop_back();
						hi.push_back(ii(t.x+2, t.y));
						t = lo.back();
						lo.push_back(ii(t.x, t.y+2)), lo.push_back(ii(t.x+2, t.y+2));
					}
				}
				out();
			}
		}
	}
}
