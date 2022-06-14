#include<bits/stdc++.h>

using namespace std;
void fuinc1(int db1[],int db2[],int setN);

int main(){
    int setN;
    while(cin>>setN){
        int db1[100000],db2[100000];
        for(int i=0;i<setN;i++){
            cin>>db1[i];
		}
        for(int i=0;i<setN;i++){
            cin>>db2[i];
		}
        sort(db1,db1+setN);
        sort(db2,db2+setN);
        fuinc1(db1,db2,setN);
    }
    return 0;
}

void fuinc1(int db1[],int db2[],int setN){
    int num_1=0;
    int n1=0,n2=0;
    int m1=setN-1,m2=setN-1;

    while(n1<=m1){
        if(db1[m1]>db2[m2]){
                num_1+=200;
                m1--;
                m2--;
            }
        else if(db1[m1]<db2[m2]){
            num_1-=200;
            n1++;
            m2--;
        }
        else{
            if(db1[n1]>db2[n2]){
                num_1+=200;
                n1++;
                n2++;
            }
            else{
                if(db1[n1]<db2[m2])
                    num_1-=200;
                n1++;
                m2--;
            }
        }
    }
    printf("%d\n",num_1);
}



