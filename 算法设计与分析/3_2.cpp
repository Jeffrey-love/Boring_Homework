#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    int n,i,j,k;
    cin>>a>>n;
    int len=a.size();
    for(k=0;k<n;k++){
        for(i=0;i<len-1;i++){
            if(a[i]>a[i+1]){
                for(j=i;j<len-1;j++)
                    a[j]=a[j+1];
                break;
            }
        }
        len--;
    }
    i = 0;	//处理开头是0的情况 
    while(i<=len-1&&a[i]=='0')	i++;

    for(j=i;j<=len-1;j++)
            cout<<a[j];
}
