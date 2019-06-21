package com.company;

import javafx.util.Pair;

import javax.swing.text.Segment;
import java.util.Vector;

public class Main {

    public static class T{
        public int c;
        public int w;
        T(int x, int y){
            c = x;
            w = y;
        }
    }

    public static int func(Vector<T> a, int w){

        return ans;
    }

    public static void main(String[] args) {
        int n = 3;
        int w = 50;
        Vector<T> a = new Vector<>(n);
        a.add(new T(60, 20));
        a.add(new T(100, 50));
        a.add(new T(120, 30));
        System.out.println(func(a, w));
    }
}
