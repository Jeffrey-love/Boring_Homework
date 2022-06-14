#include<bits/stdc++.h>
using namespace std;
int n, m, k, i, j, t;

int a[10001], dp[10001];
void func1();

int main(){
	cin >> t;
	while (t--){
		func1();
	}
	return 0;
}

void func1(){
	while (scanf("%d", &n) != EOF){
		for (i = 1; i <= n; i++){
			a[i] = 0;
			dp[i] = 99999;
		}
		cin >> m >> k;
		for (i = 0; i < m; i++){
			scanf("%d", &j);
			a[j] = 1;
		}
		dp[1] = a[1];
		for (i = 1; i <= n; i++){
			for (j = 1; j <= k; j++){
				if (i + j > n){
					break;
				}
				if (dp[i] + a[i + j] < dp[i + j]){
					dp[i + j] = dp[i] + a[i + j];
				}
			}
		}
		cout << dp[n] << endl;
	}
}

