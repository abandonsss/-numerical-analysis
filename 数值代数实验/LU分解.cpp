#include <stdio.h>
void gauss(double (*a)[100],int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			a[j][i]/=a[i][i];
			for(k=i+1;k<=n;k++)
			{
				a[j][k]-=a[j][i]*a[i][k];
			}
		}
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	double a[100][100];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	gauss(a,n);
	for(i;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%lf ",a[i][j]);
		}
		printf("\n");
	}
	return 0;	
}
