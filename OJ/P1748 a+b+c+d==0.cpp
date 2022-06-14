#include<iostream>
#include<algorithm>

using namespace std;

int answ[40000];
int sum;
void fun(int x,int len);

int main(){
    int k1;
    scanf("%d",&k1);
    while (k1--){
        int n;
        scanf("%d",&n);
        int lis[2000][10];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 4; j++)
                cin >> lis[i][j];
        int h=1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                answ[h] = lis[i][1] + lis[j][2];
                h++;
            }
        sort(answ + 1, answ + h);
        int len;
        len = h ;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int answ = lis[i][3] + lis[j][4];
                fun(-answ, len);
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

void fun(int x,int len){
    int left = 1, right = len-1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (answ[mid] == x){
            sum++;
            int i=mid,j=mid;
            while (answ[i - 1] == x){
                sum++;
                i--;
            }
            while (answ[j + 1] == x){
                sum++;
                j++;
            }
            return;
        }
        else if (answ[mid] > x)       right = mid - 1;
        else    left = mid + 1;
    }
    return;
}


