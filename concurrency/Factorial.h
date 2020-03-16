#ifndef FACTORIAL_H
#define FACTORIAL_H
class Factorial{
public:
    static long factorial(long n){
        long res = 1;
        for(long i = 2;i<=n;i++){
            res*=i;
        }
        return res;
    }
};

#endif // FACTORIAL_H
