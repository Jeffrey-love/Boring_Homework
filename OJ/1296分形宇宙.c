#include<stdio.h>
#include<math.h> 
char pp[1000][1000];
void print(int n,int x,int y){
	int size=pow(3.0,n-2);
	if(n==1){
		pp[x][y]='X';
	}
	else{
		print(n-1,x,y);	//			左上角
		print(n-1,x,y+2*size);//					右上角
		print(n-1,x+size,y+size);//			中间
		print(n-1,x+2*size,y);//	左下角 
		print(n-1,x+2*size,y+2*size);//				右下角 
	}
	
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		int i,j,size;
		size=pow(3.0,n-1);
		for(i=1;i<=size;i++)
			for(j=1;j<=size;j++)
				pp[i][j]=' ';
		
		print(n,1,1);
		
		for(i=1;i<=size;i++){
			for(j=1;j<=size;j++)
				printf("%c",pp[i][j]);
			printf("\n");	
		}
		printf("-\n"); 
	}
	return 0;
}



