#include <iostream>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int n_max = 255, m_max = 250005;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct db{
    int nnex, end;
    long long value;
    db(int N = 0, int E = 0, long long V = 0ll){
        nnex = N;
        end = E;
        value = V;
    }
} etem[m_max << 1];

int n, m, coun = 1;
int ffr[n_max], tp[n_max], start[n_max];
bool flag[n_max];
long long temp, answer, dst[n_max];
priority_queue<pair<long long, int> > q;

void ad_elem(int a, int b, long long l);
void dfunc();
void dfunction();
void doo();

int main(){
    cin >> n >> m;
    int a, b;
    long long l;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> l;
        ad_elem(a, b, l);
        ad_elem(b, a, l);
    }
    dfunc();
    doo();
    cout << answer - temp << endl;
    return 0;
}

void ad_elem(int a, int b, long long l){
    etem[++coun] = db(ffr[a], b, l);
    ffr[a] = coun;
    return;
}

void dfunc(){
    for (int i = 1; i <= n; ++i)
        dst[i] = INF;
    dst[1] = 0ll;
    q.push(make_pair(0, 1));
    while (!q.empty()){
        int x = q.top().second;
        q.pop();
        if (flag[x])
            continue;
        flag[x] = true;
        for (int i = ffr[x]; i; i = etem[i].nnex){
            int y = etem[i].end;
            if (dst[y] > dst[x] + etem[i].value){
                dst[y] = dst[x] + etem[i].value;
                start[y] = i;
                tp[y] = x;
                q.push(make_pair(-dst[y], y));
            }
        }
    }
    temp = dst[n];
    return;
}

void dfunction(){
    for (int i = 1; i <= n; ++i){
        dst[i] = INF, flag[i] = false;
	}
    dst[1] = 0ll;
    q.push(make_pair(0, 1));
    while (!q.empty()){
        int x = q.top().second;
        q.pop();
        if (flag[x]){
            continue;
		}
        flag[x] = true;
        for (int i = ffr[x]; i; i = etem[i].nnex){
            int y = etem[i].end;
            if (dst[y] > dst[x] + etem[i].value){
                dst[y] = dst[x] + etem[i].value;
                q.push(make_pair(-dst[y], y));
            }
        }
    }
    return;
}

void doo(){
    for (int y = 1; y <= n; ++y){
        int x = tp[y], i = start[y];
        etem[i].value <<= 1;
        etem[i ^ 1].value <<= 1;
        dfunction();
        answer = max(answer, dst[n]);
        etem[i].value >>= 1;
        etem[i ^ 1].value >>= 1;
    }
    return;
}
