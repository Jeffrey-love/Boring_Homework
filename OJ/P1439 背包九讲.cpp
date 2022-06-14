#include <iostream>

using namespace std;

int main(){
    int V, N;
    while (cin >> V >> N){
        int *wup = new int[N + 2],*wei = new int[N + 2],*sum = new int[N + 2];
        for(int i = 1; i <= N; i++)	cin >> wup[i] >> wei[i];
        for (int i = 1; i <= N; i++)
            for (int j = V; j >= wup[i]; j--)	sum[j] = max(sum[j], sum[j - wup[i]] + wei[i]);
        cout << sum[V] << endl;
        delete[] wup, wei, sum;
    }
    return 0;
}
