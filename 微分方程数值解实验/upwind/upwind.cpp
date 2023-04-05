#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define N 100
#define J 100

double u0(double x) {
	if(x >= 0.2 && x <= 0.4) 
		return 1.0;
	else 
		return 0.0;
} //初始条件

double func_a(double x,double t) {
	return (1+x*x)/(1+2*x*t+2*x*x+pow(x,4));
}

double solution(double x,double t) {
	return u0(x-t/(1+x*x));                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
} //根据特征线求解精确解

double left_bounnary(double t) { return 0; }
double right_bounnary(double t) { return 0; }
int main() {
	double a=0.0, b=1.0,dt=0.01;
	double dx=(b-a)/J;
	double k=dt/dx;
	double u[N+1][J+1];
	double *x,*t;
	x=new(double[J+1]);
	t=new(double[N+1]);
	int i,j;
	fstream x_file("x_data.txt", ios::out);
	fstream t_file("t_data.txt", ios::out);
	fstream u_file("u_data.txt", ios::out);
	fstream real_file("real_data.txt", ios::out);
	for(i=0;i<=J;i++) 
	{	
		x[i]=i*dx;
		u[0][i]=u0(x[i]);
		x_file << x[i] << " ";
	}
	for(i=0;i<=N;i++)
	{
		t[i]=i*dt;
		t_file << t[i] << " ";
	}	
	double mu;
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=J;j++)
		{
			mu=func_a(x[j],t[i])*k;
			if(j==0) {
				if(mu>=0) {
					u[i+1][j]=left_bounnary(t[i+1]);
				} else {
					u[i+1][j]=(1+mu)*u[i][j]-mu*u[i][j+1];
				}
			} else if (j==J) {
				if(mu < 0) {
					u[i+1][j]=right_bounnary(t[i+1]);
				} else {
				u[i+1][j]=(1-mu)*u[i][j]+mu*u[i][j-1];
				} 
			}
			else{
				if(mu>=0) {
					u[i+1][j]=(1-mu)*u[i][j]+mu*u[i][j-1];
				} else {
					u[i+1][j]=(1+mu)*u[i][j]-mu*u[i][j+1];
				}
			}
		}
	}
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=J;j++)
		{
			real_file << solution(x[j],t[i]) << " ";
			cout << u[i][j] << " ";
			u_file << u[i][j] << " ";
		}
		cout << endl;
		u_file << endl;
		real_file << endl;
	}
	x_file.close();
	t_file.close();
	u_file.close();
	real_file.close();

	delete []t;
	delete []x;
	return 0;
}
