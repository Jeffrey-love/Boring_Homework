#include <bits/stdc++.h>
#define INF 1e9 + 5
using namespace std;
const int maxn = 105;
const int maxm = 1005;
int mp[maxn][maxn];
int m,n,q;
void init()
{
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(i == j) mp[i][j] = 0;
			else       mp[i][j] = INF;
}
 
void floyd()
{
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				mp[i][j] = min(mp[i][j],max(mp[i][k],mp[k][j]));
}
 
int main(void)
{
	int a,b,c;
	int ncase = 0;
	while(scanf("%d %d %d",&n,&m,&q) != EOF && n + m + q){
		init();
		while(m--){
			scanf("%d %d %d",&a,&b,&c);
			mp[a][b] = mp[b][a] = c;
		}
		floyd();
		printf("Case #%d\n",++ncase);
		while(q--){
			scanf("%d %d",&a,&b);
			if(mp[a][b] == INF) printf("no path\n");
			else 				printf("%d\n",mp[a][b]);
		}
	}
	return 0;
}

