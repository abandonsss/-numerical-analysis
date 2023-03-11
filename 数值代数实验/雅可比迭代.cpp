#include <stdio.h>
#include <math.h>
int main() {
	int n,i,j,k;
	double a[100][100];
	double y[100];
	double x1[100];
	double x2[100];
	double eps=1e-5;
	double err=10000.0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		x1[i]=0;
		for(j=1;j<=n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		scanf("%lf",&y[i]);
	int m=0;
	while(m<k && err>eps)
	{
		err=0.0;
		for(i=1;i<=n;i++)
		{ 
			double ret=y[i];
			for(j=1;j<=n;j++)
			{
				if(i!=j)
					ret-=a[i][j]*x1[j];
			}
			x2[i]=ret/a[i][i];
		}
		m++;
		for(i=1;i<=n;i++)
		{
			if(err<fabs(x1[i]-x2[i]))
				err=fabs(x1[i]-x2[i]);
			x1[i]=x2[i];
		}
		for(i=1;i<=n;i++)
			printf("µÚ%d´Îµü´ú:x[%d]=%lf\n",m,i,x2[i]);
		printf("\n");
	}
	return 0;
}
