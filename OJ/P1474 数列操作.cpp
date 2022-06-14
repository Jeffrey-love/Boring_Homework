#include<queue>
#include<iostream>

#define max_number 30
using namespace std;
int list1[max_number];
void func1(priority_queue <long long,vector<long long>,greater<long long> > qqq,int num); 

int main(){
    int num;
    while(cin>>num)
    {
        priority_queue<long long,vector<long long>,greater<long long> > qqq;
        for(int k=0;k<num;k++)
        {
            cin>>list1[k];
            qqq.push(list1[k]);
        }
        func1(qqq,num);
    }
    return 0;
}


void func1(priority_queue <long long,vector<long long>,greater<long long> > qqq,int num){
    long long a,b;
    for(int k=1;k<num;k++)
    {
        a=qqq.top();
        qqq.pop();
        b=qqq.top();
        qqq.pop();
        qqq.push(a*b+1);
    }
    cout<<qqq.top()<<endl;
}


