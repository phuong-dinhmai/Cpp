#include <bits/stdc++.h>
using namespace std;

int bd[3][3];

int solve()
{
	int m[8];
	m[0] = bd[1][2];
	m[1] = bd[0][2];
	m[2] = bd[0][1];
	m[3] = bd[0][0];
	m[4] = bd[1][0];
	m[5] = bd[2][0];
	m[6] = bd[2][1];
	m[7] = bd[2][2];
	
	bd[1][1] = (bd[1][1]+5)%8;
	int pre = bd[1][1];
	
	for(;;)
	{
		if (m[bd[1][1]] == 0)
		{
			pre = bd[1][1];
			bd[1][1] = (bd[1][1]+1) %8;
		}
		if (m[bd[1][1]] == 1)
		{
			pre = bd[1][1];
			bd[1][1] = (bd[1][1]+7)%8;
		}
		if (m[pre] != m[bd[1][1]])
			if (m[pre] == 1) return pre; else return bd[1][1];
	}

}

main(){
	int x, y, dir;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> x)
	{
		if (x == -1) break;
		cin >> y >> dir;
		bd[1][1] = dir;
		for (int i = 0; i < 8; i++)
		{
			int a,b,k;
			cin >> a >> b >> k;
			bd[a - x + 1][b- y + 1] = k;
		}
		cout <<  solve() << endl;
	}
}
