#include <cmath>
#include <stdio.h>
int fact(int n){
 int res = 1;
 for(int i=1; i<=n; ++i)
 res *= i;
 return res;
}
int C(int n, int k){
 return fact(n)/(fact(k)*fact(n-k));
}
double f1(int r, int k, double* Y){
 double res = 0;
 for(int j=0; j<=r; ++j){
 res += pow(-1, j)*C(r, j)*Y[k+r-j-1];
 }
 return res;
}


double f2(int r, int k, double* Y){
 return f1(r, k-r, Y);
}


double Vpered(int n, double* Y, double q){
 double res = Y[0];
 double a;
 for(int j=1; j<=n; ++j){
    a = f1(j, 0, Y)/fact(j);
        for(int i=0; i<j; ++i)
            a *= q-i;
 res += a;
 }
 return res;
}
double Nazad(int n, double* Y, double q){
 double res = Y[n-1];
 double a;
 for(int j=1; j<=n; ++j){
 a = f2(j, n, Y)/fact(j);
 for(int i=0; i<j; ++i)
 a *= q+i;
 res += a;
 }

 return res;
}
int main()
{
 double X[11] = {0.2680, 0.4290,0.5910, 0.7520, 0.9130, 1.0740,
1.2360, 1.3970, 1.5580, 1.7190, 1.8810};
 double Y[11] = {-0.1950,-0.0480,0.0110, 0.0100, -0.0280, -0.0770,
-0.1130, -0.1090, -0.0410,0.1140, 0.3870};
 double x1 = 0.8110, x2 = 0.3770, x3 = 1.5480;
 printf("f(x1)=%f\n", Vpered(4, Y+1, (x1-X[4])/(X[4]-X[3])));
 printf("f(x2)=%f\n", Vpered(4, Y+1, (x2-X[1])/(X[2]-X[1])));
 printf("f(x3)=%f\n", Nazad(4, Y+1, (x3-X[7])/(X[2]-X[1])));
 return 0;
}

