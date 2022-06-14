#include<iostream>
#include<cstdio>

using namespace std;

const int num_max=999999,INF=0x3f3f3f3f,fri=998244353;

int fro[num_max], tb[num_max];
int solve(int x);
int fun(int n);

int main() {
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> tb[i] ;
		fro[i]=i;
	}
	for(int i=1;i<=n;++i) {
		int a=solve(i), c=solve(tb[i]);
		if(a!=c)fro[a]=c;
	}
	int cnt=0;
	for(int i=1;i<=n;++i) {
		if(fro[i]==i) cnt++;
	}
	printf("%d",fun(cnt)-1);
	return 0;	
}

int solve(int x) {
	while(x!=fro[x])x=fro[x]=fro[fro[x]];
	return x;
}
int fun(int n) {
	int ans=1,b2=2;
	for(int i=1;i<=n;++i) {
		ans=(ans*b2)%fri;
	}
	return ans;
}


