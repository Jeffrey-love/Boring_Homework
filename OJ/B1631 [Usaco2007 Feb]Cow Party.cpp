#include <iostream>
#include <algorithm>
#define max_num 1024
#define INF 0xffffff

using namespace std;

int db[max_num][max_num], n;
int dist[max_num], temp[max_num];
void solve(int x);

int main(){
    int g, x;
    cin >> n >> g >> x;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i != j){
                db[i][j] = INF;
            }
            else{
                db[i][j] = 0;
            }
        }
    }
    int k, v, w;
    while (g--){
        cin >> k >> v >> w;
        if (w < db[k][v])
            db[k][v] = w;
    }
    solve(x);
    for (int i = 1; i <= n; ++i)
        dist[i] = temp[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            int temp;
            temp = db[j][i];
            db[j][i] = db[i][j];
            db[i][j] = temp;
        }
    }
    solve(x);
    for (int i = 1; i <= n; ++i){
        if (i != x)
            ans = max(ans, dist[i] + temp[i]);
    }
    cout << ans << endl;
    return 0;
}

void solve(int x){
    int visit[max_num] = {0};
    int min, next = x;
    for (int i = 1; i <= n; ++i)
        temp[i] = db[x][i];
    visit[x] = 1;
    for (int i = 2; i <= n; ++i){
        min = INF;
        for (int j = 1; j <= n; ++j){
            if (!visit[j] && temp[j] < min){
                min = temp[j];
                next = j;
            }
        }
        visit[next] = 1;
        for (int j = 1; j <= n; ++j){
            if (!visit[j] && temp[j] > temp[next] + db[next][j])
                temp[j] = temp[next] + db[next][j];
        }
    }
}


