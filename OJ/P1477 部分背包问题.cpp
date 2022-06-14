#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct db{
    double zhong;
    double wei;
    double per;
} sum[102];

bool fun(db m, db n){
    return m.per > n.per;
}

double solve(int n, int d, db sum[]);
 
int main(){
    int n;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> sum[i].zhong >> sum[i].wei;
        sum[i].per = sum[i].wei / sum[i].zhong;
    }
    sort(sum, sum + n, fun);
    cout << fixed << setprecision(2) << solve(n, d, sum);
	cout << endl;
    return 0;
}

double solve(int n, int d, db sum[]){
    double tot = 0, temp = d;
    for (int i = 0; i < n; i++){
        if (temp >= sum[i].zhong){
            temp -= sum[i].zhong;
            tot += sum[i].wei;
        }
        else{
            tot += temp * sum[i].per;
            break;
        }
    }
    return tot;
}
