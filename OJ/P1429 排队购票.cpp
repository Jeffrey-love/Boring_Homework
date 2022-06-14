#include<iostream>

using namespace std;

int a,b;
int solve(int a,int b);

int main(){
    while(cin >> a >> b){
        int ans;
		ans = solve(a,b);
        cout << ans << endl;
    }
    return 0;
}

int solve(int a,int b){
    if(b == 0)
        return 1;
    if(a < b)
        return 0;
    return solve(a - 1,b) + solve(a ,b - 1);
}
