#include <bits/stdc++.h>
#define WHITE 1
#define GRAY 0
#define BLACK -1
using namespace std;

int ans,n,m,mx=0;
char s[25][25],check[25][25];

void dfs(int i, int j)
{
	if (i<0 || j<0 || i>=n || s[i][j] == '\0') return;
	
	if (s[i][j] == '0' || check[i][j] == BLACK) return;
	else
	{
		ans++;
		check[i][j] = BLACK; 
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i+1,j);
		dfs(i-1,j);
		dfs(i+1,j+1);
		dfs(i+1,j-1);
		dfs(i-1,j+1);
		dfs(i-1,j-1);
	}
}

main(){
	int test; 
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	scanf ("%d",&test);
	getchar();
	getchar();
	for (int k=0; k<test; k++)
	{
		n=0;
        memset(s,'\0',sizeof(s));
        memset(check,WHITE,sizeof(check));
        if(k!=0) cout << endl;

        while(gets(s[n]))
        {
            if(s[n][0]=='\0')
                break;
            n++;
        }
        
        mx = 0;
		for (int i=0; i<n; i++)
			for (int j=0; s[i][j] != '\0'; j++)
			{
				if (s[i][j] == '1')  
					{
						ans = 0;
						dfs(i,j);
						mx=max(mx,ans);
					}
			}
		cout << mx << endl;
	}
	return 0;
}
