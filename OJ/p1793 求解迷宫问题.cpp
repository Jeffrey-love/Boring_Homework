#include <iostream>

char migong[8][8];
int h[4] = {0, 1, 0, -1}; 
int v[4] = {-1, 0, 1, 0}; 
int m1 = -1, m2 = -1; 
using namespace std;

struct mig{
    int x, y; 
    int pre;  
};
mig lu[129];  

void show(int m1){
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            if (migong[i][j] == '*')
                migong[i][j] = 'O';
        }
    int k = m1;
    while (k != -1){
        migong[lu[k].x][lu[k].y] = ' ';
        k = lu[k].pre;
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++)	cout << migong[i][j];
        cout << endl;
    }
}

void solve(int x, int y){
    mig p, p1, p2;
    p.x = x, p.y = y;
    p.pre = -1;
    migong[p.x][p.y] = '*'; 
    lu[++m2] = p; 
    while (m1 != m2){
        p1 = lu[++m1];
        if (p1.x == 7 && p1.y == 7){
            show(m1);
            return;
        }
        for (int k = 0; k < 4; k++){
            p2.x = p1.x + h[k];
            p2.y = p1.y + v[k];
            if (p2.x >= 0 && p2.y >= 0 && p2.y < 8 && p2.y < 8 && migong[p2.x][p2.y] == 'O'){
                migong[p2.x][p2.y] = '*';
                p2.pre = m1;
                lu[++m2] = p2;
            }
        }
    }
}

int main(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> migong[i][j];
        }
    }
    solve(0, 0);
    return 0;
}
