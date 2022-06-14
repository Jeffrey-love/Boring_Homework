#include <algorithm>
#include <iostream>

#include <vector>

using namespace std;

bool function(string m, string j);

int main(){
    int num;
    while(cin >> num) {
        vector<string> db(num, "");
        for(int m=0; m<num; m++){
            cin >> db[m];
        }

        sort(db.begin(), db.end(), function);
        for(int m=0; m<num; m++){
            cout << db[m];
        }
        cout << endl;
    }
}

bool function(string m, string j){
    return (m+j) > (j+m);
}
