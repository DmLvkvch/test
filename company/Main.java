package com.company;
import javax.swing.*;
public class Main extends JFrame {
    public static void main(String[] args) {
        Graph g = new Graph();
        TopSort sort = new TopSort(g);
        sort.Alg(g);
        Window w = new Window(g, sort);
        w.setVisible(true);
    }
}

