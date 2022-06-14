# include<stdio.h>

int n, m,s;
void solve(int a,int b);

int main(){
	scanf("%d%d",&n,&m);
	solve(1,1);
	printf("%d\n",s);
	return 0;
}
void solve(int a,int b){
	if (a > m && b > n)		return;
	if (a == m && b == n)
	{
		s++;
		return;
	}
	solve(a + 1, b + 2);
	solve(a + 2, b + 1);
}
