#include<stdio.h>
#define min(a,b) (((a)>(b))?(b):(a))
#define N 1000

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		int a[N][N];

		for(i=0;i<n;i++)
		{	for(j=0;j<=i;j++)
			{	scanf("%d",&a[i][j]);
			}					
		}
		//////////////完成输入操作 //////////////

		for(i=n-2;i>=0;i--)
		{	for(j=0;j<=i;j++)
			{	a[i][j]+=min(a[i+1][j],a[i+1][j+1]);
			}
		}
		printf("%d\n",a[0][0]);
	}
	
	return 0;
}
