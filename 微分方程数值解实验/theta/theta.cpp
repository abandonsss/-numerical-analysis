#include <iostream>
#include <fstream>
using namespace std;
#define N 1000
#define J 20
#define step 50
double mu = 0.5;
double theta = 0.5;

double u0(double x)
{
	if(x<=0.5&&x>=0)
		return 2.0*x;
	else
		return 2-2*x;
}

void solve_tridiag(int n, double *a, double *b, double *c, double *d, double *x)
{
	int i;
	double *bb= new double[n+1];
	for(i=0;i<=n;i++)
		bb[i]=b[i];
	for(i=1;i<=n;i++)
	{	
		double m;
		m=a[i]/bb[i-1];
		bb[i]=b[i]-m*c[i-1];
		d[i]=d[i]-m*d[i-1];
	}
	x[n]=d[n]/bb[n];
	for(i=n-1;i>=0;i--)
	{
		x[i]=(d[i]-c[i]*x[i+1])/bb[i];
	}
	delete []bb;
}

int main() {
	double a0 = 0.0, b0 = 1.0;
	double dx = (b0-a0)/J;
	double dt = mu * (dx * dx); 
 	double u[N+1][J+1];
	int i,j;
	double a[J+1],b[J+1],c[J+1],d[J+1],un[J+1],x[J+1],t[N+1];
	fstream x_file("x_data.txt", ios::out);
	fstream t_file("t_data.txt", ios::out);
	fstream u_file("u_data.txt", ios::out);
	for(i=0;i<=J;i++)
	{
		x[i]=i*dx;
		u[0][i]=u0(x[i]);
		un[i]=u[0][i];
		x_file << x[i] << endl;
	}
	for(i=0;i<=N;i++)
	{
		t[i]=i*dt;
		t_file << t[i] << endl;
	}
	b[0]=1.0+2*theta*mu;
	a[0]=-1.0*mu*theta;
	c[0]=-1.0*mu*theta;
	b[J]=1.0+2*theta*mu;
	a[J]=-1.0*mu*theta;
	c[J]=-1.0*mu*theta;
	for(i=1;i<J;i++)
	{	
		b[i]=1.0+2*theta*mu;
		a[i]=-1.0*mu*theta;
		c[i]=-1.0*mu*theta;
	}
	int n=0;
	while(n<step)
	{
		u[n+1][0]=0.0; u[n+1][J]=0.0;
		un[0]=0.0; un[J]=0.0;
		for(i=1;i<J;i++)
		{
			d[i]=un[i]+(1-theta)*mu*(un[i+1]-2*un[i]+un[i-1]);
		}
		d[0]=un[0]+(1-theta)*mu*(un[1]-2*un[0]);
		d[J]=un[J]+(1-theta)*mu*(un[J-1]-2*un[J]);
		solve_tridiag(J,a,b,c,d,un);
		for(i=1;i<J;i++)
		{
			u[n+1][i]=un[i];
		}
		n++;
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=J;j++)
		{
			cout << u[i][j] << " ";
			u_file << u[i][j] << " ";
		}
		cout << endl;
		u_file << endl;
	}
	x_file.close();
	t_file.close();
	u_file.close();
	return 0;
}
