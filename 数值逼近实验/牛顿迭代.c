#include "stdio.h"
#include "math.h"
#define a 3
double f(double x)
{
	double y=x*x-a;
	return y;
}
double df(double x)
{
	double y=2*x;
	return y;
}
int main()
{
	double x0,x1,tol;
	int k,n;
	scanf("%lf %lf %d",&x0,&tol,&n);
	for(k=1;k<=n;k++)
	{
		if(df(x0)==0)
		{
			printf("导数为0，迭代失败");
			break;
		}
		x1=x0-f(x0)/df(x0);
		printf("the root of x[%d]=%.6lf\n",k,x1);
		double c=x1-x0;
		if(fabs(c)<tol)
		{
			
			printf("11111 %lf     %lf",x0,c);
			break;
		}
		if(k>=n)
		{
			printf("迭次次数超过最大限制");
			break;
		}
		x0=x1;
	}
	return 0;
}
