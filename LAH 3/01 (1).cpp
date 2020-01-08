#include <iostream>
#include <stdio.h>
using namespace std;
int n;
char a[21];
//---------------------
void track(int i)
{
	if (i==n+1) 
	{
		for (int i=1;i<=n;i++) cout<<a[i];
		cout<<endl;
		return ;
	}
	else
	{
	a[i]='A';
	track(i+1);
	a[i]='B';
	if (a[i-1]!='B') track(i+1);
	return ;
	}		
}

//---------------------
main(){
	freopen ("01.inp","r",stdin);
	freopen ("01.out","w",stdout);
	cin>>n;
	track(1);
}
