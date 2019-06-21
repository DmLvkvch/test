#include <iostream>
#include <ctime>
using namespace std;

struct A{
public:
    A(char c, double d, int i){}
private:
    char c;
    double d;
    int i;
};

struct B:A{
public:
    char c;
    double d;
    int i;
};

char & get_c(A & a){
    A* b = &a;
    return (char)(b);

}

int  main(int argc, char *argv[])
{
    A a(1, 2 ,3);
    cout<<get_c(a);

    return 0;
}

