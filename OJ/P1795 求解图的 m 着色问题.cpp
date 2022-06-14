#include<iostream>
using namespace std;

int bian, dian, type;
int answer;
int colour[400];
int db[400][400];

int fun(int p, int color);
void solve(int vec);

int main(){
    cin >> dian >> bian >> type;
    int i;
    for (i = 1; i <= bian; i++){
        int a, b;
        cin >> a >> b;
        db[a][b] = 1;
        db[b][a] = 1;
    }
    solve(1);
    cout << answer << endl;
    return 0;
}

void solve(int vec){
    if (vec > dian){
        answer++;
        return;
    }
    int i;
    for (i = 1; i <= type; i++)
        if (fun(vec, i)){
            colour[vec] = i;
            solve(vec + 1);
            colour[vec] = 0;
        }
}

int fun(int p, int color){
    for (int i = 1; i <= dian; i++)
        if (db[p][i] == 1 && color == colour[i])     return 0;
    return 1;
}


