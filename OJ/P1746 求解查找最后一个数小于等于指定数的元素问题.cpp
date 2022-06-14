#include <iostream>

using namespace std;

int main(){
    int a, b, ans;
    while(cin >> b >> a){
    	int i,*arr = new int[b];
        for (i = 1; i <= b; i++)	cin >> arr[i];
        for (i = 1; i <= a; i++){
            scanf("%d",&ans);
            int temp = 0, t = b - 1, in;
            while (temp <= t){
                in = (temp + t) / 2;
                if (arr[in] <= ans){
                    temp = in + 1;
				}
                else{
                    t = in - 1;
				}
            }
            ans = -1;
            if (t >= 0){
                ans = arr[t];
            }
            cout << ans << endl;
        }
        delete[] arr;
    }
    return 0;
}
