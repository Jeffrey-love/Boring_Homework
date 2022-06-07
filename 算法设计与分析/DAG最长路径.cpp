#include<stdio.h>
#define N 1000
#define INF 0x7ffffff

int g[N][N];
int n;

void Floyd(){
    int k,i,j;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=k&&j!=i&&j!=k&&g[i][k]&&g[k][j])
                    if(g[i][j]<g[i][k]+g[k][j])
                        g[i][j]=g[i][k]+g[k][j];
}

int main(){
    int m,i;
    scanf("%d%d",&n,&m);
 	g[0][0]=0;
 	for(i=0 ; i < m ; i++){
 		int a,b;
 		scanf("%d%d",&a,&b);
 		scanf("%d",&g[a][b]);
	}
    Floyd();
 	int s,t;
 	scanf("%d%d",&s,&t);
    int res=-INF;
    printf("%d\n",g[s][t]);
 
    return 0;
}
