#include <iostream>

using namespace std;

bool tes[9] = {false};
int db[9][9];
bool judge(int x, int y);
int solve(int n); 

int main(){
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            cin >> db[i][j];
            if (db[i][j])
                tes[i] = true;
        }
    cout << solve(0);
    return 0;
}

bool judge(int x, int y){
    for (int i = 0; i < 8; i++){
        if (i != x && db[y][i])
            return false;
        if (i != y && db[i][x])
            return false;
    }
    for (int i = 1; y - i >= 0 && x - i >= 0; i++)
        if (db[y - i][x - i])
            return false;
    for (int i = 1; y + i < 8 && x - i >= 0; i++)
        if (db[y + i][x - i])
            return false;
    for (int i = 1; y - i >= 0 && x + i < 8; i++)
        if (db[y - i][x + i])
            return false;
    for (int i = 1; y + i < 8 && x + i < 8; i++)
        if (db[y + i][x + i])
            return false;
    return true;
}

int solve(int n){
    if (n == 8)
        return 1;
    if (tes[n])
        return solve(n + 1);
    int result = 0;
    for (int i = 0; i < 8; i++){
        if (judge(i, n))
        {
            db[n][i] = 1;
            result += solve(n + 1);
            db[n][i] = 0;
        }
    }
    return result;
}


