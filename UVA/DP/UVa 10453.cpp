#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int non = 1;
const int lft = 2;
const int rght = 3;

int f[N][N];
int trace[N][N];
string str;

void traced(int start, int en)
{
	if (start > en) return;
	if (start == en)
	{
		printf("%c", str[en]);
		return;
	}
	else if (trace[start][en] == non)
	{
		printf("%c", str[start]);
		traced(start+1, en-1);
		printf("%c", str[en]);
		return;
	} 
	else if (trace[start][en] == rght)
	{
		printf("%c", str[en]);
		traced(start, en-1);
		printf("%c", str[en]);
		return;
	} 
	else if (trace[start][en] == lft)
	{
		printf("%c", str[start]);
		traced(start+1, en);
		printf("%c", str[start]);
		return;
	}
}

int F(int start, int en)
{
	if (start >= en) return 0;
	if (f[start][en] != -1) return f[start][en];
	if (str[start] == str[en]) f[start][en] = F(start+1, en-1), trace[start][en] = non;
	else
	{
		int x = F(start+1, en);
		int y = F(start, en-1);
		if (x <= y)
		{
			f[start][en] = x + 1;
			trace[start][en] = lft;
		}
		else
		{
			f[start][en] = y + 1;
			trace[start][en] = rght;
		}
	}
	return f[start][en];
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	while (cin >> str)
	{
		memset(f, -1, sizeof(f));
		printf("%d ", F(0, str.size() - 1));
		traced(0, str.size() - 1);
		printf("\n");
	}
}
