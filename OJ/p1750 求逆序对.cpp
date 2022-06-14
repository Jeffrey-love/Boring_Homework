#include <iostream>

long long int num;
using namespace std;
void mer(int *str, int l, int mid, int r){
    int i = l, j = mid + 1, n = 0;
    int *temp = new int[r - l + 1];
    while (i <= mid && j <= r){
        if (str[i] <= str[j]){
            temp[n++] = str[i++];
        }
        else
        {
            temp[n++] = str[j++];
            num += mid - i + 1;
        }
    }
    
    while (i <= mid)	temp[n++] = str[i++];
    while (j <= r)	temp[n++] = str[j++];
    for (int q = l; q <= r; ++q){
        str[q] = temp[q - l];
    }
    delete[] temp;
}


void chan(int *str, int l, int r){
    if (l >= r) 	return;
    
    int mid = (l + r) / 2;
    chan(str, l, mid);
    chan(str, mid + 1, r);
    mer(str, l, mid, r);
}


int main(){
    int n;
    cin >> n;
    
    int *str = new int[n];
    num = 0;
    for (int i = 0; i < n; i++){cin >> str[i];}
    chan(str, 0, n - 1);
    
    cout << num << endl;
    return 0;
}
