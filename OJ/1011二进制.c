#include<stdio.h>

int main()
{
	int p[20]={0};
	int num,i,j,count;
	
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		
		if(num==1)
		{
			printf("1\n");
			continue;
		}
		for(j=0;num>=1;j++)
		{
			if(num%2==0)
			{
				p[j]=0;
				num/=2;
			}
			else if(num%2==1)
			{
				p[j]=1;
				num/=2;
			}
		}
		
		for(;j>0;j--)
			printf("%d",p[j-1]);
		printf("\n");


	}
	return 0;
}
