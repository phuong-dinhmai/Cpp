#include <bits/stdc++.h>
#define inf (int) (1e9+7)
#define maxN 10005
using namespace std;

bool prime(int num)
{
	if (num < 2) return false;
	for (int j = 2; j *j <= num; j++)
		if (num % j == 0) return false;
	return true;
}
main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	int test, n;
	int a[maxN];
	int sum[maxN];
	sum[0] = 0;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		int best = inf;
		int start = 0, en = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++)
			{
				int x = sum[i] - sum[j-1];
				if (prime(x) && best > (i-j+1))
				{
					best = i-j+1;
					start = j; 
					en = i;
				}
			}
		if (best == inf) printf("This sequence is anti-primed.\n");
		else 
		{
			printf("Shortest primed subsequence is length %d: ", best);
			//cout << start << " " << en << endl;
			for (int i = start; i < en; i++) cout << a[i] << " ";
			printf("%d\n", a[en]);
		}
		
	}
}
