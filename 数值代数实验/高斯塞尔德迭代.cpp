#include <stdio.h>
#include <math.h>
#define n 3
#define K 100
int main() {
	double a[n+1][n+1];
	double b[n+1];
	double x1[n+1];
	double x2[n+1];
	double err=10000.0;
	double eps=1e-5;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lf ",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		x1[i]=0;
		scanf("%lf",&b[i]);
	}
	int k=0;
	while(k<K && err>eps)
	{
		err=0.0;
		k++;
		for(i=1;i<=n;i++)
		{
			double ret=b[i]; 
			for(j=1;j<=n;j++)
			{
				if(i<j)
				{
					ret-=a[i][j]*x1[j];
				}
				if(i>j)
				{
					ret-=a[i][j]*x2[j];
				}
			}
			x2[i]=ret/a[i][i];
		}
		for(i=1;i<=n;i++)
		{
			err+=(x2[i]-x1[i])*(x2[i]-x1[i]);
			x1[i]=x2[i];
			printf("第%d次迭代：x[%d]=%lf ",k,i,x2[i]);
		}
		err=sqrt(err);
		printf("误差为：%lf\n",err);
	}
	return 0;
}
