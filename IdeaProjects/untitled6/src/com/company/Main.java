package com.company;
import java.util.Vector;
public class Main {


    static class queue{
        private int[] m;
        private int size;
        private int n;
        queue(int s){
            size = s;
            m = new int[size];
            n = 0;
        }

        void resize(){
            int[] buf = new int[size*2];
            System.arraycopy(m, 0, buf, 0, size);
            m = buf;
            buf = null;
            size*=2;
        }

        void push_back(int x){
            if(n==size)
                resize();
            m[n++] = x;
        }

        void push_front(int x){
            if(n==size)
                resize();
            for(int i = n-1;i>=0;i--){
                m[i+1] = m[i];
            }
            m[0] = x;
            n++;
        }

        void pop_back(){
            if(!empty())
                 m[--n] = 0;
        }

        boolean empty(){
            return n==0;
        }

        void pop_front(){
            if(!empty()) {
                for (int i = 1; i < n; i++) {
                    m[i - 1] = m[i];
                }
                m[--n] = 0;
            }

        }

        int top(){
            if(!empty())
                return m[0];
            return -1;
        }

        int size(){
            return n;
        }

    }

    public static void main(String[] args) {
        queue q = new queue(5);
        for(int i = 0;i<5;i++) {
            q.push_back(i);
        }
        for(int i = 0;i<q.size();i++) {
            System.out.println(q.top());
            q.pop_front();
        }
        System.out.println(q.size());
    }
}
