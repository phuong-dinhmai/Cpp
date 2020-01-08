#include <bits/stdc++.h>
#define ii pair <int , int>
#define inf (int) 1e9+7
using namespace std;

typedef struct state 
{
	int x, y, dir, color;
} state;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,m;
	int test = 0;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		test++;
		ii start, end;
		char a[25][25];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == 'S') 
				{
					start.first = i;
					start.second = j;
				}
				if (a[i][j] == 'T') 
				{
					end.first = i;
					end.second = j;
				}
			}
		if (test != 1) cout << endl;
		cout << "Case #" << test << endl;
		
		int time[25][25][4][5];
		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 25; j++)
				for (int k = 0; k < 4; k++)
					for (int h = 0; h < 5; h++) time[i][j][k][h] = inf;
						
		queue <state> q;
	 	time[start.first][start.second][0][0] = 0;
	 	q.push((state) {start.first, start.second, 0, 0});
	 	bool ok = false;
	 	
	 	while (!q.empty())
	 	{
	 		int x = q.front().x;
	 		int y = q.front().y;
	 		int dir = q.front().dir;
	 		int col = q.front().color;
	 		q.pop(); 
	 		int dis = time[x][y][dir][col];
	 		
	 		if (col == 0 && x == end.first && y == end.second) 
	 		{
	 			cout << "minimum time = " << dis << " sec" << endl;
	 			ok = true;
	 			break;
	 		}
	 		
	 		if (time[x][y][(dir+1) % 4][col] == inf) 
			{
			 	time[x][y][(dir+1) % 4][col] =  dis + 1;
				q.push((state) {x,y,(dir+1) % 4, col});
			}
	 		if (time[x][y][(dir+3) % 4][col] == inf) 
			 {
			 	time[x][y][(dir+3) % 4][col] = dis + 1;
			 	q.push((state) {x,y,(dir+3) % 4, col});
			 }
	
	 		col = (col + 1) % 5;
	 		x += dx[dir];
			y += dy[dir];
			if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#' && time[x][y][dir][col] == inf) 
			{
				time[x][y][dir][col] = dis + 1;	
				q.push((state) {x,y,dir,col});
			}
	 	}
	 	if (!ok) cout << "destination not reachable" << endl;
	}
	
}
