#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
using namespace std;

const int maxN = 1e3+5;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dz[4][2] = {{0, 2}, {2, 0}, {1, 3}, {3, 1}};
char mp[256];
int n, m;
ii start, en;
int a[maxN][maxN];
int f[maxN][maxN][4];
char ch;

void init()
{
	mp['+'] = 15;
	mp['-'] = 10;
	mp['|'] = 5;
	mp['^'] = 1;

	mp['>'] = 8;
	mp['<'] = 2;
	mp['v'] = 4;
	mp['L'] = 13;

	mp['R'] = 7;
	mp['U'] = 14;
	mp['D'] = 11;
	mp['*'] = 0;
}

bool outside(int x, int y)
{
	return (x < 1 || y < 1 || x > n || y > m);
}

int rot(int x)
{
	return ((x >> 1) + ((x & 1) << 3));
}

int rotate(int x, int times)
{
	while(times--) x = rot(x);
	return x;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> ch, a[i][j] = mp[ch];
	cin >> start.x >> start.y;
	cin >> en.x >> en.y;
	memset(f, -1, sizeof(f));
	queue <int> qx, qy, qdir;
	qx.push(start.x);
	qy.push(start.y);
	qdir.push(0);
	f[start.x][start.y][0] = 0;
	while(!qx.empty())
	{
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		int d = qdir.front(); qdir.pop();
		if (x == en.x && y == en.y)
		{
			cout << f[x][y][d] << endl;
			return 0;
		}
		// rotate only
		int dd = (d + 1) % 4;
		if (f[x][y][dd] < 0)
		{
			f[x][y][dd] = f[x][y][d] + 1;
			qx.push(x);
			qy.push(y);
			qdir.push(dd);
		}
		// can move to another room
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (outside(nx, ny)) continue;
			int f1 = rotate(a[x][y], d) >> dz[i][0] & 1;
			int f2 = rotate(a[nx][ny], d) >> dz[i][1] & 1;
			//cout << a[x][y] << " " << x << " " << y << "    " << nx << " " << ny <<  "      "  << d << "      " << f1 << "  " << f2 << endl;  
			if (f1 & f2 && f[nx][ny][d] < 0)
			{
				f[nx][ny][d] = f[x][y][d] + 1;
				qx.push(nx);
				qy.push(ny);
				qdir.push(d);
			}
		}
	}
	cout << -1 << endl;
}
