#include <bits/stdc++.h>
#define maxN (5000001)
using namespace std;

int num[maxN];
int sum[maxN];
int a, b;
bool ok[maxN];

bool prime(int num)
{
	if (num < 2) return false;
	for (int j = 2; j*j <= num; j++)
		if (num % j == 0) return false;
	return true;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	fill(ok, ok + maxN, 0);
	for (int i = 2; i < maxN; i++)
	{
		if (!ok[i])
		{
			for (int j = i; j < maxN; j += i) 
			{
				sum[j] += i;
				ok[j] = 1;
			}
		}
	}
	for (int i = 1; i < maxN; i++)
		{
			num[i] = num[i-1] + prime(sum[i]);
 		}
	while (scanf("%d", &a) && a != 0)
	{
		scanf ("%d", &b);
		printf("%d\n", num[b] - num[a-1]);
	}
}
