#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define vfi vector <pair <float, ii> >
using namespace std;

float d[201][201];
vi x,y;
int n,m;

void init()
{
	x.assign(n,0);
	y.assign(n,0);
}

float dis(int i, int j)
{
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

void input()
{
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			float r = dis(i,j);
			d[i][j] = r;
		}
		
}

main()
{
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test = 0;
	while (cin >> n)
	{
		if (n == 0) break;
		test++;
		init();
		input();
		
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) 
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
		
		cout << "Scenario #" << test << endl;
		cout << "Frog Distance = " << setprecision(3) << fixed << d[1][0] << endl;
		cout << endl;
	}
}
