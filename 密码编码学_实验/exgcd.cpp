#include <iostream>

using namespace std;

int exgcd(int a, int b, int *x, int *y){
    if(b==0){
        *x = 1;
        *y = 0;
        return a;
    }
    int gcd = exgcd(b, a%b, y, x);
    *y -= (a/b) * *x; 
    return gcd;
}

int main(){
    int a, b, x, y, l;
    cin >> a >> b;
    l = exgcd(a, b, &x, &y);
    printf("最大公约数：%d, x = %d , y = %d",l, x, y);
    return 0;
}