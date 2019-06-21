package com.company;
import java.util.Scanner;
public class Main {

    static class node{
        node next;
        int val;

          public node(){
            next = null;
            val = 0;
        }
        public node(node x, int val){
              next = x;
              this.val = val;
        }
    }

    static class stack{
        node head;
        int size;
        public stack(){
            head = new node();
            size = 0;
        }

        void push(int x){
            node tmp = head;
            if(size == 0){
                head = new node(null, x);
                size++;
            }
            else{
                while(tmp.next!=null)
                    tmp = tmp.next;
                tmp.next = new node(null, x);
                size++;
            }
        }

        void pop(){
            node tmp = head;
            while(tmp.next.next!=null) {
                tmp = tmp.next;
            }
            tmp.next = null;

        }

    }

    public static void main(String[] args) {
        stack s = new stack();
        s.push(5);
        s.push(10);
        s.push(6);
        s.pop();
        s.push(1);
    }
}
