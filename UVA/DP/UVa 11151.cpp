#include <bits/stdc++.h>
#define maxN 1005
using namespace std;

int test;
int f[maxN][maxN];
char str[maxN];

void init()
{
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++) f[i][j] = -1;
}

int F(int start, int en)
{
	if (start == en) return f[start][en] = 1;
	if (f[start][en] != -1) return f[start][en];
	if (start + 1 == en) 
		if (str[start] != str[en]) return f[start][en] = 1; else return f[start][en] = 2;
	if (str[start] == str[en]) return f[start][en] = F(start+1, en-1) + 2;
		else return f[start][en] = max(F(start+1, en), F(start, en-1));
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	scanf("%d", &test);
	getchar();
	while(test--)
	{
		gets(str);
		if (strlen(str) == 0) 
		{
			printf("0\n"); continue;
		}
		init();
		printf("%d\n", F(0, strlen(str) - 1));
	}
}
