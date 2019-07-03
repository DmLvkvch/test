package com.company;
public class Main {

    public static void main(String[] args) {
	    Graph g = new Graph();
        g.addE(5,5);
        g.addE(0, 1);
        g.addE(2 ,1);
        g.addE(3, 1);
        g.addE(1, 4);
        g.addE(5, 4);
        g.addE(3, 5);
        TopSort t = new TopSort(g);
        t.Alg();
        Window w = new Window();
        w.setVisible(true);
        w.setSize(200, 200);


    }
}
