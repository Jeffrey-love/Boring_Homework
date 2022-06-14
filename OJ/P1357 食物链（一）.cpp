#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;

int array[MAX][MAX];
int n, m; 
int num;
int MAXL;
int X[MAX];
bool compare(int i, int j)
{
    if (array[i][j] == 1)
        return true;
    return false;
}

void DFS(int i)
{

    for (int j = 1; j <= n; j++)
    {
        if (compare(i, j)) 
        {
            num++;
            DFS(j);
            num--;
        }
        else
        {
            if (num > MAXL)
                MAXL = num;
        }
    }
}
int main()
{
    while (cin >> n >> m)
    {
        num = 0;
        MAXL = 0;
        memset(array, 0, sizeof(array));
        memset(X, 0, sizeof(X));
        int x, y;
        for (int k = 0; k < m; k++)
        {
            cin >> x >> y;
            array[x][y] = 1;
            X[y]++;
        }
        for (int k = 1; k <= n; k++)
            if (X[k] == 0)
                DFS(k);
        cout << MAXL+1 << endl;
    }
    return 0;
}

