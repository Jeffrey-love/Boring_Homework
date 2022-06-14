#include <bits/stdc++.h>

using namespace std;

int main(){
    int number, tmp;
    while(cin >> number){
        cin >> tmp;
        int* db1 = new int[tmp + 2];
        int* db2 = new int[tmp + 2];
        int* sum = new int[tmp + 2];
        for (int i = 1; i <= tmp; i++){
            cin >> db1[i] >> db2[i];
		}
        for (int i = 1; i <= tmp; i++){
            for (int j = number; j >= db1[i]; j--){
                sum[j] = max(sum[j], sum[j - db1[i]] + db2[i]);
			}
		}
 		printf("%d\n", sum[number]);
	}
    return 0;
}

