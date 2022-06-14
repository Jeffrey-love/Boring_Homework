#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int num_n = 2001;
vector<pair<int, int> > g[num_n];
int nnn, mm1, list_mx;


void func1(){
    list_mx = -1;
    int db[nnn + 1] = {0};
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    int count, sig;
    count = 1, sig = 1;
    while (count < nnn)
    {
        db[sig] = 1; 
        for (int i = 0; i < g[sig].size(); i++)
            q.push(g[sig][i]);

        int dist, w;
        while (true)
        {
            w = q.top().first;
            dist = q.top().second;
            q.pop();
            if (!db[dist])
                break;
        }
       
        list_mx = max(list_mx, w);
        sig = dist;
        count++;
    }
}

int main(){
    cin >> nnn >> mm1;
    int u1, v, w;
    for (int i = 1; i <= mm1; i++){
        cin >> u1 >> v >> w;
        g[v].push_back(make_pair(w, u1));
        g[u1].push_back(make_pair(w, v));
    }
    func1();
    cout << list_mx << endl;
}


