#include<bits/stdc++.h>

using namespace std;

typedef struct {
	int tele; 
	int value1;
}list1;
int main(){
	int m,n;
	while(cin>>m>>n){
		int i,j;
		list1 dp[10000];
		int tmp[10000]={};
		for(i=0;i<n;i++){
			cin>>dp[i].tele>>dp[i].value1;
		}
	for(i=0;i<n;i++){
		for(j=m;j>=dp[i].tele;j--){
			tmp[j]=(tmp[j-dp[i].tele]+dp[i].value1>tmp[j]?tmp[j-dp[i].tele]+dp[i].value1:tmp[j]);
		}
	}
	printf("%d\n", tmp[m]);
	}
	return 0;
}

