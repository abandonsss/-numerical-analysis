#include <stdio.h>
#define msize 100
double v[msize][msize];
double x[msize];
int main()
{
	int n;
	scanf("%d", &n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%lf %lf",&x[i],&v[i][1]);
	}
	for(j=2;j<=n;j++)
	{
		for(i=1;i<=n-j+1;i++) 
		{
			v[i][j]=(v[i+1][j-1]-v[i][j-1])/(x[i+j-1]-x[i]);	
		}	
	}
	for(j=1;j<=n;j++)
	{
		printf("%lf ",v[1][j]);
	}	
	return 0;		
}
