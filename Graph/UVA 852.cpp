#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

char a[10][10],ok[10][10];
int b,w;

int around(int i, int j)
{
	int r = 0;
	if (i<0 || j<0 || i>=9 || j>=9) return r;
	else 
	{
		if (a[i][j] == 'X' ) 
		{
			b++;
			return r;
		}
		else if (a[i][j] == 'O') 
		{
			w++;
			return r;
		}
		else if (ok[i][j] == BLACK) return r;
		else
		{
			r++;
			ok[i][j] = BLACK;
			r+=around(i+1,j);
			r+=around(i-1,j);
			r+=around(i,j+1);
			r+=around(i,j-1);
			return r;
		}
	}
}

main(){
	int test;
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	cin >> test;
	while (test--)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) 
			{
				cin >> a[i][j];
				ok[i][j] = WHITE;
			}
		int black = 0, white  = 0;
	
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (a[i][j] == 'X') black++;
				else if (a[i][j] == 'O') white++;
				else 
				{
					if (ok[i][j] == WHITE)
					{
						b=w=0;
						int x;
						x = around(i,j);
						if (b == 0 && w != 0) white+=x;
						else if (w == 0 && b != 0) black+=x;
					}
				}	 
		cout << "Black " << black << " White " << white << endl;
	}
}
	
