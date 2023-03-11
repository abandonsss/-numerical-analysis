#include"math.h"
#include"stdio.h"
#define n 5

double *vec_plus(double *a, double b[],double alpha, double *c);
double vec_multiply(double *a, double b[]);
double *mat_vec(double A[][n],double b[],double c[]);
main()
{
	double A[n][n]={{10,1, 2,3,4},{1,9,-1,2,-3},{2,-1,7,3,-5},{3,2,3,12,-1},{4,-3,-5,-1,15}};
    double b[n]={12,-27,14,-17,12};
	int i,j;
	double x[n],r[n],w[n],p[n];
	int k=0, K=20;  // the maximum number of iterations
	for(i=0;i<n;i++)
	{
		x[i]=0.0; r[i]=0.0;w[i]=0.0; p[i]=0.0;
	}
    double vec_inner=0.0, eps=1e-15, b_norm2=0.0;
	double alpha=0.0, beta=0.0,rho0=0.0,rho1=0.0;

	mat_vec(A,x,w);  //w=A*x;
	vec_plus(b,w,-1,r);      //r=b-A*x=b-w
	rho1=vec_multiply(r,r);  // rho0=r^T*r
	b_norm2=vec_multiply(b,b); // b^T*b;
	b_norm2=sqrt(b_norm2);

	while(sqrt(rho1>eps*b_norm2)&& k<K)
	{
		k++;
		if(k==1) // p=r
		{
			for(i=0;i<n;i++)
			{
				p[i]=r[i];
			}

		}
		else
		{
			beta=rho1/rho0;
			vec_plus(r,p,beta,p);    //p=r+beta*p ???
		}
		mat_vec(A,p,w);  //w=A*p;
		alpha=rho1/vec_multiply(p,w);  //alpha=rho1/p^T*w;
		vec_plus(x,p,alpha,x); //  x=x+alpha*p;  ??
		vec_plus(r,w,-alpha,r); //  r=r-alpha*w; ??
		rho0=rho1;
		rho1=vec_multiply(r,r);  // rho1=r^T*r;	
		printf("the %d iteration is:\n",k);
		for( i=0;i<n;i++)
		{	
			printf("x[%d]=%.8f\n",i,x[i]);
		}
	}
}


 

double *vec_plus(double *a, double b[],double alpha, double *c)
{
	for(int i=0;i<n;i++)
	{
		c[i]=a[i]+alpha*b[i];
		//printf("c[%d]=%.4f\n",i,c[i]);
	}
	return c;
}
double vec_multiply(double *a, double b[])
{
	double sum=0.0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i]*b[i];
	}
	//printf("%.4f\n",sum);
	return sum;
}
double *mat_vec(double A[][n],double b[],double c[])
{
	for(int i=0;i<n;i++)
	{
		c[i]=0.0;
		for(int j=0;j<n;j++)
		{
			c[i]=c[i]+A[i][j]*b[j];
		}
	}
	return c;
}
