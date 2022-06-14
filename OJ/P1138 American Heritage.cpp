#include <iostream>
#include <string>
using namespace std;

void solve(string front, string after);
int main(){
    string front, after;
    while (cin >> after >> front){
        solve(front, after);
        cout << endl;
    }
    return 0;
}


void solve(string front, string after){
    int cha = front.length();
    if (cha == 0)	return;
    if (cha == 1){
        cout << front[0];
        return;
    }
    int temp = after.find(front[0]);
    solve(front.substr(1, temp), after.substr(0, temp));
    solve(front.substr(temp + 1, cha - temp - 1), after.substr(temp + 1, cha - temp - 1));
    cout << front[0];
}

