#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f,mo1 = 1e9 + 7,MAX_Num = 1e5 + 10;

struct db{
    int at;
    int after;
    int val;
} e[16200];

int n, m, s, k;
int front[3000];
int Count;
int dist[3000];

struct solve{
    bool operator()(int x, int y){
        return dist[x] > dist[y];
    }
};

void add_num(int a1, int b2, int k);
void dfunc();

int main(){
    cin >> n >> m;
	cin >> s >> k;
    memset(dist, INF, sizeof(dist));
    memset(front, -1, sizeof(front));
    int i;
    for(i = 0; i < m; i++){
        int a1, b2, w;
        cin >> a1 >> b2 >> w;
        add_num(a1, b2, w);
        add_num(b2, a1, w);
    }
    dfunc();
    cout << dist[k] << endl;
    return 0;
}

void dfunc(){
    priority_queue<int, vector<int>, solve> qe;
    dist[s] = 0;
    qe.push(s);
    while (!qe.empty()){
        int a1 = qe.top();
        qe.pop();
        for (int i = front[a1]; i != -1; i = e[i].after){
            int b2 = e[i].at;
            if (dist[a1] + e[i].val < dist[b2]){
                dist[b2] = dist[a1] + e[i].val;
                qe.push(b2);
            }
        }
    }
}

void add_num(int a1, int b2, int k){
    e[Count].at = b2;
    e[Count].val = k;
    e[Count].after = front[a1];
    front[a1] = Count++;
}
