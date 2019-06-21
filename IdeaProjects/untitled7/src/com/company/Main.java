package com.company;

public class Main {

    static class node {
        int val;
        node next;
        node prev;

        node(int val, node next, node prev) {
            this.val = val;
            this.next = next;
            this.prev = prev;
        }
    }

    static class list {
        node tail;
        node head;

        list() {
            tail = head = null;
        }

        boolean empty() {
            if (tail == null && head == null)
                return true;
            else return false;
        }

        list(int x) {
            tail = head = new node(x, null, null);
        }

        void add_front(int x) {
            if (empty()) {
                head = new node(x, null, null);
                tail = head;
            } else {
                head.prev = new node(x, head, null);
                head = head.prev;
            }
        }

        void add_back(int x){
            if(empty()){
                tail = new node(x, null, null);
                head = tail;
            }
            else {
                tail.next = new node(x, null, tail);
                tail = tail.next;
            }
        }
    }
        public static void main(String[] args) {
            list l = new list();
            l.add_front(5);
            l.add_back(10);
        }
}
