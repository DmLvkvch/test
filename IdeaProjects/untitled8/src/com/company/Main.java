package com.company;

public class Main {
static class node{
    int x;
    node right;
    node left;
    node(int x){
        this.x = x;
        right = left = null;
    }
}

static class tree{
    node root;
    tree(){
        root = null;
    }
    tree(int x){
        root = new node(x);
    }

    void add(int x){
        if(root==null){
            root = new node(x);
        }
        else {
            node tmp = root;
            while (tmp != null) {
                if (x > tmp.x) {
                    if (tmp.right == null) {
                        tmp.right = new node(x);
                        return;
                    }
                    tmp = tmp.right;
                } else {
                    if (tmp.left == null) {
                        tmp.left = new node(x);
                        return;
                    }
                    tmp = tmp.left;
                }
            }
        }
    }





    void remove(int x){

    }
}
    public static void main(String[] args) {
	tree t = new tree();
	t.add(5);
	t.add(10);
	t.add(4);
    t.add(9);
    t.add(11);
    }
}
