#include<stdio.h>

int main(){
	long long int st, sum;
	int time, a[11][11];
	int i, j, cou;
	while (~scanf("%d", &time)){
		for (i = 0; i < time; i++)for (j = 0; j < time; j++)	scanf("%d", &a[i][j]);
		scanf("%lld", &st); 
		st++;
		cou = st % 4;st /= 4;
		for (i = 0; i < time; i++){
			for (j = 0; j < time; j++){
				sum = a[i][j] + a[time - j - 1][i] + a[time - i - 1][time - j - 1]
					+ a[j][time - i - 1];
				sum *= st;
				switch (cou){
					case 3:
						sum += a[time - i - 1][time - j - 1];
					case 2:
						sum += a[time - j - 1][i];
					case 1:
						sum += a[i][j];
					
				}
				printf("%lld ", sum);
			}
			printf("\n");
		}
	}
	return 0;
}
