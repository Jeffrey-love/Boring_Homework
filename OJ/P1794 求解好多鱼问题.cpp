#include<bits/stdc++.h>
using namespace std;
long long db[100000];

int main(){
    int a;
	int b;
	int number1;
    
    cin >> b >> a;

    cin >> number1;
    
    int Fish_Size[100000];
    
    for (int i = 0; i < number1; i++){
        cin >> Fish_Size[i];
        for (int t = 2 * Fish_Size[i]; t <= 10 * Fish_Size[i]; t++)
            db[t] = 1;
        for (int t = Fish_Size[i] / 10; t <= Fish_Size[i] / 2; t++)
            db[t] = 1;
    }
    int ans = 0;
    for (int t = b; t <= a; t++)
        if (db[t] == 0)
            ans++;
    cout << ans << endl;
    return 0;
}

