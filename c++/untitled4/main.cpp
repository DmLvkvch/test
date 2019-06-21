#include <cmath>
#include <stdio.h>
int fact(int n){
 int res = 1;
 for(int i=1; i<=n; ++i)
 res *= i;
 return res;
}
int combination(int n, int k){
 return fact(n)/(fact(k)*fact(n-k));
}
double downward_diff(int r, int k, double* Y){
 double res = 0;
 for(int j=0; j<=r; ++j){
 res += pow(-1, j)*combination(r, j)*Y[k+r-j-1];
 }
 return res;
}
double forward_diff(int r, int k, double* Y){
 return downward_diff(r, k-r, Y);
}
double Newton_forward(int n, double* Y, double q){
 double res = Y[0];
 double sub_res;
 for(int j=1; j<=n; ++j){
 sub_res = downward_diff(j, 0, Y)/fact(j);
 for(int i=0; i<j; ++i)
 sub_res *= q-i;
 res += sub_res;
 }
 return res;
}
double Newton_backward(int n, double* Y, double q){
 double res = Y[n-1];
 double sub_res;
 for(int j=1; j<=n; ++j){
 sub_res = forward_diff(j, n, Y)/fact(j);
 for(int i=0; i<j; ++i)
 sub_res *= q+i;
 res += sub_res;
 }

 return res;
}
int main()
{
 double X[11] = {0.2680,0.4290, 0.5910, 0.7520, 0.9130, 1.0740, 1.2360,
1.3970, 1.5580, 1.7190, 1.8810};
 double Y[11] = {-0.1950, -0.0480, 0.0110,0.0100, -0.0280, -0.0770,
-0.1130, -0.1090, -0.0410,  0.1140, 0.3870};
 double x1 = 0.8110, x2 = 0.3770, x3 = 1.5480;
 printf("f(x1)=%f\n", Newton_backward(4, Y+1, (x1-X[4])/(X[2]-X[1])));
 printf("f(x2)=%f\n", Newton_forward(4, Y+1, (x2-X[1])/(X[2]-X[1])));
 printf("f(x3)=%f\n", Newton_forward(
            4, Y+5, (x3-X[7])/(X[8]-X[7])));
 return 0;
}
