package com.company;

import java.util.regex.Pattern;

class stack{
    private
    int s[] = new int[10];
    private
    int top;
    public
    stack(){
        top = -1;
    }

    void push(int x){
        if(top==9)
            return;
        else {
            top++;
            s[top] = x;

        }
    }

    void pop(){
        if(top==0)
            return;
        else{
            s[top] = 0;
            top--;
            return;
        }
    }

    int stop(){
        return s[top];
    }
}

class box{
    protected int a, b, w;
    box(int a, int b, int w){
        this.a = a;
        this.b = b;
        this.w = w;
    }

    public int v() {
        return a * b * w;
    }
}

class box1 extends box{
    int color;
    box1(int a, int b, int w, int color){
        super(a, b, w);
        this.color = color;
    }



}


public class Main {

        public static void main(String[] args) {
            box x = new box(1, 2 ,3);
            box1 y = new box1(2, 2, 2, 5);
            y.v();
            box t;
            t = x;
            t = y;
            System.out.println(y.v()+" "+x.v());
        }

}
