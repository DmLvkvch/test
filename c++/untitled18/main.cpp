#include <iostream>
#include <string>
using namespace std;

class People{
    int age;
    string name;

public:
    
    People(int a, string t = "52434"){
        age = a;
        name = t;
    }
    People(){}
};

class A{
private:
    virtual void print(){
        cout<<"class A"<<endl;
    }
};

class B: public A{
public:
    void print() override{
        //A::print();
        cout<<"class B"<<endl;
    }
};

class aa{
    size_t size;
    int* a;
public:
    explicit aa(size_t sz, int t){
        size = sz;
        int* a = new int [5];
        for(int i = 0;i<5;i++){
            a[i] = i;
        }
        this->a = a;
    }
    explicit aa(int sz):aa(sz, -1){}

    void print(){
        for(int i = 0;i<size;i++)
            cout<<a[i]<<" ";
    }

};

struct Point{
    double a;
}zero;

class Base1{
public:
    Base1(){
        cout<<"Base1"<<endl;
    }
};

class Base2{
public:
    Base2(){
        cout<<"Base2"<<endl;
    }
};

class Deriv:public Base1, virtual public Base2{
public:
    Deriv():Base1(), Base2 (){
        cout<<"Deriv"<<endl;
    }
};

struct A1{
    char c1;
    double d1;
    char c2;
    double d2;
    char c3;
    double d3;
    char c4;
    double d4;
};

struct B1 : public A1{
    char c1;
    char c2;
    char c3;
    char c4;
        double d1;
            double d2;
                double d3;
    double d4;
};

int t = 2;

int &foo(){
    return t;
}

int main()
{
    People p;
    People y(p);
    int a = 10, b = 20;
    int arr[10];
    int & link1 = a;
   // int & link2 = a+b;
    int &link3 = *(arr + a / 2);
    //int &link4 = *(arr + a / 2) + 1;
    int &link5 = (a + b > 10) ? a : b;
    cout<<sizeof (A1)<<" "<<sizeof (B1);
    foo() = 6;
    cout<<t;
    return 0;
}
