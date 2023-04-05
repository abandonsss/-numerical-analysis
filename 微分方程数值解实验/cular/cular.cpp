#include <iostream>
#include <fstream>
using namespace std;
#define J 50
#define N 50

double u0(double x) {
	if(x<=0.5 && x>=0)
		return 2.0*x;
	else
		return 2-2.0*x;
}


int main() {
	int j,n;
	double a=0.0, b=1.0, dt=0.0013, dx=(b-a)/J, k=dt/(dx*dx);
	double **u;
	u = new double*[N+1];
	u[0] = new double[J+1]; 
	for (j=0;j<=J;j++)
	{
		u[0][j]= u0(dx*j);
	}
	u[0][0]=0;
	u[0][J]=0;
	for(n=0;n<=N-1;n++)
	{
		u[n+1] = new double[J+1];
		u[n+1][0]=0;
		u[n+1][J]=0;
		for(j=1;j<=J-1;j++)
		{
			u[n+1][j]=u[n][j]+k*(u[n][j+1]-2*u[n][j]+u[n][j-1]);
		}
	}
	fstream u_file;
	u_file.open("data.txt", ios::out);
	for(int i=0;i<=N-1;i++)
	{
		for(int j=0;j<=J;j++)
		{
			cout << u[i][j] <<" ";
			u_file << u[i][j] << " ";
		}
		cout << endl;
		u_file << endl;
	}
	u_file.close();
	delete []u;
	return 0;
}
