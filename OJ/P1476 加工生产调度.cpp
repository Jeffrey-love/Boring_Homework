#include <iostream>
#include <algorithm>
using namespace std;

struct num{
    int tim, li;
};

bool db_num(num x, num y){
    return x.tim < y.tim;
}

int main(){
    int n;
    while (cin >> n){
        int *db1 = new int[n],*db2 = new int[n],*list = new int[n];
        num *temp = new num[n];
        for (int i = 0; i < n; i++)    cin >> db1[i];

        for (int i = 0; i < n; i++){
            cin >> db2[i];
            temp[i].tim = min(db1[i], db2[i]);
            temp[i].li = i;
        }
        sort(temp, temp + n, db_num);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++){
            if (temp[i].tim == db1[temp[i].li])
                list[l++] = temp[i].li;
            else
                list[r--] = temp[i].li;
        }
        int ans = db1[list[0]];
        for (int i = 1; i < n; i++){
            if (db1[list[i]] < db2[list[i - 1]])
                db2[list[i]] = db2[list[i]] + db2[list[i - 1]] - db1[list[i]];
            ans += db1[list[i]];
        }
        ans += db2[list[n - 1]];
        cout << ans << endl;
        delete[] db1,db2,list,temp;
    }
    return 0;
}
