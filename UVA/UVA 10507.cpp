#include <bits/stdc++.h>
using namespace std;

main(){
	
	while (cin >> n >> m)
	{
		char x,y,z;
		cin >> x >> y >> z;
		wake[x - 'A'] = wake[y - 'A'] = wake[z - 'A'] = true;
		for (int i = 0; i < m; i++)
		{
			char x,y;
			cin >> x >> y;
			x -= 'A';
			y -= 'A';
			edge[x][y] = 1;
			edge[y][x] = 1;
		}
		while(1)
		{
			if (res == n) break;
			if (year == maxN) break;
		 	year++;
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++)
				{
					if (edge[i][j])
						if (wake[i] && !wake[j]) connect[j]++;
					if (connect[j] == 3)
					{
						res++;
						wake[j] = true;
					}
				}
		}
		if (year == maxN) cout << "THIS BRAIN NEVER WAKES UP" << endl; else cout << "WAKE UP IN, " << year << ", years" << endl;
	}
}
