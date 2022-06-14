#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int N, numb, maxnum, ans;
    while (cin >> N){
        maxnum = 0;
        ans = 0;
        for (int i = 0; i < N; i++){
            cin >> numb;
            ans += numb;
            maxnum = max(maxnum, numb);
        }
        double a;
        if(maxnum > ans - maxnum){
        	a = (double)(ans - maxnum);
		}
		else{
			a = (double)ans / 2.0;
		}
        cout << fixed << setprecision(1) << a << endl;
    }
    return 0;
}
