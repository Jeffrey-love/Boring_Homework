#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n,m;
    while(cin>>n>>m){
        priority_queue<pair<long long,long long> >lisq;
        long long a,b;
        for(int item=0;item<n;item++){
            cin>>a>>b;
            pair<long long,long long> t (min(a,b),max(a,b));
            lisq.push(t);
        }
        
        long long elem=0;
        while(m&&!lisq.empty()){
            a=lisq.top().first;
            b=lisq.top().second;
            elem+=a*a;

            lisq.pop();
            b-=a;
            pair<long long,long long>t(min(a,b),max(a,b));
            lisq.push(t);
            m--;
        }
        cout<<elem<<endl;
    }
    return 0;
}

