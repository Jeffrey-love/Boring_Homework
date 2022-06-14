#include<bits/stdc++.h>
#define Max 1000

using namespace std;
 
int list1[Max];
 
int main(){
	int i,j,m,tmp,lis1[Max],lis2[Max];
	while(cin>>m>>tmp){
		int M=0;
		for(i=0;i<=tmp;i++)	{
			list1[i]=0;
		}
		for(i=1;i<=m;i++){
			cin>>lis1[i]>>lis2[i];
		}
		for(i=1;i<=m;i++){
			for(j=lis1[i];j<=tmp;j++){
				list1[j]=max(list1[j],list1[j-lis1[i]]+lis2[i]);
				M=list1[j];
			}
		}
	printf("%d\n",M);
	}
	return 0;
}

