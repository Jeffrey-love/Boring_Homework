#include <cstring>
#include <iostream>

#define max_numb 1000
using namespace std;
int number1;
int list1[max_numb][max_numb];
int db[max_numb];
int ni1, hahm; 
int max_li;
bool function1(int i, int j);
void func1(int i);
int main(){
    while (cin >> ni1 >> hahm)
    {
        number1 = 0;
        max_li = 0;
        memset(list1, 0, sizeof(list1));
        memset(db, 0, sizeof(db));
        int ahahmm, b;
        for (int k = 0; k < hahm; k++)
        {
            cin >> ahahmm >> b;
            list1[ahahmm][b] = 1;
            db[b]++;
        }
        for (int k = 1; k <= ni1; k++)
            if (db[k] == 0)
                func1(k);
        cout << max_li+1 << endl;
    }
    return 0;
}

bool function1(int i, int j){
    if (list1[i][j] == 1)
        return true;
    return false;
}

void func1(int i){

    for (int j = 1; j <= ni1; j++)
    {
        if (function1(i, j)) 
        {
            number1++;
            func1(j);
            number1--;
        }
        else
        {
            if (number1 > max_li)
                max_li = number1;
        }
    }
}


