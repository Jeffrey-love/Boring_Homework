#include <iostream>

using namespace std;
//扩展欧几里得算法
//注意a > b，懒得做比较啦> <
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
    printf("×î´ó¹«Ô¼Êý£º%d, x = %d , y = %d",l, x, y);
    return 0;
}
